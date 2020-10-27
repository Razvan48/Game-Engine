#pragma once

#include <fstream>
#include <string>
#include <vector>

#include <glew.h>
#include <strstream>

class Basic3DObject
{
private:
	std::string name;
	std::vector<float> vertexCoord;
	std::vector<unsigned int> vertexIndex;

	unsigned int vaoID;
	unsigned int vboID;
	unsigned int eboID;

public:
	Basic3DObject(std::string name);
	~Basic3DObject();

	void loadRAMData(std::vector<float> vertexCoord, std::vector<unsigned int> vertexIndex);
	void loadOBJData(std::string dataAdress);

	unsigned int GetVaoID();
	int GetVertexIndexSize();
};

