#include "callbacks.hpp"
#include "window.hpp"
#include "../common/resized_event.hpp"
#include "../common/key_event.hpp"
#include "enum_convert.hpp"

namespace window::glfw
{
    Window *convert_user_pointer(GLFWwindow *window)
    {
        void *user_ptr = glfwGetWindowUserPointer(window);
        Window *window_ptr = reinterpret_cast<Window *>(user_ptr);
        return window_ptr;
    }

    void _glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Window *window_ptr = convert_user_pointer(window);
        if (!window_ptr)
            return;

        Key kc = convert_key(key);
        Action act = convert_action(action);

        window_ptr->request_handle_event(std::make_shared<KeyEvent>(kc, act));
    }

    void _glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        Window *window_ptr = convert_user_pointer(window);
        if (!window_ptr)
            return;

        window_ptr->request_handle_event(std::make_shared<ResizedEvent>(width, height));
    }

} // namespace window::glfw
