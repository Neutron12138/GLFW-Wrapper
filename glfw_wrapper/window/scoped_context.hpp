#pragma once

#include "window.hpp"

namespace glfw_wrapper
{
    /// @brief 作用域内自动切换上下文
    class ScopedContext : public base::NoncopyableObject
    {
    private:
        /// @brief 先前的上下文窗口（可以为空）
        WindowRef m_previous;
        /// @brief 新绑定的上下文窗口
        WindowRef m_current;

    public:
        ScopedContext(const WindowRef &current)
            : m_current(current)
        {
            if (!m_current)
                throw BASE_MAKE_RUNTIME_ERROR("The newly bound context window cannot be a null pointer");

            m_current->make_context_current();
        }

        ScopedContext(const WindowRef &current, const WindowRef &previous)
            : m_current(current), m_previous(previous)
        {
            if (!m_current)
                throw BASE_MAKE_RUNTIME_ERROR("The newly bound context window cannot be a null pointer");

            m_current->make_context_current();
        }

        ~ScopedContext()
        {
            if (m_previous)
                m_previous->make_context_current();
            else
                glfwMakeContextCurrent(nullptr);
        }
    };

} // namespace glfw_wrapper
