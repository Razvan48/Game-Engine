#pragma once

#include <glew.h>
#include <fstream>
#include <string>

#include "Basic2DObject.h"

class Basic2DRenderer
{
private:
	int programID;
	int vertexShaderID;
	int fragmentShaderID;

	std::string vertexShaderCode;
	std::string fragmentShaderCode;

public:
	Basic2DRenderer(std::string vertexShaderAdress, std::string fragmentShaderAdress);
	~Basic2DRenderer();

	void Use();
	void Render(Basic2DObject* object);

	void ActivateWireframeMode();
	void DeactivateWireframeMode();
};

