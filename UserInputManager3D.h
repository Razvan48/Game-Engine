#pragma once

#include "WindowManager.h"
#include "CameraManager3D.h"

#include <glew.h>
#include <glfw3.h>

class UserInputManager3D
{
private:

public:
	void UserInput(WindowManager* window, CameraManager3D* camera);

	UserInputManager3D();
	~UserInputManager3D();
};

