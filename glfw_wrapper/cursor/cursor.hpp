#pragma once

#include "../base/resource.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Cursor);

    /// @brief GLFW光标
    class Cursor : public Resource
    {
    public:
        /// @brief 光标形状
        enum class Shape : base::Int32
        {
            Arrow = GLFW_ARROW_CURSOR,
            IBeam = GLFW_IBEAM_CURSOR,
            Crosshair = GLFW_CROSSHAIR_CURSOR,
            PointingHand = GLFW_POINTING_HAND_CURSOR,
            ResizeEW = GLFW_RESIZE_EW_CURSOR,
            ResizeNS = GLFW_RESIZE_NS_CURSOR,
            ResizeNWSE = GLFW_RESIZE_NWSE_CURSOR,
            ResizeNESW = GLFW_RESIZE_NESW_CURSOR,
            ResizeAll = GLFW_RESIZE_ALL_CURSOR,
            NotAllowed = GLFW_NOT_ALLOWED_CURSOR,
            HResize = GLFW_HRESIZE_CURSOR,
            VResize = GLFW_VRESIZE_CURSOR,
            Hand = GLFW_HAND_CURSOR,
        };

        static GLFWcursor *create_glfw_cursor(int shape);
        static GLFWcursor *create_glfw_cursor(const GLFWimage *image, int xhot, int yhot);

    private:
        /// @brief GLFW光标句柄
        GLFWcursor *m_cursor = nullptr;

    public:
        Cursor() = default;
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
        void create(Shape shape);
        void create(const Image *image, const glm::ivec2 &hot);
        void destroy();
    };

    Cursor create_cursor(Cursor::Shape shape);
    Cursor create_cursor(const Image *image, const glm::ivec2 &hot);

    CursorRef create_cursor_shared(Cursor::Shape shape);
    CursorRef create_cursor_shared(const Image *image, const glm::ivec2 &hot);

    CursorUniqueRef create_cursor_unique(Cursor::Shape shape);
    CursorUniqueRef create_cursor_unique(const Image *image, const glm::ivec2 &hot);

} // namespace glfw_wrapper
