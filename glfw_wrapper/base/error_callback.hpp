#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <base/core/noncopyable_object.hpp>
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
        static ErrorCallback &get_instance()
        {
            static ErrorCallback instance;
            return instance;
        }

    private:
        /// @brief 回调数组
        CallbackArray m_callbacks = {};

    private:
        inline ErrorCallback()
        {
            glfwSetErrorCallback(_error_callback);
            m_callbacks.push_back(Function(_default_error_callback));
        }

    public:
        inline ~ErrorCallback() { glfwSetErrorCallback(nullptr); }

    private:
        static inline void _error_callback(int error_code, const char *description)
        {
            for (auto &callback : get_instance().m_callbacks)
                callback(error_code, description);
        }

        static inline void _default_error_callback(int error_code, const char *description)
        {
            std::cout << "[GLFW Error]" << std::endl
                      << "error code: " << error_code << std::endl
                      << "description: " << description << std::endl;
        }

    public:
        inline const CallbackArray &get_callbacks() const { return m_callbacks; }

    public:
        template <typename F>
        inline void add_callback(F callback) { m_callbacks.push_back(Function(callback)); }
        inline void remove_callback(CallbackConstIterator iter) { m_callbacks.erase(iter); }
    };

} // namespace glfw_wrapper
