#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>

class Window {
public:
    GLFWwindow* handle;
    int width;
    int height;

    Window(int w, int h, const char* title);

    bool isValid();
    bool shouldClose();
    void swapBuffers();
    void pollEvents();
    void close();
};