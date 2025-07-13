#pragma once

#include "../base/resource.hpp"
#include "../cursor/cursor.hpp"
#include "../monitor/monitor.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Window);

    /// @brief GLFW窗口
    class Window : public Resource
    {
    public:
        static GLFWwindow *create_glfw_window(int width, int height, const char *title = "",
                                              GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);

        static void set_hint(int hint, int value) { glfwWindowHint(hint, value); }

        static void set_opengl(const glm::ivec2 &version, bool enable_debug = false, base::Int32 profile = GLFW_OPENGL_CORE_PROFILE);
        static void set_opengl(bool enable_debug = false, base::Int32 profile = GLFW_OPENGL_CORE_PROFILE);

    private:
        /// @brief GLFW窗口句柄
        GLFWwindow *m_window = nullptr;

    public:
        inline Window() = default;
        inline Window(const glm::ivec2 &size, const std::string &title = {}) { create(size, title); }
        inline Window(const glm::ivec2 &size, const std::string &title,
                      const Monitor &monitor) { create(size, title, monitor); }
        inline Window(const glm::ivec2 &size, const std::string &title,
                      const Window &share) { create(size, title, share); }
        inline Window(const glm::ivec2 &size, const std::string &title,
                      const Monitor &monitor, const Window &share) { create(size, title, monitor, share); }
        Window(Window &&from) : m_window(std::exchange(from.m_window, nullptr)) {}
        inline ~Window() override { destroy(); }
        BASE_DELETE_COPY_FUNCTION(Window);

    public:
        Window &operator=(Window &&from);
        inline GLFWwindow *get_window() const { return m_window; }
        inline base::Int64 get_resource_type() const override { return static_cast<::base::Int64>(ResourceType::Window); }
        inline bool is_valid() const override { return m_window; }
        inline operator GLFWwindow *() const { return m_window; }

    public:
        virtual void create(const glm::ivec2 &size, const std::string &title = {});
        virtual void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor);
        virtual void create(const glm::ivec2 &size, const std::string &title, const Window &share);
        virtual void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share);
        void destroy();

    public:
        inline void set_input_mode(base::Int32 mode, base::Int32 value) { glfwSetInputMode(m_window, mode, value); }
        inline base::Int32 get_key(base::Int32 key) { return glfwGetKey(m_window, key); }

        inline void set_cursor() { glfwSetCursor(m_window, nullptr); }
        inline void set_cursor(const Cursor &cursor) { glfwSetCursor(m_window, cursor.get_cursor()); }
        std::string get_clipboard_string() const;
        inline void set_clipboard_string(const std::string &string) { glfwSetClipboardString(m_window, string.data()); }

        inline void make_context_current() { glfwMakeContextCurrent(m_window); }
        inline void swap_buffers() { glfwSwapBuffers(m_window); }
        inline void swap_interval(base::Int32 interval) { glfwSwapInterval(interval); }
        inline void iconify() { glfwIconifyWindow(m_window); }
        inline void restore() { glfwRestoreWindow(m_window); }
        inline void maximize() { glfwMaximizeWindow(m_window); }
        inline void hide() { glfwHideWindow(m_window); }
        inline void show() { glfwShowWindow(m_window); }
        inline void focus() { glfwFocusWindow(m_window); }
        inline void request_attention() { glfwRequestWindowAttention(m_window); }

        inline base::Int32 get_attrib(base::Int32 attrib) { return glfwGetWindowAttrib(m_window, attrib); }
        inline base::Int32 should_close() const { return glfwWindowShouldClose(m_window); }
        inline std::string get_title() const { return glfwGetWindowTitle(m_window); }
        inline void *get_user_pointer() const { return glfwGetWindowUserPointer(m_window); }
        inline Monitor get_monitor() const { return glfwGetWindowMonitor(m_window); }
        inline float get_opacity() const { return glfwGetWindowOpacity(m_window); }
        glm::ivec2 get_pos() const;
        glm::ivec2 get_size() const;
        glm::ivec2 get_framebuffer_size() const;
        glm::vec2 get_content_scale() const;

        inline void set_icon() { glfwSetWindowIcon(m_window, 0, nullptr); }
        inline void set_icon(const Image *image) { glfwSetWindowIcon(m_window, 1, image); }
        inline void set_attrib(base::Int32 attrib, base::Int32 value) { glfwSetWindowAttrib(m_window, attrib, value); }
        inline void set_should_close(base::Int32 value) { glfwSetWindowShouldClose(m_window, value); }
        inline void set_title(const std::string &title) { glfwSetWindowTitle(m_window, title.data()); }
        inline void set_user_pointer(void *pointer) { glfwSetWindowUserPointer(m_window, pointer); }
        inline void set_pos(const glm::ivec2 &pos) { glfwSetWindowPos(m_window, pos.x, pos.y); }
        inline void set_size(const glm::ivec2 &size) { glfwSetWindowSize(m_window, size.x, size.y); }
        inline void set_size_limits(const glm::ivec2 &min, const glm::ivec2 &max) { glfwSetWindowSizeLimits(m_window, min.x, min.y, max.x, max.y); }
        inline void set_aspect_ratio(const glm::ivec2 &ratio) { glfwSetWindowAspectRatio(m_window, ratio.x, ratio.y); }
        inline void set_opacity(float opacity) { glfwSetWindowOpacity(m_window, opacity); }
        inline void set_monitor(const Monitor &monitor, const glm::ivec2 &pos, const glm::ivec2 &size, base::Int32 refresh_rate)
        {
            glfwSetWindowMonitor(m_window, monitor.get_monitor(), pos.x, pos.y, size.x, size.y, refresh_rate);
        }
    };

} // namespace glfw_wrapper
