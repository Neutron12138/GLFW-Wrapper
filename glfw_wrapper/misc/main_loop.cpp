#pragma once

#include "main_loop.hpp"

namespace glfw_wrapper
{
    void MainLoop::_update(double delta) {}
    void MainLoop::_draw() {}

    const WindowWithCallback &MainLoop::get_window() const { return m_window; }
    double MainLoop::get_last_update_time() const { return m_last_update_time; }

    void MainLoop::run()
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

} // namespace glfw_wrapper
