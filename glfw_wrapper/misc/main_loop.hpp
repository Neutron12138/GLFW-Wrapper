#pragma once

#include <base/misc/application.hpp>
#include "../base/context.hpp"
#include "../base/error_callback.hpp"
#include "../window/window_with_callback.hpp"

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
        /// @brief OpenGL上下文版本
        glm::ivec2 m_opengl_context_version = glm::ivec2(4, 5);
        /// @brief 启用OpenGL调试
        bool m_is_opengl_debug_context_enabled = false;
        /// @brief OpenGL代理
        base::Int32 m_opengl_profile = GLFW_OPENGL_CORE_PROFILE;
        /// @brief 初始窗口大小
        glm::ivec2 m_initial_window_size = glm::ivec2(1152, 648);
        /// @brief 初始窗口标题
        std::string m_initial_window_title = {};

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
        const glm::ivec2 &get_opengl_context_version() const;
        bool is_opengl_debug_context_enabled() const;
        const glm::ivec2 &get_initial_window_size() const;
        const std::string &get_initial_window_title() const;

    public:
        using base::Application::run;
        void run() override;
    };

} // namespace glfw_wrapper
