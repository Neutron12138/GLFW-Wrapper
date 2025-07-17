#pragma once

#include "main_loop.hpp"

namespace glfw_wrapper
{
    void MainLoop::_update(double delta) {}
    void MainLoop::_draw() {}

    const WindowWithCallback &MainLoop::get_window() const { return m_window; }
    double MainLoop::get_last_update_time() const { return m_last_update_time; }
    const glm::ivec2 &MainLoop::get_opengl_context_version() const { return m_opengl_context_version; }
    bool MainLoop::is_opengl_debug_context_enabled() const { return m_is_opengl_debug_context_enabled; }
    const glm::ivec2 &MainLoop::get_initial_window_size() const { return m_initial_window_size; }
    const std::string &MainLoop::get_initial_window_title() const { return m_initial_window_title; }

    void MainLoop::run()
    {
        Window::set_opengl(m_opengl_context_version,
                           m_is_opengl_debug_context_enabled,
                           m_opengl_profile);
        m_window.create(m_initial_window_size,
                        m_initial_window_title);
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
