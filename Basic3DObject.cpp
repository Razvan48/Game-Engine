#include "Basic3DObject.h"

Basic3DObject::Basic3DObject(std::string name)
{
	this->name = name;

	glGenVertexArrays(1, &this->vaoID);
	glGenBuffers(1, &this->vboID);
	glGenBuffers(1, &this->eboID);
}

Basic3DObject::~Basic3DObject()
{
	glDeleteBuffers(1, &this->vboID);
	glDeleteBuffers(1, &this->eboID);
	glDeleteVertexArrays(1, &this->vaoID);
}

void Basic3DObject::loadRAMData(std::vector<float> vertexCoord, std::vector<unsigned int> vertexIndex)
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Basic3DObject::loadOBJData(std::string dataAdress)
{
	glBindVertexArray(this->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, this->vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboID);

	std::ifstream FIN(dataAdress);

	while (!FIN.eof())
	{
		std::string line;

		getline(FIN, line);

		if (line[0] == 'v')
		{
			std::strstream input;
			input << line;

			char junk;

			input >> junk;

			float coord;
			
			for (int i = 0; i < 3; i++)
			{
				input >> coord;
				this->vertexCoord.push_back(coord);
			}
		}
		else if (line[0] == 'f')
		{
			std::strstream input;
			input << line;

			char junk;

			input >> junk;

			unsigned int index;

			for (int i = 0; i < 3; i++)
			{
				input >> index;
				this->vertexIndex.push_back(index - 1);
			}
		}
	}

	FIN.close();

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->vertexCoord.size(), &this->vertexCoord[0], GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * this->vertexIndex.size(), &this->vertexIndex[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

unsigned int Basic3DObject::GetVaoID()
{
	return this->vaoID;
}

int Basic3DObject::GetVertexIndexSize()
{
	return this->vertexIndex.size();
}
