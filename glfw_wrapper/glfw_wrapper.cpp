#pragma once

#include "glfw_wrapper.hpp"

// base

#include "base/glfw.cpp"
#include "base/error_callback.cpp"
#include "base/context.cpp"

// cursor

#include "cursor/cursor.cpp"
#include "cursor/create_cursor.cpp"

// monitor

#include "monitor/monitor.cpp"

// window

#include "window/window.cpp"
#include "window/create_window.cpp"
#include "window/scoped_context.cpp"
#include "window/window_with_callback.cpp"
#include "window/create_window_with_callback.cpp"

// misc

#include "misc/main_loop.cpp"
