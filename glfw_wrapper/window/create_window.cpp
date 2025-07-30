#pragma once

#include "window.hpp"

namespace glfw_wrapper
{
    Window create_window(const glm::ivec2 &size, const std::string &title)
    {
        Window window;
        window.create(size, title);
        return window;
    }

    Window create_window(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        Window window;
        window.create(size, title, monitor);
        return window;
    }

    Window create_window(const glm::ivec2 &size, const std::string &title, const Window &share)
    {
        Window window;
        window.create(size, title, share);
        return window;
    }

    Window create_window(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share)
    {
        Window window;
        window.create(size, title, monitor, share);
        return window;
    }

    WindowRef create_window_shared(const glm::ivec2 &size, const std::string &title)
    {
        WindowRef window = std::make_shared<Window>();
        window->create(size, title);
        return window;
    }

    WindowRef create_window_shared(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        WindowRef window = std::make_shared<Window>();
        window->create(size, title, monitor);
        return window;
    }

    WindowRef create_window_shared(const glm::ivec2 &size, const std::string &title, const Window &share)
    {
        WindowRef window = std::make_shared<Window>();
        window->create(size, title, share);
        return window;
    }

    WindowRef create_window_shared(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share)
    {
        WindowRef window = std::make_shared<Window>();
        window->create(size, title, monitor, share);
        return window;
    }

    WindowUniqueRef create_window_unique(const glm::ivec2 &size, const std::string &title)
    {
        WindowUniqueRef window = std::make_unique<Window>();
        window->create(size, title);
        return window;
    }

    WindowUniqueRef create_window_unique(const glm::ivec2 &size, const std::string &title, const Monitor &monitor)
    {
        WindowUniqueRef window = std::make_unique<Window>();
        window->create(size, title, monitor);
        return window;
    }

    WindowUniqueRef create_window_unique(const glm::ivec2 &size, const std::string &title, const Window &share)
    {
        WindowUniqueRef window = std::make_unique<Window>();
        window->create(size, title, share);
        return window;
    }

    WindowUniqueRef create_window_unique(const glm::ivec2 &size, const std::string &title, const Monitor &monitor, const Window &share)
    {
        WindowUniqueRef window = std::make_unique<Window>();
        window->create(size, title, monitor, share);
        return window;
    }

} // namespace glfw_wrapper
