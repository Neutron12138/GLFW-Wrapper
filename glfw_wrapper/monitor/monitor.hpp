#pragma once

#include <vector>
#include <base/core/ref.hpp>
#include <base/core/exception.hpp>
#include "../base/glfw.hpp"
#include "work_area.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Monitor);

    /// @brief GLFW监视器对象
    class Monitor
    {
    public:
        static inline Monitor get_primary() { return glfwGetPrimaryMonitor(); }
        static std::vector<Monitor> get_monitors();
        static inline GLFWmonitorfun set_callback(GLFWmonitorfun func) { return glfwSetMonitorCallback(func); }

    private:
        /// @brief GLFW监视器句柄
        GLFWmonitor *m_monitor = nullptr;

    public:
        inline Monitor() = default;
        inline Monitor(GLFWmonitor *monitor) : m_monitor(monitor) {}
        inline Monitor(const Monitor &another) : m_monitor(another.m_monitor) {}
        inline ~Monitor() = default;

    public:
        inline Monitor &operator=(GLFWmonitor *monitor)
        {
            m_monitor = monitor;
            return *this;
        }
        inline Monitor &operator=(const Monitor &another)
        {
            m_monitor = another.m_monitor;
            return *this;
        }
        inline GLFWmonitor *get_monitor() const { return m_monitor; }
        inline operator GLFWmonitor *() const { return m_monitor; }
        inline bool is_valid() const { return m_monitor; }

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
