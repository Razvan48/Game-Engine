#include "WindowManager.h"


void WindowManager::FramebufferSizeCallback(GLFWwindow* window, int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
}

WindowManager::WindowManager(int width, int height, const char* title)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->width = width;
    this->height = height;
    this->title = title;
    this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
    //glfwGetPrimaryMonitor();

    glfwMakeContextCurrent(this->window);

    glfwSetTime(this->currentTime);

    glewInit();

    //glfwSetFramebufferSizeCallback(this->window, std::bind(&WindowManager::FramebufferSizeCallback, this, std::placeholders::_1));
    glfwSetFramebufferSizeCallback(this->window, WindowManager::FramebufferSizeCallback);
}

WindowManager::~WindowManager()
{
    glfwDestroyWindow(this->window);
}

void WindowManager::PreFrame()
{
    this->previousTime = this->currentTime;
    this->currentTime = glfwGetTime();
    this->deltaTime = this->currentTime - this->previousTime;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void WindowManager::PostFrame()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void WindowManager::SetBackgroundColor(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
}

bool WindowManager::shouldWindowClose()
{
    return glfwWindowShouldClose(this->window);
}

GLFWwindow* WindowManager::GetWindow()
{
    return this->window;
}

float WindowManager::GetDeltaTime()
{
    return this->deltaTime;
}
