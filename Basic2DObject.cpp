#include "Basic2DObject.h"

Basic2DObject::Basic2DObject(std::string name)
{
	this->name = name;

	glGenVertexArrays(1, &this->vaoID);
	glGenBuffers(1, &this->vboID);
	glGenBuffers(1, &this->eboID);
}

Basic2DObject::~Basic2DObject()
{
	glDeleteBuffers(1, &this->vboID);
	glDeleteBuffers(1, &this->eboID);
	glDeleteVertexArrays(1, &this->vaoID);
}

void Basic2DObject::loadRAMData(std::vector<float> vertexCoord, std::vector<unsigned int> vertexIndex)
{
	glBindVertexArray(this->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

	for (int i = 0; i < vertexCoord.size(); i++)
	{
		this->vertexCoord.push_back(vertexCoord[i]);
	}

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->vertexCoord.size(), &this->vertexCoord[0], GL_STATIC_DRAW);

	for (int i = 0; i < vertexIndex.size(); i++)
	{
		this->vertexIndex.push_back(vertexIndex[i]);
	}

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * this->vertexIndex.size(), &this->vertexIndex[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

/*Nu e scris, trb scris candva :(
void Basic2DObject::loadOBJData(std::string dataAdress)
{
	std::ifstream FIN(dataAdress);



	FIN.close();
}
//*/

unsigned int Basic2DObject::GetVaoID()
{
	return this->vaoID;
}

int Basic2DObject::GetVertexIndexSize()
{
	return this->vertexIndex.size();
}
