#pragma once

#include <vector>
#include <bits/refwrap.h>
#include <base/core/ref.hpp>
#include <base/core/exception.hpp>
#include "../base/glfw.hpp"
#include "work_area.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Monitor);

    class Monitor
    {
    public:
        static inline Monitor get_primary() { return glfwGetPrimaryMonitor(); }
        static std::vector<Monitor> get_monitors();

    private:
        GLFWmonitor *m_monitor;

    public:
        inline Monitor(GLFWmonitor *monitor) : m_monitor(monitor)
        {
            if (!monitor)
                throw BASE_MAKE_RUNTIME_ERROR("Unable to observe an empty monitor");
        }

        inline ~Monitor() = default;

    public:
        inline GLFWmonitor *get_monitor() const { return m_monitor; }

    public:
        std::vector<VideoMode> get_video_modes() const;
        glm::ivec2 get_physical_size() const;
        glm::vec2 get_content_scale() const;
        glm::ivec2 get_position() const;
        WorkArea get_work_area() const;

        inline VideoMode get_video_mode() const { return *glfwGetVideoMode(m_monitor); }
        inline std::string get_name() const { return glfwGetMonitorName(m_monitor); }
        inline void *get_user_pointer() const { return glfwGetMonitorUserPointer(m_monitor); }
        inline GammaRamp get_gamma_ramp() const { return *glfwGetGammaRamp(m_monitor); }

        inline void set_user_pointer(void *pointer) { glfwSetMonitorUserPointer(m_monitor, pointer); }
        inline void set_gamma_ramp(const GammaRamp *ramp) { glfwSetGammaRamp(m_monitor, ramp); }
        inline void set_gamma(float gamma) { glfwSetGamma(m_monitor, gamma); }
    };

} // namespace glfw_wrapper
