#pragma once

#include <glew.h>
#include <glfw3.h>
#pragma once

#include <functional>

class WindowManager
{
private:
	int width;
	int height;
	const char* title;
	GLFWwindow* window;

	float currentTime = 0.0f;
	float previousTime = 0.0f;
	float deltaTime = 0.0f;
	//float previousTime;
	//float deltaTime;

	//void FramebufferSizeCallback(GLFWwindow* window, int newWidth, int newHeight);
	static void FramebufferSizeCallback(GLFWwindow* window, int newWidth, int newHeight);

public:
	WindowManager(int width, int height, const char* title);
	~WindowManager();

	void PreFrame();
	void PostFrame();

	void SetBackgroundColor(float red, float green, float blue, float alpha);

	bool shouldWindowClose();

	float GetDeltaTime();

	GLFWwindow* GetWindow();

	int GetWidth();
	int GetHeight();

	void BlockMouse();
	void UnblockMouse();
};

