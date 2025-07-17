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
        Cursor() = default;
        Cursor(base::Int32 shape);
        Cursor(const Image *image, const glm::ivec2 &hot);
        Cursor(Cursor &&from);
        ~Cursor() override;
        BASE_DELETE_COPY_FUNCTION(Cursor);

    public:
        Cursor &operator=(Cursor &&from);
        GLFWcursor *get_cursor() const;
        base::Int64 get_resource_type() const override;
        bool is_valid() const override;
        operator GLFWcursor *() const;

    public:
        void create(base::Int32 shape);
        void create(const Image *image, const glm::ivec2 &hot);
        void destroy();
    };

} // namespace glfw_wrapper
