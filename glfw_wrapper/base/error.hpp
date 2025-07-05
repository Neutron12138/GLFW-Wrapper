#pragma once

#include <string>
#include <base/core/type.hpp>

namespace glfw_wrapper
{
    /// @brief GLFW错误
    class Error
    {
    private:
        /// @brief 错误码
        ::base::Int32 m_error_code;
        /// @brief 描述
        std::string m_description;

    public:
        inline Error(::base::Int32 error_code, std::string &&description)
            : m_error_code(error_code), m_description(description) {}
        inline ~Error() = default;

    public:
        bool has_error() const { return m_error_code != 0; }
        ::base::Int32 get_error_code() const { return m_error_code; }
        const std::string &get_description() const { return m_description; }
    };

} // namespace glfw_wrapper
