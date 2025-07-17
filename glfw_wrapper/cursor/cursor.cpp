#pragma once

#include "cursor.hpp"

namespace glfw_wrapper
{
    GLFWcursor *Cursor::create_cursor(int shape)
    {
        GLFWcursor *cursor = glfwCreateStandardCursor(shape);
        if (!cursor)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create GLFW cursor, shape: ", shape);

        return cursor;
    }

    GLFWcursor *Cursor::create_cursor(const GLFWimage *image, int xhot, int yhot)
    {
        GLFWcursor *cursor = glfwCreateCursor(image, xhot, yhot);
        if (!cursor)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create GLFW cursor\nimage: ", image,
                                          ", xhot: ", xhot,
                                          ", yhot: ", yhot);

        return cursor;
    }

    Cursor::Cursor(base::Int32 shape) { create(shape); }
    Cursor::Cursor(const Image *image, const glm::ivec2 &hot) { create(image, hot); }
    Cursor::Cursor(Cursor &&from) : m_cursor(std::exchange(from.m_cursor, nullptr)) {}
    Cursor::~Cursor() { destroy(); }

    Cursor &Cursor::operator=(Cursor &&from)
    {
        destroy();
        m_cursor = from.m_cursor;
        from.m_cursor = nullptr;
        return *this;
    }

    GLFWcursor *Cursor::get_cursor() const { return m_cursor; }
    base::Int64 Cursor::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Cursor); }
    bool Cursor::is_valid() const { return m_cursor; }
    Cursor::operator GLFWcursor *() const { return m_cursor; }

    void Cursor::create(base::Int32 shape)
    {
        destroy();
        m_cursor = create_cursor(shape);
    }

    void Cursor::create(const Image *image, const glm::ivec2 &hot)
    {
        destroy();
        m_cursor = create_cursor(image, hot.x, hot.y);
    }

    void Cursor::destroy()
    {
        if (m_cursor)
            glfwDestroyCursor(m_cursor);
        m_cursor = nullptr;
    }

} // namespace glfw_wrapper
