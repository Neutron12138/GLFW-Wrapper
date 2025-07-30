#pragma once

#include "window_with_callback.hpp"

namespace glfw_wrapper
{
    WindowWithCallback create_window_with_callback(const glm::ivec2 &size, const std::string &title)
    {
        WindowWithCallback window;
        window.create(size, title);
        return window;
    }

    WindowWithCallback create_window_with_callback(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        WindowWithCallback window;
        window.create(size, title, monitor);
        return window;
    }

    WindowWithCallback create_window_with_callback(const glm::ivec2 &size, const std::string &title, const WindowWithCallback &share)
    {
        WindowWithCallback window;
        window.create(size, title, share);
        return window;
    }

    WindowWithCallback create_window_with_callback(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const WindowWithCallback &share)
    {
        WindowWithCallback window;
        window.create(size, title, monitor, share);
        return window;
    }

    WindowWithCallbackRef create_window_with_callback_shared(const glm::ivec2 &size, const std::string &title)
    {
        WindowWithCallbackRef window = std::make_shared<WindowWithCallback>();
        window->create(size, title);
        return window;
    }

    WindowWithCallbackRef create_window_with_callback_shared(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        WindowWithCallbackRef window = std::make_shared<WindowWithCallback>();
        window->create(size, title, monitor);
        return window;
    }

    WindowWithCallbackRef create_window_with_callback_shared(const glm::ivec2 &size, const std::string &title, const WindowWithCallback &share)
    {
        WindowWithCallbackRef window = std::make_shared<WindowWithCallback>();
        window->create(size, title, share);
        return window;
    }

    WindowWithCallbackRef create_window_with_callback_shared(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const WindowWithCallback &share)
    {
        WindowWithCallbackRef window = std::make_shared<WindowWithCallback>();
        window->create(size, title, monitor, share);
        return window;
    }

    WindowWithCallbackUniqueRef create_window_with_callback_unique(const glm::ivec2 &size, const std::string &title)
    {
        WindowWithCallbackUniqueRef window = std::make_unique<WindowWithCallback>();
        window->create(size, title);
        return window;
    }

    WindowWithCallbackUniqueRef create_window_with_callback_unique(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        WindowWithCallbackUniqueRef window = std::make_unique<WindowWithCallback>();
        window->create(size, title, monitor);
        return window;
    }

    WindowWithCallbackUniqueRef create_window_with_callback_unique(const glm::ivec2 &size, const std::string &title, const WindowWithCallback &share)
    {
        WindowWithCallbackUniqueRef window = std::make_unique<WindowWithCallback>();
        window->create(size, title, share);
        return window;
    }

    WindowWithCallbackUniqueRef create_window_with_callback_unique(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const WindowWithCallback &share)
    {
        WindowWithCallbackUniqueRef window = std::make_unique<WindowWithCallback>();
        window->create(size, title, monitor, share);
        return window;
    }

} // namespace glfw_wrapper
