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

} // namespace glfw_wrapper
