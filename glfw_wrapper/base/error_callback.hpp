#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <base/misc/noncopyable_object.hpp>
#include "glfw.hpp"

namespace glfw_wrapper
{
    /// @brief GLFW错误回调管理器
    class ErrorCallback : public base::NoncopyableObject
    {
    public:
        using ErrorFunc = void(int error_code, const char *description);
        using Function = std::function<ErrorFunc>;
        using CallbackArray = std::vector<Function>;
        using CallbackConstIterator = CallbackArray::const_iterator;

        /// @brief 获取实例
        /// @return 实例
        static ErrorCallback &get_instance();

    private:
        /// @brief 回调数组
        CallbackArray m_callbacks;

    private:
        ErrorCallback();

    public:
        ~ErrorCallback();
        BASE_DELETE_COPY_FUNCTION(ErrorCallback);

    private:
        static void _error_callback(int error_code, const char *description);
        static void _default_error_callback(int error_code, const char *description);

    public:
        const CallbackArray &get_callbacks() const;

    public:
        template <typename F>
        void add_callback(F callback) { m_callbacks.push_back(Function(callback)); }
        void remove_callback(CallbackConstIterator iter);
    };

} // namespace glfw_wrapper
