#pragma once

#include "glfw.hpp"

namespace glfw_wrapper
{
    glm::ivec3 get_version()
    {
        glm::ivec3 version;
        glfwGetVersion(&version.x, &version.y, &version.z);
        return version;
    }

    Error get_error()
    {
        const char *description = nullptr;
        int error_code = glfwGetError(&description);
        if (error_code == GLFW_NO_ERROR)
            return Error(GLFW_NO_ERROR, {});
        else
            return Error(error_code, description);
    }

    std::string get_version_string() { return glfwGetVersionString(); }
    bool is_platform_supported(base::Int32 platform) { return glfwPlatformSupported(platform); }
    void init_hint(base::Int32 hint, base::Int32 value) { glfwInitHint(hint, value); }
    void init_allocator(GLFWallocator *allocator) { glfwInitAllocator(allocator); }

} // namespace glfw_wrapper
