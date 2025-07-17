#pragma once

#include "window.hpp"

namespace glfw_wrapper
{
    /// @brief 作用域内自动切换上下文
    class ScopedContext : public base::NoncopyableObject
    {
    private:
        /// @brief 先前的上下文窗口（可以为空）
        Window *m_previous;
        /// @brief 新绑定的上下文窗口
        Window *m_current;

    public:
        ScopedContext(Window *current);
        ScopedContext(Window *current, Window *previous);
        ~ScopedContext();
    };

} // namespace glfw_wrapper
