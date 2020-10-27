#include "UserInputManager3D.h"

void UserInputManager3D::UserInput(WindowManager* window, CameraManager3D* camera)
{
    if (glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window->GetWindow(), 1);
    }

    if (glfwGetKey(window->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
    {
        camera->Translate(camera->GetViewDir() * camera->GetTransSpeed() * window->GetDeltaTime());
    }
    if (glfwGetKey(window->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
    {
        camera->Translate(-camera->GetViewDir() * camera->GetTransSpeed() * window->GetDeltaTime());
    }
    if (glfwGetKey(window->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
    {
        camera->Translate(-glm::normalize(glm::cross(camera->GetViewDir(), camera->GetNormalDir()) * camera->GetTransSpeed() * window->GetDeltaTime()));
    }
    if (glfwGetKey(window->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
    {
        camera->Translate(glm::normalize(glm::cross(camera->GetViewDir(), camera->GetNormalDir()) * camera->GetTransSpeed() * window->GetDeltaTime()));
    }

    double newX;
    double newY;
    glfwGetCursorPos(window->GetWindow(), &newX, &newY);

    float dx = 1.0f * newX - camera->GetXMouse();
    float dy = 1.0f * newY - camera->GetYMouse();

    camera->SetXMouse(1.0f * newX);
    camera->SetYMouse(1.0f * newY);

    dx *= camera->GetMouseSenzitivity();
    dy *= camera->GetMouseSenzitivity();

    dx *= window->GetDeltaTime();
    dy *= window->GetDeltaTime();

    camera->ModifyXAngle(dx);
    camera->ModifyYAngle(-dy);

    if (camera->GetYAngle() > camera->GetMaxViewAngle())
    {
        camera->SetYAngle(camera->GetMaxViewAngle());
    }
    if (camera->GetYAngle() < -camera->GetMaxViewAngle())
    {
        camera->SetYAngle(-camera->GetMaxViewAngle());
    }

    glm::vec3 newViewDir;
    newViewDir.x = cos(glm::radians(camera->GetXAngle())) * cos(glm::radians(camera->GetYAngle()));
    newViewDir.y = sin(glm::radians(camera->GetYAngle()));
    newViewDir.z = sin(glm::radians(camera->GetXAngle())) * cos(glm::radians(camera->GetYAngle()));

    camera->SetViewDir(newViewDir);
}

UserInputManager3D::UserInputManager3D()
{
}

UserInputManager3D::~UserInputManager3D()
{

}
