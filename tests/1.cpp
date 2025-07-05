#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

int main()
{
    auto &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    auto &context = glfw_wrapper::Context::get_instance();
    auto window = glfw_wrapper::Window(glm::ivec2(640, 480), "");
    while (!window.should_close())
        context.poll_events();

    return 0;
}
