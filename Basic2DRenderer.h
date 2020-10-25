#pragma once

#include <glew.h>
#include <fstream>
#include <string>

class Basic2DRenderer
{
private:
	int programID = 0;
	int vertexShaderID = 0;
	int fragmentShaderID = 0;

	std::string vertexShaderCode;
	std::string fragmentShaderCode;

public:
	Basic2DRenderer(const char* vertexShaderAdress, const char* fragmentShaderAdress);
	~Basic2DRenderer();

	void Use();
	void Render(unsigned int vaoID, unsigned int vboID, unsigned int eboID);
};

