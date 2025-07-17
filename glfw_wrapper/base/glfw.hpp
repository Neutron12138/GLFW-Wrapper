#pragma once

#ifdef GLFW_WRAPPER_USE_VULKAN
#include <vulkan/vulkan.h>
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
    using VideoMode = GLFWvidmode;
    using GammaRamp = GLFWgammaramp;
    using Image = GLFWimage;

    glm::ivec3 get_version();
    Error get_error();

    std::string get_version_string();
    bool is_platform_supported(base::Int32 platform);
    void init_hint(base::Int32 hint, base::Int32 value);
    void init_allocator(GLFWallocator *allocator);

} // namespace glfw_wrapper
