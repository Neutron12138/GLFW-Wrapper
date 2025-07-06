#pragma once

#include <string>
#include <base/core/type.hpp>

namespace glfw_wrapper
{
    /// @brief GLFW错误
    class Error
    {
    public:
        /// @brief 错误码
        const base::Int32 error_code;
        /// @brief 描述
        const std::string description;

    public:
        inline Error(base::Int32 ec, const std::string &dsp)
            : error_code(ec), description(dsp) {}
        inline ~Error() = default;
    };

} // namespace glfw_wrapper
