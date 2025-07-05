#include "window.hpp"

namespace glfw_wrapper
{
    GLFWwindow *Window::create_glfw_window(int width, int height, const char *title,
                                           GLFWmonitor *monitor, GLFWwindow *share)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);
        if (!window)
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to create GLFW window with width: ", width,
                ", height: ", height,
                ", title: \"", title,
                "\", monitor: ", monitor,
                ", share: ", share);

        return window;
    }

    glm::ivec2 Window::get_pos() const
    {
        glm::ivec2 pos;
        glfwGetWindowPos(m_window, &pos.x, &pos.y);
        return pos;
    }

    glm::ivec2 Window::get_size() const
    {
        glm::ivec2 size;
        glfwGetWindowSize(m_window, &size.x, &size.y);
        return size;
    }

    glm::ivec2 Window::get_framebuffer_size() const
    {
        glm::ivec2 size;
        glfwGetFramebufferSize(m_window, &size.x, &size.y);
        return size;
    }

} // namespace glfw_wrapper
