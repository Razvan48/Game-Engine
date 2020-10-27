#include "Basic3DRenderer.h"

Basic3DRenderer::Basic3DRenderer(std::string vertexShaderAdress, std::string fragmentShaderAdress)
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

    //glValidateProgram(this->programID);

    glEnable(GL_DEPTH_TEST);

    this->modelMatrixPath = glGetUniformLocation(this->programID, "modelMatrix");
    this->viewMatrixPath = glGetUniformLocation(this->programID, "viewMatrix");
    this->projectionMatrixPath = glGetUniformLocation(this->programID, "projectionMatrix");
}

Basic3DRenderer::~Basic3DRenderer()
{
    glDeleteShader(this->vertexShaderID);
    glDeleteShader(this->fragmentShaderID);
    glDeleteProgram(this->programID);
}

void Basic3DRenderer::Use()
{
    glUseProgram(this->programID);
}

void Basic3DRenderer::Render(Basic3DObject* object, CameraManager3D* camera)
{
    glBindVertexArray(object->GetVaoID());

    this->SetModelMatrix(glm::mat4(1.0f));
    this->SetViewMatrix(camera->GetViewMatrix());
    this->SetProjectionMatrix(camera->GetProjectionMatrix());

    glDrawElements(GL_TRIANGLES, object->GetVertexIndexSize(), GL_UNSIGNED_INT, 0);
}

void Basic3DRenderer::ActivateWireframeMode()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Basic3DRenderer::DeactivateWireframeMode()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Basic3DRenderer::ActivateDepthTesting()
{
    glEnable(GL_DEPTH_TEST);
}

void Basic3DRenderer::DeactivateDepthTesting()
{
    glDisable(GL_DEPTH_TEST);
}

void Basic3DRenderer::SetModelMatrix(glm::mat4 modelMatrix)
{
    glUniformMatrix4fv(this->modelMatrixPath, 1, GL_FALSE, glm::value_ptr(modelMatrix));
}

void Basic3DRenderer::SetViewMatrix(glm::mat4 viewMatrix)
{
    glUniformMatrix4fv(this->viewMatrixPath, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

void Basic3DRenderer::SetProjectionMatrix(glm::mat4 projectionMatrix)
{
    glUniformMatrix4fv(this->projectionMatrixPath, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
