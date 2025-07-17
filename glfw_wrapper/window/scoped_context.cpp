#pragma once

#include "scoped_context.hpp"

namespace glfw_wrapper
{
    ScopedContext::ScopedContext(Window *current)
        : m_current(current)
    {
        if (m_current)
            m_current->make_context_current();
        else
            glfwMakeContextCurrent(nullptr);
    }

    ScopedContext::ScopedContext(Window *current, Window *previous)
        : m_current(current), m_previous(previous)
    {
        if (m_current)
            m_current->make_context_current();
        else
            glfwMakeContextCurrent(nullptr);
    }

    ScopedContext::~ScopedContext()
    {
        if (m_previous)
            m_previous->make_context_current();
        else
            glfwMakeContextCurrent(nullptr);
    }

} // namespace glfw_wrapper
