#pragma once

#include <base/misc/application.hpp>
#include <base/core/read_string.hpp>
#include "../base/context.hpp"
#include "../base/error_callback.hpp"
#include "../window/window_with_callback.hpp"

#ifndef GLFW_WRAPPER_ENABLE_GL_DEBUG
#define GLFW_WRAPPER_ENABLE_GL_DEBUG false
#endif

namespace glfw_wrapper
{
    /// @brief 主循环
    class MainLoop : public base::Application
    {
    protected:
        /// @brief GLFW上下文
        Context &m_glfw_context = Context::get_instance();
        /// @brief GLFW错误回调
        ErrorCallback &m_glfw_error_callback = ErrorCallback::get_instance();
        /// @brief GLFW窗口
        WindowWithCallback m_window;
        /// @brief 上次更新时间
        double m_last_update_time = 0.0;

    public:
        inline MainLoop() = default;
        inline ~MainLoop() override = default;

    protected:
        /// @brief 当更新时
        /// @param delta 时间增量
        virtual void _update(double delta) {}

        /// @brief 当绘制时
        virtual void _draw() {}

    public:
        inline const WindowWithCallback &get_window() const { return m_window; }
        inline double get_last_update_time() const { return m_last_update_time; }

    public:
        using base::Application::run;

        void run() override
        {
            Window::set_opengl(GLFW_WRAPPER_ENABLE_GL_DEBUG);
            m_window.create(glm::ivec2(1152, 648));
            m_window.make_context_current();

            _initialize();
            m_last_update_time = m_glfw_context.get_time();

            while (!is_should_quit() && !m_window.should_close())
            {
                m_glfw_context.poll_events();

                double now = m_glfw_context.get_time();
                double delta = now - m_last_update_time;
                _update(delta);
                m_last_update_time = now;

                _draw();
                m_window.swap_buffers();
            }

            _finalize();
        }
    };

} // namespace glfw_wrapper
