@echo off

echo ----------Compling----------
g++ -finput-charset=utf-8 -fexec-charset=gbk "../glfw_wrapper/dll_main.cpp"^
    -o "glfw_wrapper.dll" -lopengl32 -lglfw3 -lgdi32 -shared

echo ----------End----------
pause
