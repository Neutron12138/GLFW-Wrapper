#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

int main()
{
    glm::ivec3 version = glfw_wrapper::get_version();
    std::cout << "version: " << version.x << "." << version.y << "." << version.z << std::endl
              << "version string: " << glfw_wrapper::get_version_string() << std::endl
              << std::endl;

    glfw_wrapper::init_hint(GLFW_PLATFORM, GLFW_PLATFORM_WIN32);
    auto &error_callback = glfw_wrapper::ErrorCallback::get_instance();
    auto &context = glfw_wrapper::Context::get_instance();

    std::cout << "is support vulkan: " << (context.is_vulkan_supported() ? "true" : "false") << std::endl
              << "required extensions:" << std::endl;
    auto extensions = context.get_required_instance_extensions();
    for (auto &ext : extensions)
        std::cout << "\t" << ext << std::endl;

    auto monitor = glfw_wrapper::Monitor::get_primary();
    glfw_wrapper::Window::set_opengl();
    auto window = glfw_wrapper::create_window(glm::ivec2(512, 512), "test 1");
    window.make_context_current();
    auto cursor = glfw_wrapper::create_cursor(glfw_wrapper::Cursor::Shape::Hand);
    window.set_cursor(cursor);

    while (!window.should_close())
    {
        context.poll_events();
        window.swap_buffers();
    }

    return 0;
}
