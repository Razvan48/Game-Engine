#include "Basic2Dobject.h"

Basic2Dobject::Basic2Dobject(std::string name)
{
	this->name = name;

	glGenVertexArrays(1, &(this->vaoID));
	glGenBuffers(1, &(this->vboID));
	glGenBuffers(1, &(this->eboID));
}

Basic2Dobject::~Basic2Dobject()
{
	glDeleteVertexArrays(1, &(this->vaoID));
	glDeleteBuffers(1, &(this->vboID));
	glDeleteBuffers(1, &(this->eboID));
}

void Basic2Dobject::loadDataRAM(std::vector<float> vertexCoord, std::vector<unsigned int> vertexIndex)
{
	glBindVertexArray(this->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

	for (int i = 0; i < vertexCoord.size(); i++)
	{
		this->vertexCoord.push_back(vertexCoord[i]);
	}

	glBufferData(GL_ARRAY_BUFFER, (this->vertexCoord).size() * sizeof(float), &(this->vertexCoord), GL_STATIC_DRAW);

	for (int i = 0; i < vertexIndex.size(); i++)
	{
		this->vertexIndex.push_back(vertexIndex[i]);
	}

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (this->vertexIndex).size() * sizeof(unsigned int), &(this->vertexIndex), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//glBindVertexArray(0);
}

void Basic2Dobject::loadDataOBJ(std::string dataAdress)
{
	std::ifstream FIN(dataAdress);



	FIN.close();
}

unsigned int Basic2Dobject::GetVaoID()
{
	return this->vaoID;
}

unsigned int Basic2Dobject::GetVboID()
{
	return this->vboID;
}

unsigned int Basic2Dobject::GetEboID()
{
	return this->eboID;
}
