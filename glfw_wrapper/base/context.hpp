#pragma once

#include <iostream>
#include <base/core/type.hpp>
#include <base/core/exception.hpp>
#include <base/core/noncopyable_object.hpp>
#include "glfw.hpp"
#include "../window/window.hpp"

namespace glfw_wrapper
{
    /// @brief GLFW上下文
    class Context : public base::NoncopyableObject
    {
    public:
        static Context &get_instance();

    private:
        Context();

    public:
        ~Context();
        BASE_DELETE_COPY_FUNCTION(Context);

    public:
        void post_empty_event() const;
        void poll_events() const;
        void wait_events() const;
        void wait_events_timeout(double timeout) const;

        double get_time() const;
        base::UInt64 get_timer_value() const;
        base::UInt64 get_timer_frequency() const;

        void set_clipboard_string(const std::string &string) const;
        std::string get_clipboard_string() const;

    public:
        bool is_vulkan_supported() const;
        std::vector<std::string> get_required_instance_extensions() const;

#ifdef GLFW_WRAPPER_USE_VULKAN
        GLFWvkproc get_instance_proc_address(const std::string &name) const;
        GLFWvkproc get_instance_proc_address(VkInstance instance, const std::string &name) const;
        bool is_physical_device_presentation_supported(
            VkInstance instance, VkPhysicalDevice device, base::UInt32 queuefamily) const;
        VkResult create_window_surface(
            VkInstance instance, const Window &window,
            const VkAllocationCallbacks *allocator, VkSurfaceKHR *surface) const;
#endif
    };

} // namespace glfw_wrapper
