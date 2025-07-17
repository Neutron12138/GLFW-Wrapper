#pragma once

#include "context.hpp"

namespace glfw_wrapper
{
    Context &Context::get_instance()
    {
        static Context instance;
        return instance;
    }

    Context::Context()
    {
        int error = glfwInit();
        if (error != GLFW_TRUE)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to initialize GLFW");
    }

    Context::~Context() { glfwTerminate(); }

    void Context::post_empty_event() const { glfwPostEmptyEvent(); }
    void Context::poll_events() const { glfwPollEvents(); }
    void Context::wait_events() const { glfwWaitEvents(); }
    void Context::wait_events_timeout(double timeout) const { glfwWaitEventsTimeout(timeout); }

    double Context::get_time() const { return glfwGetTime(); }
    base::UInt64 Context::get_timer_value() const { return glfwGetTimerValue(); }
    base::UInt64 Context::get_timer_frequency() const { return glfwGetTimerFrequency(); }

    void Context::set_clipboard_string(const std::string &string) const { glfwSetClipboardString(nullptr, string.data()); }
    std::string Context::get_clipboard_string() const
    {
        const char *string = glfwGetClipboardString(nullptr);
        if (string)
            return string;
        else
            return {};
    }

    bool Context::is_vulkan_supported() const { return glfwVulkanSupported(); }
    std::vector<std::string> Context::get_required_instance_extensions() const
    {
        base::UInt32 count;
        const char **extensions = glfwGetRequiredInstanceExtensions(&count);
        if (!extensions)
            return {};

        return std::move(std::vector<std::string>(extensions, extensions + count));
    }

#ifdef GLFW_WRAPPER_USE_VULKAN
    GLFWvkproc Context::get_instance_proc_address(const std::string &name) const
    {
        return glfwGetInstanceProcAddress(nullptr, name.data());
    }

    GLFWvkproc Context::get_instance_proc_address(VkInstance instance, const std::string &name) const
    {
        return glfwGetInstanceProcAddress(instance, name.data());
    }

    bool Context::is_physical_device_presentation_supported(
        VkInstance instance, VkPhysicalDevice device, base::UInt32 queuefamily) const
    {
        return glfwGetPhysicalDevicePresentationSupport(instance, device, queuefamily);
    }

    VkResult Context::create_window_surface(
        VkInstance instance, const Window &window,
        const VkAllocationCallbacks *allocator, VkSurfaceKHR *surface) const
    {
        return glfwCreateWindowSurface(instance, window.get_window(), allocator, surface);
    }
#endif

} // namespace glfw_wrapper
