#include "window.hpp"

namespace glfw_wrapper
{
    GLFWwindow *Window::create_glfw_window(int width, int height, const char *title,
                                           GLFWmonitor *monitor, GLFWwindow *share)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);
        if (!window)
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to create GLFW window\nwidth: ", width,
                ", height: ", height,
                ", title: \"", title,
                "\", monitor: ", monitor,
                ", share: ", share);

        return window;
    }

    void Window::set_opengl(const glm::ivec2 &version, bool enable_debug, base::Int32 profile)
    {
        set_hint(GLFW_CONTEXT_VERSION_MAJOR, version.x);
        set_hint(GLFW_CONTEXT_VERSION_MINOR, version.y);
        set_hint(GLFW_OPENGL_DEBUG_CONTEXT, enable_debug);
        set_hint(GLFW_OPENGL_PROFILE, profile);
    }

    void Window::set_opengl(bool enable_debug, base::Int32 profile)
    {
        set_opengl(glm::ivec2(4, 5), enable_debug, profile);
    }

    Window &Window::operator=(Window &&from)
    {
        destroy();
        m_window = from.m_window;
        from.m_window = nullptr;
        return *this;
    }

    void Window::create(const glm::ivec2 &size, const std::string &title)
    {
        destroy();
        m_window = create_glfw_window(size.x, size.y, title.data());
    }

    void Window::create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        destroy();
        m_window = create_glfw_window(size.x, size.y, title.data(), monitor, nullptr);
    }

    void Window::create(const glm::ivec2 &size, const std::string &title, const Window &share)
    {
        destroy();
        m_window = create_glfw_window(size.x, size.y, title.data(), nullptr, share);
    }

    void Window::create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share)
    {
        destroy();
        m_window = create_glfw_window(size.x, size.y, title.data(), monitor, share);
    }

    void Window::destroy()
    {
        if (m_window)
            glfwDestroyWindow(m_window);
        m_window = nullptr;
    }

    std::string Window::get_clipboard_string() const
    {
        const char *string = glfwGetClipboardString(m_window);
        if (string)
            return string;
        else
            return {};
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

    glm::vec2 Window::get_content_scale() const
    {
        glm::vec2 size;
        glfwGetWindowContentScale(m_window, &size.x, &size.y);
        return size;
    }

} // namespace glfw_wrapper
