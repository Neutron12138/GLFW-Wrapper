#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

class MyMainLoop : public glfw_wrapper::MainLoop
{
private:
    double total_time = 0.0;

private:
    void _on_window_closed()
    {
        std::cout << "window closed" << std::endl;
    }

protected:
    void _initialize() override
    {
        m_window.window_close_callback = [&]()
        { _on_window_closed(); };
    }

    void _update(double delta) override
    {
        total_time += delta;
        if (total_time < 1.0)
            return;

        total_time -= 1.0;
        std::cout << "One second has passed" << std::endl;
    }

public:
    MyMainLoop()
    {
        m_initial_window_size = glm::ivec2(640, 480);
        m_initial_window_title = "test 3";
    }
};

int main(int argc, char *argv[])
{
    MyMainLoop app;
    app.run(argc, argv);
    return app.get_exit_code();
}
