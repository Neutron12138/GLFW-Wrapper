#include "window_with_callback.hpp"

#define GLFW_WRAPPER_WINDOW_CALLBACK_CHECK \
    if (!window)                           \
        return;                            \
                                           \
    auto ptr = static_cast<WindowWithCallback *>(glfwGetWindowUserPointer(window));

#define GLFW_WRAPPER_WINDOW_CALLBACK_CALL(name, ...) \
    if (ptr->name##_callback)                        \
        ptr->name##_callback(*ptr, __VA_ARGS__);     \
    ptr->_on_##name(__VA_ARGS__);

namespace glfw_wrapper
{
    void WindowWithCallback::_connect_callbacks()
    {
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
        glfwSetWindowUserPointer(get_window(), nullptr);
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
            ptr->window_refresh_callback(*ptr);
        ptr->_on_window_refresh();
    }

    void WindowWithCallback::_key_callback(GLFWwindow *window, int key, int scancode, int action, int mod)
    {
        GLFW_WRAPPER_WINDOW_CALLBACK_CHECK;
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(key, key, scancode, action, mod);
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
        GLFW_WRAPPER_WINDOW_CALLBACK_CALL(mouse_button, button, action, mod);
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
            ptr->window_close_callback(*ptr);
        ptr->_on_window_close();
    }

} // namespace glfw_wrapper
