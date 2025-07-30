#pragma once

#include <base/version.hpp>

// base

#include "base/error.hpp"
#include "base/glfw.hpp"
#include "base/enums.hpp"
#include "base/error_callback.hpp"
#include "base/context.hpp"

// cursor

#include "cursor/cursor.hpp"

// monitor

#include "monitor/work_area.hpp"
#include "monitor/monitor.hpp"

// window

#include "window/window.hpp"
#include "window/scoped_context.hpp"
#include "window/window_with_callback.hpp"

// misc

#include "misc/main_loop.hpp"

// implementation

#ifdef GLFW_WRAPPER_INCLUDE_IMPL
#include "glfw_wrapper.cpp"
#endif
