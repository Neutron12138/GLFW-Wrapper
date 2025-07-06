#pragma once

#include "../base/resource.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Cursor);

    /// @brief GLFW光标
    class Cursor : public Resource
    {
    public:
        static GLFWcursor *create_cursor(int shape);
        static GLFWcursor *create_cursor(const GLFWimage *image, int xhot, int yhot);

    private:
        GLFWcursor *m_cursor;

    public:
        inline Cursor(base::Int32 shape)
        {
            m_cursor = create_cursor(shape);
        }

        inline Cursor(const GLFWimage *image, const glm::ivec2 &hot)
        {
            m_cursor = create_cursor(image, hot.x, hot.y);
        }

        inline ~Cursor() override
        {
            glfwDestroyCursor(m_cursor);
            m_cursor = nullptr;
        }

    public:
        GLFWcursor *get_cursor() const { return m_cursor; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Cursor); }
    };

} // namespace glfw_wrapper
