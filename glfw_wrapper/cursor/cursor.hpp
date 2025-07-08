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
        /// @brief GLFW光标句柄
        GLFWcursor *m_cursor = nullptr;

    public:
        inline Cursor() = default;
        Cursor(Cursor &&from) : m_cursor(from.m_cursor) { from.m_cursor = nullptr; }
        inline ~Cursor() override { destroy(); }

    public:
        Cursor &operator=(Cursor &&from);
        GLFWcursor *get_cursor() const { return m_cursor; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Cursor); }
        inline bool is_valid() const override { return m_cursor; }
        inline operator GLFWcursor *() const { return m_cursor; }

    public:
        inline void create(base::Int32 shape);
        inline void create(const GLFWimage *image, const glm::ivec2 &hot);
        inline void destroy();
    };

} // namespace glfw_wrapper
