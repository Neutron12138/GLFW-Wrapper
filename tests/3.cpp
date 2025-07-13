#include <iostream>
#include "../glfw_wrapper/glfw_wrapper.hpp"

class MyMainLoop : public glfw_wrapper::MainLoop
{
private:
    double total_time = 0.0;

protected:
    void _update(double delta) override
    {
        total_time += delta;
        if (total_time < 1.0)
            return;

        total_time -= 1.0;
        std::cout << "One second has passed" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    MyMainLoop app;
    app.run(argc, argv);
    return app.get_exit_code();
}
