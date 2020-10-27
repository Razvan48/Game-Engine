#include "Basic2DRenderer.h"

Basic2DRenderer::Basic2DRenderer(std::string vertexShaderAdress, std::string fragmentShaderAdress)
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
        getline(fragmentFIN, line);

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

    //glValidateProgram(this->programID);
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

void Basic2DRenderer::Render(Basic2DObject* object)
{
    glBindVertexArray(object->GetVaoID());

    glDrawElements(GL_TRIANGLES, object->GetVertexIndexSize(), GL_UNSIGNED_INT, 0);
}

void Basic2DRenderer::ActivateWireframeMode()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Basic2DRenderer::DeactivateWireframeMode()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
