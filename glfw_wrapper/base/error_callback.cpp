#pragma once

#include "error_callback.hpp"

namespace glfw_wrapper
{
    ErrorCallback &ErrorCallback::get_instance()
    {
        static ErrorCallback instance;
        return instance;
    }

    ErrorCallback::ErrorCallback()
    {
        glfwSetErrorCallback(_error_callback);
        m_callbacks.push_back(Function(_default_error_callback));
    }

    ErrorCallback::~ErrorCallback() { glfwSetErrorCallback(nullptr); }

    void ErrorCallback::_error_callback(int error_code, const char *description)
    {
        for (auto &callback : get_instance().m_callbacks)
            callback(error_code, description);
    }

    void ErrorCallback::_default_error_callback(int error_code, const char *description)
    {
        std::cout << "[GLFW Error]" << std::endl
                  << "error code: " << error_code << std::endl
                  << "description: " << description << std::endl;
    }

    const ErrorCallback::CallbackArray &ErrorCallback::get_callbacks() const { return m_callbacks; }
    void ErrorCallback::remove_callback(CallbackConstIterator iter) { m_callbacks.erase(iter); }

} // namespace glfw_wrapper
