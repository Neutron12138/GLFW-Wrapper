#pragma once

#include "window.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(WindowWithCallback);

    /// @brief 带事件回调的窗口
    class WindowWithCallback : public Window
    {
    public:
        using WindowSizeFunc = void(WindowWithCallback &, const glm::ivec2 &);
        using WindowSizeCallback = std::function<WindowSizeFunc>;

        using FramebufferSizeFunc = void(WindowWithCallback &, const glm::ivec2 &);
        using FramebufferSizeCallback = std::function<FramebufferSizeFunc>;

        using WindowContentScaleFunc = void(WindowWithCallback &, const glm::vec2 &);
        using WindowContentScaleCallback = std::function<WindowContentScaleFunc>;

        using WindowPosFunc = void(WindowWithCallback &, const glm::ivec2 &);
        using WindowPosCallback = std::function<WindowPosFunc>;

        using WindowIconifyFunc = void(WindowWithCallback &, bool);
        using WindowIconifyCallback = std::function<WindowIconifyFunc>;

        using WindowMaximizeFunc = void(WindowWithCallback &, bool);
        using WindowMaximizeCallback = std::function<WindowMaximizeFunc>;

        using WindowFocusFunc = void(WindowWithCallback &, bool);
        using WindowFocusCallback = std::function<WindowFocusFunc>;

        using WindowRefreshFunc = void(WindowWithCallback &);
        using WindowRefreshCallback = std::function<WindowRefreshFunc>;

        using KeyFunc = void(WindowWithCallback &, base::Int32, base::Int32, base::Int32, base::Int32);
        using KeyCallback = std::function<KeyFunc>;

        using CharFunc = void(WindowWithCallback &, base::UInt32 codepoint);
        using CharCallback = std::function<CharFunc>;

        using CursorPosFunc = void(WindowWithCallback &, const glm::dvec2 &pos);
        using CursorPosCallback = std::function<CursorPosFunc>;

        using CursorEnterFunc = void(WindowWithCallback &, bool);
        using CursorEnterCallback = std::function<CursorEnterFunc>;

        using MouseButtonFunc = void(WindowWithCallback &, base::Int32, base::Int32, base::Int32);
        using MouseButtonCallback = std::function<MouseButtonFunc>;

        using ScrollFunc = void(WindowWithCallback &, const glm::dvec2 &);
        using ScrollCallback = std::function<ScrollFunc>;

        using DropFunc = void(WindowWithCallback &, const std::vector<std::string> &paths);
        using DropCallback = std::function<DropFunc>;

        using WindowCloseFunc = void(WindowWithCallback &);
        using WindowCloseCallback = std::function<WindowCloseFunc>;

    public:
        WindowSizeCallback window_size_callback;
        FramebufferSizeCallback framebuffer_size_callback;
        WindowContentScaleCallback window_content_scale_callback;
        WindowPosCallback window_pos_callback;
        WindowIconifyCallback window_iconify_callback;
        WindowMaximizeCallback window_maximize_callback;
        WindowFocusCallback window_focus_callback;
        WindowRefreshCallback window_refresh_callback;
        KeyCallback key_callback;
        CharCallback char_callback;
        CursorPosCallback cursor_pos_callback;
        CursorEnterCallback cursor_enter_callback;
        MouseButtonCallback mouse_button_callback;
        ScrollCallback scroll_callback;
        DropCallback drop_callback;
        WindowCloseCallback window_close_callback;

    public:
        WindowWithCallback() = default;
        WindowWithCallback(const glm::ivec2 &size, const std::string &title = {});
        WindowWithCallback(const glm::ivec2 &size, const std::string &title,
                           const Monitor &monitor);
        WindowWithCallback(const glm::ivec2 &size, const std::string &title,
                           const Window &share);
        WindowWithCallback(const glm::ivec2 &size, const std::string &title,
                           const Monitor &monitor, const Window &share);
        ~WindowWithCallback() override;
        BASE_DELETE_COPY_FUNCTION(WindowWithCallback);

    public:
        void create(const glm::ivec2 &size, const std::string &title = {}) override;
        void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor) override;
        void create(const glm::ivec2 &size, const std::string &title, const Window &share) override;
        void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share) override;

    protected:
        virtual void _on_window_size(const glm::ivec2 &size);
        virtual void _on_framebuffer_size(const glm::ivec2 &size);
        virtual void _on_window_content_scale(const glm::vec2 &scale);
        virtual void _on_window_pos(const glm::ivec2 &pos);
        virtual void _on_window_iconify(bool iconified);
        virtual void _on_window_maximize(bool maximized);
        virtual void _on_window_focus(bool focused);
        virtual void _on_window_refresh();
        virtual void _on_key(base::Int32 key, base::Int32 scancode, base::Int32 action, base::Int32 mod);
        virtual void _on_char(base::UInt32 codepoint);
        virtual void _on_cursor_pos(const glm::dvec2 &pos);
        virtual void _on_cursor_enter(bool entered);
        virtual void _on_mouse_button(base::Int32 button, base::Int32 action, base::Int32 mod);
        virtual void _on_scroll(const glm::dvec2 &offset);
        virtual void _on_drop(const std::vector<std::string> &paths);
        virtual void _on_window_close();

    private:
        void _connect_callbacks();
        void _disconnect_callbacks();

        static void _window_size_callback(GLFWwindow *window, int width, int height);
        static void _framebuffer_size_callback(GLFWwindow *window, int width, int height);
        static void _window_content_scale_callback(GLFWwindow *window, float xscale, float yscale);
        static void _window_pos_callback(GLFWwindow *window, int xpos, int ypos);
        static void _window_iconify_callback(GLFWwindow *window, int iconified);
        static void _window_maximize_callback(GLFWwindow *window, int maximized);
        static void _window_focus_callback(GLFWwindow *window, int focused);
        static void _window_refresh_callback(GLFWwindow *window);
        static void _key_callback(GLFWwindow *window, int key, int scancode, int action, int mod);
        static void _char_callback(GLFWwindow *window, unsigned int codepoint);
        static void _cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
        static void _cursor_enter_callback(GLFWwindow *window, int entered);
        static void _mouse_button_callback(GLFWwindow *window, int button, int action, int mod);
        static void _scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
        static void _drop_callback(GLFWwindow *window, int count, const char **paths);
        static void _window_close_callback(GLFWwindow *window);
    };

} // namespace glfw_wrapper
