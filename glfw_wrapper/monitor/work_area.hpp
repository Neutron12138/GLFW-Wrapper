#pragma once

#include <glm/glm.hpp>

namespace glfw_wrapper
{
    /// @brief 监视器的工作区域
    class WorkArea
    {
    public:
        /// @brief 位置
        const glm::ivec2 position;
        /// @brief 尺寸
        const glm::ivec2 size;

    public:
        WorkArea(const glm::ivec2 &pos, const glm::ivec2 &sz)
            : position(pos), size(sz) {}
        ~WorkArea() = default;
    };

} // namespace glfw_wrapper
