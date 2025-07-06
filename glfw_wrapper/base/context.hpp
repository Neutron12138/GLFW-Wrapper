#pragma once

#include <iostream>
#include <base/core/type.hpp>
#include <base/core/noncopyable_object.hpp>
#include <base/core/exception.hpp>
#include "glfw.hpp"
#include "../window/window.hpp"

namespace glfw_wrapper
{
    /// @brief GLFW上下文
    class Context : public base::NoncopyableObject
    {
    public:
        static Context &get_instance()
        {
            static Context instance;
            return instance;
        }

    private:
        inline Context()
        {
            int error = glfwInit();
            if (error != GLFW_TRUE)
                throw BASE_MAKE_RUNTIME_ERROR("Failed to initialize GLFW");
        }

    public:
        inline ~Context() { glfwTerminate(); }

    public:
        inline void post_empty_event() const { glfwPostEmptyEvent(); }
        inline void poll_events() const { glfwPollEvents(); }
        inline void wait_events() const { glfwWaitEvents(); }
        inline void wait_events_timeout(double timeout) const { glfwWaitEventsTimeout(timeout); }

        inline double get_time() const { return glfwGetTime(); }
        inline base::UInt64 get_timer_value() const { return glfwGetTimerValue(); }
        inline base::UInt64 get_timer_frequency() const { return glfwGetTimerFrequency(); }

        inline void set_clipboard_string(const std::string &string) const { glfwSetClipboardString(nullptr, string.data()); }
        std::string get_clipboard_string() const
        {
            const char *string = glfwGetClipboardString(nullptr);
            if (string)
                return string;
            else
                return {};
        }

    public:
        inline bool is_vulkan_supported() const { return glfwVulkanSupported(); }
        std::vector<std::string> get_required_instance_extensions() const
        {
            base::UInt32 count;
            const char **extensions = glfwGetRequiredInstanceExtensions(&count);
            if (!extensions)
                return {};

            return std::move(std::vector<std::string>(extensions, extensions + count));
        }

#ifdef GLFW_WRAPPER_USE_VULKAN
        inline GLFWvkproc get_instance_proc_address(const std::string &name) const
        {
            return glfwGetInstanceProcAddress(nullptr, name.data());
        }

        inline GLFWvkproc get_instance_proc_address(VkInstance instance, const std::string &name) const
        {
            return glfwGetInstanceProcAddress(instance, name.data());
        }

        inline bool is_physical_device_presentation_supported(
            VkInstance instance, VkPhysicalDevice device, base::UInt32 queuefamily) const
        {
            return glfwGetPhysicalDevicePresentationSupport(instance, device, queuefamily);
        }

        inline VkResult create_window_surface(
            VkInstance instance, const Window &window,
            const VkAllocationCallbacks *allocator, VkSurfaceKHR *surface) const
        {
            return glfwCreateWindowSurface(instance, window.get_window(), allocator, surface);
        }
#endif
    };

} // namespace glfw_wrapper
