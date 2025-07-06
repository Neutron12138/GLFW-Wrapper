#pragma once

#include <base/misc/resource.hpp>
#include "glfw.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Resource);

    /// @brief GLFW资源
    class Resource : public base::Resource
    {
    public:
        /// @brief 资源类型
        enum class ResourceType : base::Int64
        {
            /// @brief 无
            None,
            /// @brief 窗口
            Window,
            /// @brief 光标
            Cursor,
        };

    public:
        Resource() = default;
        ~Resource() override = default;
    };

} // namespace glfw_wrapper
