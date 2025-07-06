#pragma once

#ifdef GLFW_WRAPPER_USE_VULKAN
#include <vulkan/vulkan.hpp>
#else
#define GLFW_INCLUDE_NONE
#endif

#include <string>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "error.hpp"

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

    inline std::string get_version_string() { return glfwGetVersionString(); }
    inline bool is_platform_supported(base::Int32 platform) { return glfwPlatformSupported(platform); }
    inline void init_hint(base::Int32 hint, base::Int32 value) { glfwInitHint(hint, value); }
    inline void init_allocator(GLFWallocator *allocator) { glfwInitAllocator(allocator); }

} // namespace glfw_wrapper
