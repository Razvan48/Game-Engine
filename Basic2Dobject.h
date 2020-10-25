#pragma once

#include <fstream>
#include <string>
#include <vector>

#include <glew.h>

class Basic2Dobject
{
private:
	std::string name;
	std::vector<float> vertexCoord;
	std::vector<unsigned int> vertexIndex;

	unsigned int vaoID;
	unsigned int vboID;

	unsigned int eboID;

public:
	Basic2Dobject(std::string name);
	~Basic2Dobject();

	void loadDataRAM(std::vector<float> vertexCoord, std::vector<unsigned int> vertexIndex);
	void loadDataOBJ(std::string dataAdress);

	unsigned int GetVaoID();
	unsigned int GetVboID();
	unsigned int GetEboID();
};

