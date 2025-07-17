#pragma once

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

    void Window::set_hint(int hint, int value) { glfwWindowHint(hint, value); }

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

    Window::Window(const glm::ivec2 &size, const std::string &title) { create(size, title); }
    Window::Window(const glm::ivec2 &size, const std::string &title,
                   const Monitor &monitor) { create(size, title, monitor); }
    Window::Window(const glm::ivec2 &size, const std::string &title,
                   const Window &share) { create(size, title, share); }
    Window::Window(const glm::ivec2 &size, const std::string &title,
                   const Monitor &monitor, const Window &share) { create(size, title, monitor, share); }
    Window::Window(Window &&from) : m_window(std::exchange(from.m_window, nullptr)) {}
    Window::~Window() { destroy(); }

    Window &Window::operator=(Window &&from)
    {
        destroy();
        m_window = from.m_window;
        from.m_window = nullptr;
        return *this;
    }

    GLFWwindow *Window::get_window() const { return m_window; }
    base::Int64 Window::get_resource_type() const { return static_cast<::base::Int64>(ResourceType::Window); }
    bool Window::is_valid() const { return m_window; }
    Window::operator GLFWwindow *() const { return m_window; }

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

    void Window::set_input_mode(InputMode mode, base::Int32 value) { glfwSetInputMode(m_window, static_cast<int>(mode), value); }
    base::Int32 Window::get_input_mode(InputMode mode) const { return glfwGetInputMode(m_window, static_cast<int>(mode)); }
    base::Int32 Window::get_key(Key key) const { return glfwGetKey(m_window, static_cast<int>(key)); }

    void Window::set_cursor() { glfwSetCursor(m_window, nullptr); }
    void Window::set_cursor(const Cursor &cursor) { glfwSetCursor(m_window, cursor.get_cursor()); }

    std::string Window::get_clipboard_string() const
    {
        const char *string = glfwGetClipboardString(m_window);
        if (string)
            return string;
        else
            return {};
    }

    void Window::set_clipboard_string(const std::string &string) { glfwSetClipboardString(m_window, string.data()); }

    void Window::make_context_current() { glfwMakeContextCurrent(m_window); }
    void Window::swap_buffers() { glfwSwapBuffers(m_window); }
    void Window::swap_interval(base::Int32 interval) { glfwSwapInterval(interval); }
    void Window::iconify() { glfwIconifyWindow(m_window); }
    void Window::restore() { glfwRestoreWindow(m_window); }
    void Window::maximize() { glfwMaximizeWindow(m_window); }
    void Window::hide() { glfwHideWindow(m_window); }
    void Window::show() { glfwShowWindow(m_window); }
    void Window::focus() { glfwFocusWindow(m_window); }
    void Window::request_attention() { glfwRequestWindowAttention(m_window); }

    base::Int32 Window::get_attrib(base::Int32 attrib) { return glfwGetWindowAttrib(m_window, attrib); }
    base::Int32 Window::should_close() const { return glfwWindowShouldClose(m_window); }
    std::string Window::get_title() const { return glfwGetWindowTitle(m_window); }
    void *Window::get_user_pointer() const { return glfwGetWindowUserPointer(m_window); }
    Monitor Window::get_monitor() const { return glfwGetWindowMonitor(m_window); }
    float Window::get_opacity() const { return glfwGetWindowOpacity(m_window); }

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

    void Window::set_icon() { glfwSetWindowIcon(m_window, 0, nullptr); }
    void Window::set_icon(const Image *image) { glfwSetWindowIcon(m_window, 1, image); }
    void Window::set_attrib(base::Int32 attrib, base::Int32 value) { glfwSetWindowAttrib(m_window, attrib, value); }
    void Window::set_should_close(base::Int32 value) { glfwSetWindowShouldClose(m_window, value); }
    void Window::set_title(const std::string &title) { glfwSetWindowTitle(m_window, title.data()); }
    void Window::set_user_pointer(void *pointer) { glfwSetWindowUserPointer(m_window, pointer); }
    void Window::set_pos(const glm::ivec2 &pos) { glfwSetWindowPos(m_window, pos.x, pos.y); }
    void Window::set_size(const glm::ivec2 &size) { glfwSetWindowSize(m_window, size.x, size.y); }
    void Window::set_size_limits(const glm::ivec2 &min, const glm::ivec2 &max) { glfwSetWindowSizeLimits(m_window, min.x, min.y, max.x, max.y); }
    void Window::set_aspect_ratio(const glm::ivec2 &ratio) { glfwSetWindowAspectRatio(m_window, ratio.x, ratio.y); }
    void Window::set_opacity(float opacity) { glfwSetWindowOpacity(m_window, opacity); }

    void Window::set_monitor(const Monitor &monitor, const glm::ivec2 &pos, const glm::ivec2 &size, base::Int32 refresh_rate)
    {
        glfwSetWindowMonitor(m_window, monitor.get_monitor(), pos.x, pos.y, size.x, size.y, refresh_rate);
    }

} // namespace glfw_wrapper
