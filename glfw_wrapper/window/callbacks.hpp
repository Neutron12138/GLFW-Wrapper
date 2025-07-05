#pragma once

#include "glfw.hpp"

namespace window::glfw
{
    class Window;
    Window *convert_user_pointer(GLFWwindow *window);

    void _glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void _glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height);

} // namespace window::glfw
