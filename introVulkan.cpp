#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// #include <vulkan/vulkan.h>       -> pas besoin de l'inclure, figure ligne 110 de GLFW/glfw3.h

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <optional>

#include <vector>
#include <map>

class HelloTriangleApplication {

    // Chaque objet Vulkan doit être "free" (désalloué) une fois que l'on ne s'en sert plus.
    // 
    // "After all, Vulkan's niche is to be explicit about every operation to avoid mistakes, 
    // so it's good to be explicit about the lifetime of objects to learn how the API works."
    // "RAII is the recommended model for larger Vulkan programs, but for learning purposes 
    // it's always good to know what's going on behind the scenes."
    // "It has been briefly touched upon before that almost every operation in Vulkan, 
    // anything from drawing to uploading textures, requires commands to be submitted to a queue." 
    
    // "Because Vulkan requires you to be very explicit about everything you're doing, 
    // it's easy to make many small mistakes like using a new GPU feature and forgetting 
    // to request it at logical device creation time."
    //      ==> les "validation layers" permettent de vérifier que le comportement du
    //          programme n'est pas (trop) indésiré.
    // Revenir sur cette partie plus tard. Je regarde juste les idées pour l'instant, on verra
    // plus tard pour une implémentation pratique.
    //  VK_ERROR_LAYER_NOT_PRESENT  --> PLUS TARD
    // Revenir sur la section "Message callback" (et suivantes) plus tard (en temps voulu)

    // PhysicalDevice puis LogicalDevice (pour parler (interface ?) au PhysicalDevice ?) 

    public:
        
        void run() {

            initWindow(); // GLFW work
            initVulkan(); // Préparation, initiation du programme
            mainLoop();   // Comportement du programme (rafraîchissement image)
            cleanup();    // Désallocation
    }

    private:

        GLFWwindow* window;
        VkInstance instance;

        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // Carte graphique que l'on va utiliser.
        VkDevice logicalDevice;
        VkQueue graphicsqueue;

        const uint32_t WIDTH = 1260;
        const uint32_t HEIGHT = 720;

        // Va falloir travailler la logique de "queue".
        // Pas évidente du tout.
        // NB "Device queues are implictly cleaned when the service is destroyed."
        struct QueueFamilyIndices {

            std::optional<uint32_t> graphicsfamily;

            bool isComplete() {
                return graphicsfamily.has_value();
            }
        };


        void initWindow() {

            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // ne pas créer un contexte OpenGL par défaut
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);   // fenêtre non resizeable

            window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle", nullptr, nullptr);
        }

        void initVulkan() {

            createInstance();
            pickPhysicalDevice();
            createLogicalDevice();
        }

        void mainLoop() {

            while (!glfwWindowShouldClose(window)) {

                glfwPollEvents();
            }
        }

        void cleanup() {

            // D'abord détruire le device... et ensuite l'instance !
            vkDestroyDevice(logicalDevice, nullptr);
            vkDestroyInstance(instance, nullptr);

            glfwDestroyWindow(window);
            
            glfwTerminate();
        }

        void createInstance() {

            VkApplicationInfo appinfo{};

            appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // = 0 ?
            appinfo.pApplicationName = "Triangle";
            appinfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appinfo.pEngineName = "No engine";
            appinfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appinfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createinfo{};

            createinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createinfo.pApplicationInfo = &appinfo;

            // Compter le nombre d'extensions utilisées par Vulkan (étant "platform agnostic" il a besoin
            // d'extensions pour pouvoir fonctionner sur chaque architecture)
            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;
            
            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
            
            createinfo.enabledExtensionCount = glfwExtensionCount;
            createinfo.ppEnabledExtensionNames = glfwExtensions;

            VkResult result = vkCreateInstance(&createinfo, nullptr, &instance);

            // Vérifier que l'instance ait bien été créée :
            if (vkCreateInstance(&createinfo, nullptr, &instance) != VK_SUCCESS) {

                throw std::runtime_error("L'instance n'a pas pu être créée.");
            }

            // VK_ERROR_INCOMPATIBLE_DRIVER     --> M'EN FOUT POUR L'INSTANT
            // VK_ERROR_EXTENSION_NOT_PRESENT   --> IDEM
        }

        void pickPhysicalDevice() {

            uint32_t deviceCount = 0;
            vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

            if (deviceCount == 0) {

                throw std::runtime_error("Impossibilité de trouver un GPU supportant Vulkan.");
            }

            std::vector<VkPhysicalDevice> devices(deviceCount);
            vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

            for (const auto& device : devices) {

                if (isDeviceSuitable(device)) {
                    physicalDevice = device;
                    break;                  // Si j'ai bien compris, on ne veut qu'un seul GPU.
                }
            }

            if (physicalDevice == VK_NULL_HANDLE) {
                
                throw std::runtime_error("Impossible de trouver un GPU adéquat.");
            }

            // Use an ordered map to automatically sort candidates by increasing score
            // std::multimap<int, VkPhysicalDevice> candidates;
            //
            //for (const auto& device : devices) {
            //    int score = rateDeviceSuitability(device);        // Écrire une fonction pour donner une note !
            //    candidates.insert(std::make_pair(score, device));
            //}
            //
            //// Check if the best candidate is suitable at all
            //if (candidates.rbegin()->first > 0) {
            //    physicalDevice = candidates.rbegin()->second;
            //}
            //else {
            //    throw std::runtime_error("failed to find a suitable GPU!");
            //}

        }


        bool isDeviceSuitable(VkPhysicalDevice device) {

            // On vérifie sur le GPU est capable de faire ce qu'on lui demande.
            //
            //VkPhysicalDeviceProperties deviceproperties; // Vérifier propriétés
            //VkPhysicalDeviceFeatures devicefeatures;
            //
            //vkGetPhysicalDeviceProperties(device, &deviceproperties);
            //vkGetPhysicalDeviceFeatures(device, &devicefeatures); // regarder dans vulkan_core.h pour tout un
            //                                                      // tas d'autres propriétés à regarder
            //
            //// VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU :
            ////          The device is typically a separate processor connected to the host via an interlink.
            //// VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU :     --> celui que j'ai
            ////          The device is typically one embedded in or tightly coupled with the host.
            //
            //return deviceproperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU &&
            //    devicefeatures.geometryShader;
            
            //return true;

            QueueFamilyIndices indices = findQueueFamilies(device); // vérifier que le device est bien capable de faire
                                                                    // des "opérations graphiques" (VK_QUEUE_GRAPHICS_BIT)

            return indices.isComplete();
            }

        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
            // Logic to find queue family indices to populate struct with.
            QueueFamilyIndices indices;

            uint32_t queueFamilyCount = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

            std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

            int i = 0;
            for (const auto& queueFamily : queueFamilies) {
                if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                    // va falloir comprendre l'arithmétique binaire (le "&" ok)
                    //VK_QUEUE_GRAPHICS_BIT -> 0x00000100 : specifies that queues in this queue family 
                    // support graphics operations.

                    indices.graphicsfamily = i;
                }

                if (indices.isComplete()) { // S'il a déjà une valeur, pas besoin d'aller plus loin. Et on passe au suivant...
                    break;
                }
                i++;
            }
            return indices;
        }

        void createLogicalDevice() {

            QueueFamilyIndices indices = findQueueFamilies(physicalDevice); // WOOOOW

            VkDeviceQueueCreateInfo queuecreateInfo{};
            float queuePriority = 1.0f;

            queuecreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queuecreateInfo.queueFamilyIndex = indices.graphicsfamily.value();
            queuecreateInfo.queueCount = 1;
            queuecreateInfo.pQueuePriorities = &queuePriority;

            // Définir l'ensemble des fonctionnalités que l'on souhaite pouvoir utiliser :
            // (pas besoin de grand chose pour l'instant, mis à part geometryShader...)
            VkPhysicalDeviceFeatures deviceFeatures{};

            VkDeviceCreateInfo createinfo{};

            createinfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
            createinfo.pQueueCreateInfos = &queuecreateInfo;
            createinfo.queueCreateInfoCount = 1;
            createinfo.pEnabledFeatures = &deviceFeatures; // fonctionnaltiés

            // Il y a toute une partie sur les validation layers que j'ai skippé...
            // (y revenir plus tard...)

            if (vkCreateDevice(physicalDevice, &createinfo, nullptr, &logicalDevice) != VK_SUCCESS) {
                throw std::runtime_error("Impossible de créer un logical device.");
            }

            vkGetDeviceQueue(logicalDevice, indices.graphicsfamily.value(), 0, &graphicsqueue);
        }

};


int main() {

    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
