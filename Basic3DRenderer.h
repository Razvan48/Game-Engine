#pragma once

#include <glew.h>
#include <fstream>
#include <string>

#include "Basic3DObject.h"
#include "CameraManager3D.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Basic3DRenderer
{
private:
	int programID;
	int vertexShaderID;
	int fragmentShaderID;

	std::string vertexShaderCode;
	std::string fragmentShaderCode;

	int modelMatrixPath = 0;
	int viewMatrixPath = 0;
	int projectionMatrixPath = 0;

public:
	Basic3DRenderer(std::string vertexShaderAdress, std::string fragmentShaderAdress);
	~Basic3DRenderer();

	void Use();
	void Render(Basic3DObject* object, CameraManager3D* camera);

	void ActivateWireframeMode();
	void DeactivateWireframeMode();

	void ActivateDepthTesting();
	void DeactivateDepthTesting();

	void SetModelMatrix(glm::mat4 modelMatrix);
	void SetViewMatrix(glm::mat4 viewMatrix);
	void SetProjectionMatrix(glm::mat4 projectionMatrix);
};