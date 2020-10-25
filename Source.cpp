#include "WindowManager.h"
#include "CameraManager.h"
#include "Basic2DRenderer.h"
#include "Basic2Dobject.h"

#include <vector>

#include <iostream>

int main()
{
	WindowManager* windowManager = new WindowManager(1024, 768, "GameEngine");
	CameraManager* cameraManager = new CameraManager(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	Basic2DRenderer* basic2DRenderer = new Basic2DRenderer("Basic2DvertexShader.txt", "Basic2DfragmentShader.txt");
	basic2DRenderer->Use();

	Basic2Dobject* triangle = new Basic2Dobject("Triangle");

	std::vector<float> vertices = {
		 500.5f,  500.5f, 0.0f,
		 100.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	std::vector<unsigned int> indices = {
		0, 1, 3,
		1, 2, 3
	};

	triangle->loadDataRAM(vertices, indices);
	while (!windowManager->shouldWindowClose())
	{
		windowManager->PreFrame();


		//Aici rendering.
		basic2DRenderer->Render(triangle->GetVaoID(), triangle->GetVboID(), triangle->GetEboID());
		//

		windowManager->PostFrame();

		std::cout << "FPS::" << 1.0f / windowManager->GetDeltaTime() << '\n';
	}

	delete triangle;
	delete basic2DRenderer;
	delete cameraManager;
	delete windowManager;

	glfwTerminate();

	return 0;
}