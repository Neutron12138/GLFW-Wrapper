#pragma once

#include "../base/resource.hpp"
#include "../cursor/cursor.hpp"
#include "../monitor/monitor.hpp"
#include "../base/enums.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Window);

    /// @brief GLFW窗口
    class Window : public Resource
    {
    public:
        /// @brief 输入模式
        enum class InputMode : base::Int32
        {
            Cursor = GLFW_CURSOR,
            StickyKeys = GLFW_STICKY_KEYS,
            StickyMouseButtons = GLFW_STICKY_MOUSE_BUTTONS,
            LockKeyMods = GLFW_LOCK_KEY_MODS,
            RawMouseMotion = GLFW_RAW_MOUSE_MOTION,
        };

        static GLFWwindow *create_glfw_window(int width, int height, const char *title = "",
                                              GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);

        static void set_hint(int hint, int value);

        static void set_opengl(const glm::ivec2 &version, bool enable_debug = false, base::Int32 profile = GLFW_OPENGL_CORE_PROFILE);
        static void set_opengl(bool enable_debug = false, base::Int32 profile = GLFW_OPENGL_CORE_PROFILE);

    private:
        /// @brief GLFW窗口句柄
        GLFWwindow *m_window = nullptr;

    public:
        Window() = default;
        Window(const glm::ivec2 &size, const std::string &title = {});
        Window(const glm::ivec2 &size, const std::string &title, const Monitor &monitor);
        Window(const glm::ivec2 &size, const std::string &title, const Window &share);
        Window(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share);
        Window(Window &&from);
        ~Window() override;
        BASE_DELETE_COPY_FUNCTION(Window);

    public:
        Window &operator=(Window &&from);
        GLFWwindow *get_window() const;
        base::Int64 get_resource_type() const override;
        bool is_valid() const override;
        operator GLFWwindow *() const;

    public:
        virtual void create(const glm::ivec2 &size, const std::string &title = {});
        virtual void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor);
        virtual void create(const glm::ivec2 &size, const std::string &title, const Window &share);
        virtual void create(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share);
        void destroy();

    public:
        void set_input_mode(InputMode mode, base::Int32 value);
        base::Int32 get_input_mode(InputMode mode) const;
        base::Int32 get_key(Key key) const;

        void set_cursor();
        void set_cursor(const Cursor &cursor);
        std::string get_clipboard_string() const;
        void set_clipboard_string(const std::string &string);

        void make_context_current();
        void swap_buffers();
        void swap_interval(base::Int32 interval);
        void iconify();
        void restore();
        void maximize();
        void hide();
        void show();
        void focus();
        void request_attention();

        base::Int32 get_attrib(base::Int32 attrib);
        base::Int32 should_close() const;
        std::string get_title() const;
        void *get_user_pointer() const;
        Monitor get_monitor() const;
        float get_opacity() const;
        glm::ivec2 get_pos() const;
        glm::ivec2 get_size() const;
        glm::ivec2 get_framebuffer_size() const;
        glm::vec2 get_content_scale() const;

        void set_icon();
        void set_icon(const Image *image);
        void set_attrib(base::Int32 attrib, base::Int32 value);
        void set_should_close(base::Int32 value);
        void set_title(const std::string &title);
        void set_user_pointer(void *pointer);
        void set_pos(const glm::ivec2 &pos);
        void set_size(const glm::ivec2 &size);
        void set_size_limits(const glm::ivec2 &min, const glm::ivec2 &max);
        void set_aspect_ratio(const glm::ivec2 &ratio);
        void set_opacity(float opacity);
        void set_monitor(const Monitor &monitor, const glm::ivec2 &pos, const glm::ivec2 &size, base::Int32 refresh_rate);
    };

} // namespace glfw_wrapper
