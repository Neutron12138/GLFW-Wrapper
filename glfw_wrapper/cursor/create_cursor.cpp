#pragma once

#include "cursor.hpp"

namespace glfw_wrapper
{
    Cursor create_cursor(Cursor::Shape shape)
    {
        Cursor cursor;
        cursor.create(shape);
        return cursor;
    }

    Cursor create_cursor(const Image *image, const glm::ivec2 &hot)
    {
        Cursor cursor;
        cursor.create(image, hot);
        return cursor;
    }

    CursorRef create_cursor_shared(Cursor::Shape shape)
    {
        CursorRef cursor = std::make_shared<Cursor>();
        cursor->create(shape);
        return cursor;
    }

    CursorRef create_cursor_shared(const Image *image, const glm::ivec2 &hot)
    {
        CursorRef cursor = std::make_shared<Cursor>();
        cursor->create(image, hot);
        return cursor;
    }

    CursorUniqueRef create_cursor_unique(Cursor::Shape shape)
    {
        CursorUniqueRef cursor = std::make_unique<Cursor>();
        cursor->create(shape);
        return cursor;
    }

    CursorUniqueRef create_cursor_unique(const Image *image, const glm::ivec2 &hot)
    {
        CursorUniqueRef cursor = std::make_unique<Cursor>();
        cursor->create(image, hot);
        return cursor;
    }

} // namespace glfw_wrapper
