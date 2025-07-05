#pragma once

#include <iostream>
#include <base/core/type.hpp>
#include <base/core/noncopyable_object.hpp>
#include <base/core/exception.hpp>
#include "glfw.hpp"

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
        inline ::base::UInt64 get_timer_value() const { return glfwGetTimerValue(); }
        inline ::base::UInt64 get_timer_frequency() const { return glfwGetTimerFrequency(); }
    };

} // namespace glfw_wrapper
