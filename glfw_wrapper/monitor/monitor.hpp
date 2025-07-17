#pragma once

#include <vector>
#include <base/core/ref.hpp>
#include <base/core/exception.hpp>
#include "../base/glfw.hpp"
#include "work_area.hpp"

namespace glfw_wrapper
{
    BASE_DECLARE_REF_TYPE(Monitor);

    /// @brief GLFW监视器对象
    class Monitor
    {
    public:
        static Monitor get_primary();
        static std::vector<Monitor> get_monitors();
        static GLFWmonitorfun set_callback(GLFWmonitorfun func);

    private:
        /// @brief GLFW监视器句柄
        GLFWmonitor *m_monitor = nullptr;

    public:
        Monitor() = default;
        Monitor(GLFWmonitor *monitor);
        Monitor(const Monitor &another);
        ~Monitor() = default;

    public:
        Monitor &operator=(GLFWmonitor *monitor);
        Monitor &operator=(const Monitor &another);
        GLFWmonitor *get_monitor() const;
        operator GLFWmonitor *() const;
        bool is_valid() const;

    public:
        std::vector<VideoMode> get_video_modes() const;
        glm::ivec2 get_physical_size() const;
        glm::vec2 get_content_scale() const;
        glm::ivec2 get_position() const;
        WorkArea get_work_area() const;

        VideoMode get_video_mode() const;
        std::string get_name() const;
        void *get_user_pointer() const;
        GammaRamp get_gamma_ramp() const;

        void set_user_pointer(void *pointer);
        void set_gamma_ramp(const GammaRamp *ramp);
        void set_gamma(float gamma);
    };

} // namespace glfw_wrapper
