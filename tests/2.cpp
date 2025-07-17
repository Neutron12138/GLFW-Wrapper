#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

class MyWindow : public glfw_wrapper::WindowWithCallback
{
public:
    MyWindow() : glfw_wrapper::WindowWithCallback(glm::ivec2(512, 512)) {}
    ~MyWindow() override = default;

protected:
    void _on_window_close() override { std::cout << "window close" << std::endl; }
    void _on_framebuffer_size(const glm::ivec2 &size) override { std::cout << "framebuffer size" << std::endl; }

    void _on_key(glfw_wrapper::Key key, base::Int32, glfw_wrapper::Action action, glfw_wrapper::Mod)
    {
        switch (key)
        {
        case glfw_wrapper::Key::W:
            std::cout << "key W is ";
            break;

        case glfw_wrapper::Key::S:
            std::cout << "key S is ";
            break;

        case glfw_wrapper::Key::A:
            std::cout << "key A is ";
            break;

        case glfw_wrapper::Key::D:
            std::cout << "key D is ";
            break;
        }

        switch (action)
        {
        case glfw_wrapper::Action::Release:
            std::cout << "released" << std::endl;
            break;

        case glfw_wrapper::Action::Press:
            std::cout << "pressed" << std::endl;
            break;

        case glfw_wrapper::Action::Repeat:
            std::cout << "repeated" << std::endl;
            break;
        }
    }
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
