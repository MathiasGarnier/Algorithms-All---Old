#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// #include <vulkan/vulkan.h>       -> pas besoin de l'inclure, figure ligne 110 de GLFW/glfw3.h

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <optional>

#include <vector>
#include <map>
#include <set>

class HelloTriangleApplication {

    // Chaque objet Vulkan doit être "free" (désalloué) une fois que l'on ne s'en sert plus.
    // 
    // "After all, Vulkan's niche is to be explicit about every operation to avoid mistakes, 
    // so it's good to be explicit about the lifetime of objects to learn how the API works."
    // 
    // "RAII is the recommended model for larger Vulkan programs, but for learning purposes 
    // it's always good to know what's going on behind the scenes."
    // 
    // "It has been briefly touched upon before that almost every operation in Vulkan, 
    // anything from drawing to uploading textures, requires commands to be submitted to a queue." 
    // 
    // "Since Vulkan is a platform agnostic API, it can not interface directly with the window 
    // system on its own. To establish the connection between Vulkan and the window system to 
    // present results to the screen, we need to use the WSI (Window System Integration) extensions."
    // 
    // "Vulkan does not have the concept of a "default framebuffer", hence it requires an 
    // infrastructure that will own the buffers we will render to before we visualize them on 
    // the screen. The swap chain is essentially a queue of images that are waiting to be presented 
    // to the screen. (...) The general purpose of the swap chain is to synchronize the presentation 
    // of images with the refresh rate of the screen."



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
        VkSurfaceKHR surface; // Ca commence à commencer ! 

        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // Carte graphique que l'on va utiliser.
        VkDevice logicalDevice;
        
        VkQueue graphicsqueue;
        VkQueue presentqueue;


        const uint32_t WIDTH = 1260;
        const uint32_t HEIGHT = 720;

        // Va falloir travailler la logique de "queue".
        // Pas évidente du tout.
        // NB "Device queues are implictly cleaned when the service is destroyed."
        struct QueueFamilyIndices {

            std::optional<uint32_t> graphicsfamily;
            std::optional<uint32_t> presentfamily; // toutes les fonctionnalités ne sont pas forcément présentes
                                                   // sur la machine...

            bool isComplete() {
                return graphicsfamily.has_value() && presentfamily.has_value();
            }
        };

        // Il va falloir vérifier plein de choses parmi lesquelles :
        //      (*) Basic surface capabilities (min/max number of images in swap chain, 
        // min/max width and height of images)
        //      (*) Surface formats(pixel format, color space)
        //      (*) Available presentation modes
        const std::vector<const char*> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };

        struct SwapChainSupportDetails {

            VkSurfaceCapabilitiesKHR capabilities;
            std::vector<VkSurfaceFormatKHR> formats;
            std::vector<VkPresentModeKHR> presentModes;
        };

        void initWindow() {

            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // ne pas créer un contexte OpenGL par défaut
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);   // fenêtre non resizeable

            window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle", nullptr, nullptr);
        }

        void initVulkan() {

            createInstance();
            createSurface();
            pickPhysicalDevice();
            createLogicalDevice();
        }

        void mainLoop() {

            while (!glfwWindowShouldClose(window)) {

                glfwPollEvents();
            }
        }

        void cleanup() {

            // D'abord détruire le device et la surface... et ensuite l'instance !
            vkDestroyDevice(logicalDevice, nullptr);
            vkDestroySurfaceKHR(instance, surface, nullptr);
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

            bool isExtensionSupported = checkDeviceExtensionSupport(device);

            bool swapChainAdequate = false;

            if (isExtensionSupported) {
                SwapChainSupportDetails swapChainSupport = querySwapChainSupport(device);
                swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
            }

            return indices.isComplete() && isExtensionSupported && swapChainAdequate;
        }

        bool checkDeviceExtensionSupport(VkPhysicalDevice device) {

            uint32_t extensionCount;
            vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

            std::vector<VkExtensionProperties> availableExtensions(extensionCount);
            vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

            std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

            for (const auto& extension : availableExtensions) {
                requiredExtensions.erase(extension.extensionName);
                
                // std::cout << extension.extensionName << " ";
                // RESULTAT (exécuté au tout début) : 
                // VK_KHR_16bit_storage VK_KHR_8bit_storage VK_KHR_bind_memory2 VK_KHR_buffer_device_address 
                // VK_KHR_copy_commands2 VK_KHR_create_renderpass2 VK_KHR_dedicated_allocation 
                // VK_KHR_depth_stencil_resolve VK_KHR_descriptor_update_template VK_KHR_device_group 
                // VK_KHR_draw_indirect_count VK_KHR_driver_properties VK_KHR_dynamic_rendering 
                // VK_KHR_external_fence VK_KHR_external_fence_win32 VK_KHR_external_memory 
                // VK_KHR_external_memory_win32 VK_KHR_external_semaphore VK_KHR_external_semaphore_win32 
                // VK_KHR_format_feature_flags2 VK_KHR_get_memory_requirements2 VK_KHR_imageless_framebuffer 
                // VK_KHR_image_format_list VK_KHR_maintenance1 VK_KHR_maintenance2 VK_KHR_maintenance3 
                // VK_KHR_multiview VK_KHR_pipeline_executable_properties VK_KHR_relaxed_block_layout 
                // VK_KHR_sampler_mirror_clamp_to_edge VK_KHR_sampler_ycbcr_conversion 
                // VK_KHR_separate_depth_stencil_layouts VK_KHR_shader_atomic_int64 VK_KHR_shader_clock 
                // VK_KHR_shader_draw_parameters VK_KHR_shader_float16_int8 VK_KHR_shader_float_controls 
                // VK_KHR_shader_integer_dot_product VK_KHR_shader_non_semantic_info 
                // VK_KHR_shader_subgroup_extended_types VK_KHR_shader_subgroup_uniform_control_flow 
                // VK_KHR_shader_terminate_invocation VK_KHR_spirv_1_4 VK_KHR_storage_buffer_storage_class 
                // VK_KHR_swapchain VK_KHR_swapchain_mutable_format VK_KHR_synchronization2 
                // VK_KHR_timeline_semaphore VK_KHR_uniform_buffer_standard_layout VK_KHR_variable_pointers 
                // VK_KHR_vulkan_memory_model VK_KHR_win32_keyed_mutex VK_KHR_zero_initialize_workgroup_memory 
                // VK_EXT_4444_formats VK_EXT_calibrated_timestamps VK_EXT_color_write_enable 
                // VK_EXT_conditional_rendering VK_EXT_conservative_rasterization VK_EXT_custom_border_color 
                // VK_EXT_depth_clip_enable VK_EXT_depth_range_unrestricted VK_EXT_descriptor_indexing 
                // VK_EXT_extended_dynamic_state VK_EXT_extended_dynamic_state2 VK_EXT_external_memory_host 
                // VK_EXT_full_screen_exclusive VK_EXT_global_priority VK_EXT_hdr_metadata VK_EXT_host_query_reset 
                // VK_EXT_image_robustness VK_EXT_image_view_min_lod VK_EXT_index_type_uint8 
                // VK_EXT_inline_uniform_block VK_EXT_line_rasterization VK_EXT_load_store_op_none 
                // VK_EXT_memory_budget VK_EXT_memory_priority VK_EXT_pageable_device_local_memory 
                // VK_EXT_pipeline_creation_cache_control VK_EXT_pipeline_creation_feedback 
                // VK_EXT_primitive_topology_list_restart VK_EXT_private_data VK_EXT_queue_family_foreign 
                // VK_EXT_robustness2 VK_EXT_sampler_filter_minmax VK_EXT_sample_locations 
                // VK_EXT_scalar_block_layout VK_EXT_separate_stencil_usage VK_EXT_shader_atomic_float 
                // VK_EXT_shader_demote_to_helper_invocation VK_EXT_shader_image_atomic_int64 
                // VK_EXT_shader_stencil_export VK_EXT_shader_subgroup_ballot VK_EXT_shader_subgroup_vote 
                // VK_EXT_shader_viewport_index_layer VK_EXT_subgroup_size_control VK_EXT_texel_buffer_alignment 
                // VK_EXT_tooling_info VK_EXT_transform_feedback VK_EXT_vertex_attribute_divisor 
                // VK_EXT_ycbcr_image_arrays VK_AMD_buffer_marker VK_AMD_calibrated_timestamps 
                // VK_AMD_device_coherent_memory VK_AMD_display_native_hdr VK_AMD_draw_indirect_count 
                // VK_AMD_gcn_shader VK_AMD_gpa_interface VK_AMD_gpu_shader_half_float VK_AMD_gpu_shader_int16 
                // VK_AMD_memory_overallocation_behavior VK_AMD_mixed_attachment_samples 
                // VK_AMD_negative_viewport_height VK_AMD_pipeline_compiler_control VK_AMD_rasterization_order 
                // VK_AMD_shader_ballot VK_AMD_shader_core_properties VK_AMD_shader_core_properties2 
                // VK_AMD_shader_explicit_vertex_parameter VK_AMD_shader_fragment_mask 
                // VK_AMD_shader_image_load_store_lod VK_AMD_shader_info VK_AMD_shader_trinary_minmax 
                // VK_AMD_texture_gather_bias_lod VK_AMD_wave_limits VK_GOOGLE_decorate_string 
                // VK_GOOGLE_hlsl_functionality1 VK_GOOGLE_user_type
            }

            return requiredExtensions.empty();
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

                VkBool32 presentSupport = false;
                // --> est-ce supporté ?
                vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);

                if (presentSupport) {
                    indices.presentfamily = i;
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

            std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
            std::set<uint32_t> uniqueQueueFamilies = { indices.graphicsfamily.value(), indices.presentfamily.value() };

            float queuePriority = 1.0f;

            for (uint32_t queueFamily : uniqueQueueFamilies) {

                VkDeviceQueueCreateInfo queueCreateInfo{}; // en créé une pour chaque élément de uniqueQueueFamilies

                queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
                queueCreateInfo.queueFamilyIndex = queueFamily;
                queueCreateInfo.queueCount = 1;
                queueCreateInfo.pQueuePriorities = &queuePriority;
                queueCreateInfos.push_back(queueCreateInfo);
            }


            VkDeviceQueueCreateInfo queuecreateInfo{};

            queuecreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queuecreateInfo.queueFamilyIndex = indices.graphicsfamily.value();
            queuecreateInfo.queueCount = 1;
            queuecreateInfo.pQueuePriorities = &queuePriority;

            // Définir l'ensemble des fonctionnalités que l'on souhaite pouvoir utiliser :
            // (pas besoin de grand chose pour l'instant, mis à part geometryShader...)
            VkPhysicalDeviceFeatures deviceFeatures{};

            VkDeviceCreateInfo createinfo{};

            createinfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
            createinfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
            createinfo.pQueueCreateInfos = queueCreateInfos.data();
            createinfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
            createinfo.ppEnabledExtensionNames = deviceExtensions.data();
            createinfo.pEnabledFeatures = &deviceFeatures; // fonctionnaltiés

            // Il y a toute une partie sur les validation layers que j'ai skippé...
            // (y revenir plus tard...)

            if (vkCreateDevice(physicalDevice, &createinfo, nullptr, &logicalDevice) != VK_SUCCESS) {
                throw std::runtime_error("Impossible de créer un logical device.");
            }

            vkGetDeviceQueue(logicalDevice, indices.graphicsfamily.value(), 0, &graphicsqueue);
        }

        void createSurface() {

            if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {

                throw std::runtime_error("Impossible de créer une surface");
            }
        }

        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device) {

            SwapChainSupportDetails details;

            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &details.capabilities);

            uint32_t formatCount;
            vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);

            if (formatCount != 0) {
                details.formats.resize(formatCount);
                vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, details.formats.data());
            }

            uint32_t presentModeCount;
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, nullptr);

            if (presentModeCount != 0) {
                details.presentModes.resize(presentModeCount);
                vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, details.presentModes.data());
            }

            return details;
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
