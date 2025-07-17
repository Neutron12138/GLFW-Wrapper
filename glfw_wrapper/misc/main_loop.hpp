#pragma once

#include <base/misc/application.hpp>
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
        MainLoop() = default;
        ~MainLoop() override = default;

    protected:
        /// @brief 当更新时
        /// @param delta 时间增量
        virtual void _update(double delta);

        /// @brief 当绘制时
        virtual void _draw();

    public:
        const WindowWithCallback &get_window() const;
        double get_last_update_time() const;

    public:
        using base::Application::run;
        void run() override;
    };

} // namespace glfw_wrapper
