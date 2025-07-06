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
        std::cout << ext << std::endl;

    glfw_wrapper::Window::set_hint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfw_wrapper::Window::set_hint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfw_wrapper::Window::set_hint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto monitor = glfw_wrapper::Monitor::get_primary();
    auto window = glfw_wrapper::Window(glm::ivec2(640, 480), "", monitor);
    window.make_context_current();
    auto cursor = glfw_wrapper::Cursor(GLFW_HAND_CURSOR);
    window.set_cursor(cursor);

    while (!window.should_close())
    {
        context.poll_events();
        window.swap_buffers();
    }

    return 0;
}
