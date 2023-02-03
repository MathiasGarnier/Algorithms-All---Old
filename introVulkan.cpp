#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// #include <vulkan/vulkan.h>       -> pas besoin de l'inclure, figure ligne 110 de GLFW/glfw3.h

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include <vector>

class HelloTriangleApplication {

    // Chaque objet Vulkan doit être "free" (désalloué) une fois que l'on ne s'en sert plus.
    // 
    // "After all, Vulkan's niche is to be explicit about every operation to avoid mistakes, 
    // so it's good to be explicit about the lifetime of objects to learn how the API works."
    // "RAII is the recommended model for larger Vulkan programs, but for learning purposes 
    // it's always good to know what's going on behind the scenes."

    // "Because Vulkan requires you to be very explicit about everything you're doing, 
    // it's easy to make many small mistakes like using a new GPU feature and forgetting 
    // to request it at logical device creation time."
    //      ==> les "validation layers" permettent de vérifier que le comportement du
    //          programme n'est pas (trop) indésiré.
    // Revenir sur cette partie plus tard. Je regarde juste les idées pour l'instant, on verra
    // plus tard pour une implémentation pratique.
    //  VK_ERROR_LAYER_NOT_PRESENT  --> PLUS TARD
    // Revenir sur la section "Message callback" (et suivantes) plus tard (en temps voulu)

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

        const uint32_t WIDTH = 1260;
        const uint32_t HEIGHT = 720;

        void initWindow() {

            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // ne pas créer un contexte OpenGL par défaut
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);   // fenêtre non resizeable

            window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle", nullptr, nullptr);
        }

        void initVulkan() {

            createInstance();
            pickPhysicalDevice();
        }

        void mainLoop() {

            while (!glfwWindowShouldClose(window)) {

                glfwPollEvents();
            }
        }

        void cleanup() {

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

            VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // Carte graphique que l'on va utiliser.

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
        }

        bool isDeviceSuitable(VkPhysicalDevice device) {

            // On vérifie sur la carte graphique est capable de faire ce qu'on
            // lui demande.

            return true;
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
