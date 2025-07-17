#pragma once

#include "monitor.hpp"

namespace glfw_wrapper
{
    Monitor Monitor::get_primary() { return glfwGetPrimaryMonitor(); }

    std::vector<Monitor> Monitor::get_monitors()
    {
        int count;
        GLFWmonitor **monitors = glfwGetMonitors(&count);
        if (!monitors)
            return {};

        return std::move(std::vector<Monitor>(monitors, monitors + count));
    }

    GLFWmonitorfun Monitor::set_callback(GLFWmonitorfun func) { return glfwSetMonitorCallback(func); }

    Monitor::Monitor(GLFWmonitor *monitor) : m_monitor(monitor) {}
    Monitor::Monitor(const Monitor &another) : m_monitor(another.m_monitor) {}

    Monitor &Monitor::operator=(GLFWmonitor *monitor)
    {
        m_monitor = monitor;
        return *this;
    }
    Monitor &Monitor::operator=(const Monitor &another)
    {
        m_monitor = another.m_monitor;
        return *this;
    }

    GLFWmonitor *Monitor::get_monitor() const { return m_monitor; }
    Monitor::operator GLFWmonitor *() const { return m_monitor; }
    bool Monitor::is_valid() const { return m_monitor; }

    std::vector<VideoMode> Monitor::get_video_modes() const
    {
        int count;
        const GLFWvidmode *video_modes = glfwGetVideoModes(m_monitor, &count);
        if (!video_modes)
            return {};

        return std::move(std::vector<VideoMode>(video_modes, video_modes + count));
    }

    glm::ivec2 Monitor::get_physical_size() const
    {
        glm::ivec2 size;
        glfwGetMonitorPhysicalSize(m_monitor, &size.x, &size.y);
        return size;
    }

    glm::vec2 Monitor::get_content_scale() const
    {
        glm::vec2 scale;
        glfwGetMonitorContentScale(m_monitor, &scale.x, &scale.y);
        return scale;
    }

    glm::ivec2 Monitor::get_position() const
    {
        glm::ivec2 pos;
        glfwGetMonitorPos(m_monitor, &pos.x, &pos.y);
        return pos;
    }

    WorkArea Monitor::get_work_area() const
    {
        glm::ivec2 pos, size;
        glfwGetMonitorWorkarea(m_monitor, &pos.x, &pos.y, &size.x, &size.y);
        return WorkArea(pos, size);
    }

    VideoMode Monitor::get_video_mode() const { return *glfwGetVideoMode(m_monitor); }
    std::string Monitor::get_name() const { return glfwGetMonitorName(m_monitor); }
    void *Monitor::get_user_pointer() const { return glfwGetMonitorUserPointer(m_monitor); }
    GammaRamp Monitor::get_gamma_ramp() const { return *glfwGetGammaRamp(m_monitor); }

    void Monitor::set_user_pointer(void *pointer) { glfwSetMonitorUserPointer(m_monitor, pointer); }
    void Monitor::set_gamma_ramp(const GammaRamp *ramp) { glfwSetGammaRamp(m_monitor, ramp); }
    void Monitor::set_gamma(float gamma) { glfwSetGamma(m_monitor, gamma); }

} // namespace glfw_wrapper
