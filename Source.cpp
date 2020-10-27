#include "WindowManager.h"
#include "CameraManager3D.h"

#include "Basic2DRenderer.h"
#include "Basic2DObject.h"

#include "Basic3DRenderer.h"
#include "Basic3DObject.h"

#include "UserInputManager3D.h"

#include <vector>

#include <iostream>

int main()
{
	WindowManager* windowManager = new WindowManager(1024, 768, "GameEngine");
	CameraManager3D* cameraManager3D = new CameraManager3D(0.0f, 0.0f, 5.0f, windowManager->GetWidth(), windowManager->GetHeight());
	//Basic2DRenderer* basic2DRenderer = new Basic2DRenderer("Basic2DVertexShader.txt", "Basic2DFragmentShader.txt");
	//basic2DRenderer->ActivateWireframeMode();

	Basic3DRenderer* basic3DRenderer = new Basic3DRenderer("Basic3DVertexShader.txt", "Basic3DFragmentShader.txt");
	basic3DRenderer->ActivateWireframeMode();

	UserInputManager3D* userInputManager3D = new UserInputManager3D();

	/*
	Basic2DObject* triangle = new Basic2DObject("Triangle");

	std::vector<float> vertices = {
		 0.5f,  0.5f,
		 0.5f, -0.5f,
		-0.5f, -0.5f,
		-0.5f,  0.5f,
	};
	std::vector<unsigned int> indices = {
		0, 1, 3,
		1, 2, 3,
	};
	triangle->loadRAMData(vertices, indices);
	*/

	Basic3DObject* cube = new Basic3DObject("Cube");

	std::vector<float> vertices = {
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};

	std::vector<unsigned int> indices = {
		0, 1, 2
	};

	cube->loadOBJData("sphere.txt");
	//cube->loadRAMData(vertices, indices);

	while (!glfwWindowShouldClose(windowManager->GetWindow()))
	{
		windowManager->PreFrame();


		//Aici rendering.
		//basic2DRenderer->Use();
		//basic2DRenderer->Render(triangle);
		basic3DRenderer->Use();
		basic3DRenderer->Render(cube, cameraManager3D);

		//

		windowManager->PostFrame();
		userInputManager3D->UserInput(windowManager, cameraManager3D);
		std::cout << "FPS:: " << 1.0f / windowManager->GetDeltaTime() << '\n';
	}

	//delete triangle;
	//delete basic2DRenderer;

	delete cube;
	delete basic3DRenderer;

	delete cameraManager3D;
	delete windowManager;

	glfwTerminate();

	return 0;
}