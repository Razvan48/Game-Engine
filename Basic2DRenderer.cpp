#include "Basic2DRenderer.h"

Basic2DRenderer::Basic2DRenderer(const char* vertexShaderAdress, const char* fragmentShaderAdress)
{
    this->vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    this->fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    std::string line;

    std::ifstream vertexFIN(vertexShaderAdress);

    while (!vertexFIN.eof())
    {
        getline(vertexFIN, line);

        this->vertexShaderCode += line;
        this->vertexShaderCode += "\n";
    }

    this->vertexShaderCode += "\0";

    vertexFIN.close();

    std::ifstream fragmentFIN(fragmentShaderAdress);

    while (!fragmentFIN.eof())
    {
        std::getline(fragmentFIN, line);

        this->fragmentShaderCode += line;
        this->fragmentShaderCode += "\n";
    }

    this->fragmentShaderCode += "\0";

    fragmentFIN.close();

    const char* vertexCstr = (this->vertexShaderCode).c_str();
    const char* fragmentCstr = (this->fragmentShaderCode).c_str();

    glShaderSource(this->vertexShaderID, 1, &vertexCstr, 0);
    glShaderSource(this->fragmentShaderID, 1, &fragmentCstr, 0);

    glCompileShader(this->vertexShaderID);
    glCompileShader(this->fragmentShaderID);

    this->programID = glCreateProgram();
    glAttachShader(this->programID, this->vertexShaderID);
    glAttachShader(this->programID, this->fragmentShaderID);

    glLinkProgram(this->programID);

    glValidateProgram(this->programID);
}

Basic2DRenderer::~Basic2DRenderer()
{
    glDeleteShader(this->vertexShaderID);
    glDeleteShader(this->fragmentShaderID);
    glDeleteProgram(this->programID);
}

void Basic2DRenderer::Use()
{
    glUseProgram(this->programID);
}

void Basic2DRenderer::Render(unsigned int vaoID, unsigned int vboID, unsigned int eboID)
{
    glBindVertexArray(vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    //glBindVertexArray(0);
}
