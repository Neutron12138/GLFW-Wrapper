#include "monitor.hpp"

namespace glfw_wrapper
{
    std::vector<Monitor> Monitor::get_monitors()
    {
        int count;
        GLFWmonitor **monitors = glfwGetMonitors(&count);
        if (!monitors)
            return {};

        return std::move(std::vector<Monitor>(monitors, monitors + count));
    }

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

} // namespace glfw_wrapper
