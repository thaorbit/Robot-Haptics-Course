#include "Window.h"
#include <iostream>
using namespace std;

Window::Window(int w, int h, const char* title) {
    width = w;
    height = h;
    handle = nullptr;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!handle) {
        cout << "Tao cua so that bai" <<endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(handle);
    glfwSwapInterval(1);
    glfwShowWindow(handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Tao GLAD that bai" <<endl;
        handle = nullptr;
        return;
    }

    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
}

bool Window::isValid() {
    return handle != nullptr;
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(handle);
}

void Window::swapBuffers() {
    glfwSwapBuffers(handle);
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::close() {
    glfwTerminate();
}