#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

class MyWindow : public glfw_wrapper::WindowWithCallback
{
public:
    MyWindow() { create(glm::ivec2(512, 512)); }
    ~MyWindow() override = default;

protected:
    void _on_window_close() override { std::cout << "window close" << std::endl; }
    void _on_framebuffer_size(const glm::ivec2 &size) override { std::cout << "framebuffer size" << std::endl; }
};

int main()
{
    auto &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    auto &context = glfw_wrapper::Context::get_instance();

    MyWindow window;
    window.make_context_current();
    while (!window.should_close())
    {
        context.poll_events();
        window.swap_buffers();
    }

    window.destroy();
    std::cout << window.is_valid() << std::endl;

    return 0;
}
