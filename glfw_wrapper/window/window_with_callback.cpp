#pragma once

#include "window_with_callback.hpp"

#define GLFW_WRAPPER_WINDOW_CALLBACK_CHECK \
    if (!window)                           \
        return;                            \
                                           \
    auto ptr = static_cast<WindowWithCallback *>(glfwGetWindowUserPointer(window));

#define GLFW_WRAPPER_WINDOW_CALLBACK_CALL(name, ...) \
    if (ptr->name##_callback)                        \
        ptr->name##_callback(__VA_ARGS__);           \
    ptr->_on_##name(__VA_ARGS__);

#define GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(name) \
    name##_callback(std::exchange(from.name##_callback, nullptr))

#define GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(name) \
    name##_callback = std::exchange(from.name##_callback, nullptr);

namespace glfw_wrapper
{
    WindowWithCallback::WindowWithCallback(WindowWithCallback &&from)
        : Window(std::move(from)),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_size),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(framebuffer_size),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_content_scale),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_pos),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_iconify),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_maximize),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_focus),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_refresh),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(key),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(char),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(cursor_pos),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(cursor_enter),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(mouse_button),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(scroll),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(drop),
          GLFW_WRAPPER_WINDOW_CALLBACK_MOVE(window_close) {}

    WindowWithCallback::~WindowWithCallback() { _disconnect_callbacks(); }

    WindowWithCallback &WindowWithCallback::operator=(WindowWithCallback &&from)
    {
        Window::operator=(std::move(from));
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_size);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(framebuffer_size);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_content_scale);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_pos);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_iconify);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_maximize);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_focus);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_refresh);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(key);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(char);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(cursor_pos);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(cursor_enter);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(mouse_button);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(scroll);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(drop);
        GLFW_WRAPPER_WINDOW_CALLBACK_ASSIGN(window_close);

        return *this;
    }

    void WindowWithCallback::create(const glm::ivec2 &size, const std::string &title)
    {
        _disconnect_callbacks();
        Window::create(size, title);
        _connect_callbacks();
    }

    void WindowWithCallback::create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        _disconnect_callbacks();
        Window::create(size, title, monitor);
        _connect_callbacks();
    }

    void WindowWithCallback::create(const glm::ivec2 &size, const std::string &title, const Window &share)
    {
        _disconnect_callbacks();
        Window::create(size, title, share);
        _connect_callbacks();
    }

    void WindowWithCallback::create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share)
    {
        _disconnect_callbacks();
        Window::create(size, title, monitor, share);
        _connect_callbacks();
    }

    void WindowWithCallback::_on_window_size(const glm::ivec2 &size) {}
    void WindowWithCallback::_on_framebuffer_size(const glm::ivec2 &size) {}
    void WindowWithCallback::_on_window_content_scale(const glm::vec2 &scale) {}
    void WindowWithCallback::_on_window_pos(const glm::ivec2 &pos) {}
    void WindowWithCallback::_on_window_iconify(bool iconified) {}
    void WindowWithCallback::_on_window_maximize(bool maximized) {}
    void WindowWithCallback::_on_window_focus(bool focused) {}
    void WindowWithCallback::_on_window_refresh() {}
    void WindowWithCallback::_on_key(Key key, base::Int32 scancode, Action action, Mod mod) {}
    void WindowWithCallback::_on_char(base::UInt32 codepoint) {}
    void WindowWithCallback::_on_cursor_pos(const glm::dvec2 &pos) {}
    void WindowWithCallback::_on_cursor_enter(bool entered) {}
    void WindowWithCallback::_on_mouse_button(MouseButton button, Action action, Mod mod) {}
    void WindowWithCallback::_on_scroll(const glm::dvec2 &offset) {}
    void WindowWithCallback::_on_drop(const std::vector<std::string> &paths) {}
    void WindowWithCallback::_on_window_close() {}

    void WindowWithCallback::_connect_callbacks()
    {
        if (!get_window())
            throw BASE_MAKE_CLASS_RUNTIME_ERROR("Unable to connect callbacks on null pointer object, this: ", this);

        glfwSetWindowUserPointer(get_window(), this);
        glfwSetWindowSizeCallback(get_window(), _window_size_callback);
        glfwSetFramebufferSizeCallback(get_window(), _framebuffer_size_callback);
        glfwSetWindowContentScaleCallback(get_window(), _window_content_scale_callback);
        glfwSetWindowPosCallback(get_window(), _window_pos_callback);
        glfwSetWindowIconifyCallback(get_window(), _window_iconify_callback);
        glfwSetWindowMaximizeCallback(get_window(), _window_maximize_callback);
        glfwSetWindowFocusCallback(get_window(), _window_focus_callback);
        glfwSetWindowRefreshCallback(get_window(), _window_refresh_callback);
        glfwSetKeyCallback(get_window(), _key_callback);
        glfwSetCharCallback(get_window(), _char_callback);
        glfwSetCursorPosCallback(get_window(), _cursor_pos_callback);
        glfwSetCursorEnterCallback(get_window(), _cursor_enter_callback);
        glfwSetMouseButtonCallback(get_window(), _mouse_button_callback);
        glfwSetScrollCallback(get_window(), _scroll_callback);
        glfwSetDropCallback(get_window(), _drop_callback);
        glfwSetWindowCloseCallback(get_window(), _window_close_callback);
    }

    void WindowWithCallback::_disconnect_callbacks()
    {
        if (!get_window())
            return;

        glfwSetWindowUserPointer(get_window(), nullptr);
        glfwSetWindowSizeCallback(get_window(), nullptr);
        glfwSetFramebufferSizeCallback(get_window(), nullptr);
        glfwSetWindowContentScaleCallback(get_window(), nullptr);
        glfwSetWindowPosCallback(get_window(), nullptr);
        glfwSetWindowIconifyCallback(get_window(), nullptr);
        glfwSetWindowMaximizeCallback(get_window(), nullptr);
        glfwSetWindowFocusCallback(get_window(), nullptr);
        glfwSetWindowRefreshCallback(get_window(), nullptr);
        glfwSetKeyCallback(get_window(), nullptr);
        glfwSetCharCallback(get_window(), nullptr);
        glfwSetCursorPosCallback(get_window(), nullptr);
        glfwSetCursorEnterCallback(get_window(), nullptr);
        glfwSetMouseButtonCallback(get_window(), nullptr);
        glfwSetScrollCallback(get_window(), nullptr);
        glfwSetDropCallback(get_window(), nullptr);
        glfwSetWindowCloseCallback(get_window(), nullptr);
    }

    void WindowWithCallback::_window_size_callback(GLFWwindow *window, int width, int height)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto size = glm::ivec2(width, height);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_size, size);
    }

    void WindowWithCallback::_framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto size = glm::ivec2(width, height);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(framebuffer_size, size);
    }

    void WindowWithCallback::_window_content_scale_callback(GLFWwindow *window, float xscale, float yscale)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto scale = glm::vec2(xscale, yscale);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_content_scale, scale);
    }

    void WindowWithCallback::_window_pos_callback(GLFWwindow *window, int xpos, int ypos)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto pos = glm::ivec2(xpos, ypos);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_pos, pos);
    }

    void WindowWithCallback::_window_iconify_callback(GLFWwindow *window, int iconified)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_iconify, iconified);
    }

    void WindowWithCallback::_window_maximize_callback(GLFWwindow *window, int maximized)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_maximize, maximized);
    }

    void WindowWithCallback::_window_focus_callback(GLFWwindow *window, int focused)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(window_focus, focused);
    }

    void WindowWithCallback::_window_refresh_callback(GLFWwindow *window)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        if (ptr->window_refresh_callback)
            ptr->window_refresh_callback();
        ptr->_on_window_refresh();
    }

    void WindowWithCallback::_key_callback(GLFWwindow *window, int key, int scancode, int action, int mod)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        if (ptr->key_callback)
            ptr->key_callback(static_cast<Key>(key), scancode, static_cast<Action>(action), static_cast<Mod>(mod));
        ptr->_on_key(static_cast<Key>(key), scancode, static_cast<Action>(action), static_cast<Mod>(mod));
    }

    void WindowWithCallback::_char_callback(GLFWwindow *window, unsigned int codepoint)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(char, codepoint);
    }

    void WindowWithCallback::_cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto pos = glm::ivec2(xpos, ypos);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(cursor_pos, pos);
    }

    void WindowWithCallback::_cursor_enter_callback(GLFWwindow *window, int entered)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(cursor_enter, entered);
    }

    void WindowWithCallback::_mouse_button_callback(GLFWwindow *window, int button, int action, int mod)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        if (ptr->mouse_button_callback)
            ptr->mouse_button_callback(static_cast<MouseButton>(button), static_cast<Action>(action), static_cast<Mod>(mod));
        ptr->_on_mouse_button(static_cast<MouseButton>(button), static_cast<Action>(action), static_cast<Mod>(mod));
    }

    void WindowWithCallback::_scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        auto offset = glm::dvec2(xoffset, yoffset);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(scroll, offset);
    }

    void WindowWithCallback::_drop_callback(GLFWwindow *window, int count, const char **paths)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        std::vector<std::string> path_vec(paths, paths + count);
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(drop, path_vec);
    }

    void WindowWithCallback::_window_close_callback(GLFWwindow *window)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        if (ptr->window_close_callback)
            ptr->window_close_callback();
        ptr->_on_window_close();
    }

} // namespace glfw_wrapper
