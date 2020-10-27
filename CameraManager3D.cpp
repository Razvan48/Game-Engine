#include "CameraManager3D.h"

void CameraManager3D::ResetProjectionMatrix()
{
	this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView), 1.0f * this->width / this->height, this->nearClipPlane, this->farClipPlane);
}

void CameraManager3D::ResetViewMatrix()
{
	this->viewMatrix = glm::lookAt(this->cameraPos, cameraPos + viewDir, normalDir);
}

/*
CameraManager3D::CameraManager3D(float x, float y, float z, float xView, float yView, float zView, float xNormal, float yNormal, float zNormal, int width, int height)
{
	this->cameraPos = glm::normalize(glm::vec3(x, y, z));
	this->viewDir = glm::normalize(glm::vec3(xView, yView, zView));
	this->normalDir = glm::normalize(glm::vec3(xNormal, yNormal, zNormal));

	this->width = width;
	this->height = height;

	this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView), 1.0f * this->width / this->height, this->nearClipPlane, this->farClipPlane);
	this->viewMatrix = glm::lookAt(this->cameraPos, cameraPos + viewDir, normalDir);
}
*/

CameraManager3D::CameraManager3D(float x, float y, float z, int width, int height)
{
	this->cameraPos = glm::normalize(glm::vec3(x, y, z));
	this->viewDir = glm::normalize(glm::vec3(0.0f, 0.0f, -5.0f));
	this->normalDir = glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f));

	this->width = width;
	this->height = height;

	this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView), 1.0f * this->width / this->height, this->nearClipPlane, this->farClipPlane);
}

CameraManager3D::~CameraManager3D()
{

}

void CameraManager3D::SetFieldOfView(float fieldOfView)
{
	this->fieldOfView = fieldOfView;
	CameraManager3D::ResetProjectionMatrix();
}

void CameraManager3D::SetNearClipPlane(float nearClipPlane)
{
	this->nearClipPlane = nearClipPlane;
	CameraManager3D::ResetProjectionMatrix();
}

void CameraManager3D::SetFarClipPlane(float farClipPlane)
{
	this->farClipPlane = farClipPlane;
	CameraManager3D::ResetProjectionMatrix();
}

float CameraManager3D::GetX()
{
	return this->cameraPos.x;
}

float CameraManager3D::GetY()
{
	return this->cameraPos.y;
}

float CameraManager3D::GetZ()
{
	return this->cameraPos.z;
}

float CameraManager3D::GetXView()
{
	return this->viewDir.x;
}

float CameraManager3D::GetYView()
{
	return this->viewDir.y;
}

float CameraManager3D::GetZView()
{
	return this->viewDir.z;
}

glm::vec3 CameraManager3D::GetCameraPos()
{
	return this->cameraPos;
}

glm::vec3 CameraManager3D::GetViewDir()
{
	return this->viewDir;
}

glm::vec3 CameraManager3D::GetNormalDir()
{
	return this->normalDir;
}

glm::mat4 CameraManager3D::GetProjectionMatrix()
{
	return this->projectionMatrix;
}

glm::mat4 CameraManager3D::GetViewMatrix()
{
	return this->viewMatrix;
}

void CameraManager3D::Translate(float x, float y, float z)
{
	this->cameraPos.x += x;
	this->cameraPos.y += y;
	this->cameraPos.z += z;

	CameraManager3D::ResetViewMatrix();
}

void CameraManager3D::Translate(glm::vec3 translation)
{
	this->cameraPos += translation;

	CameraManager3D::ResetViewMatrix();
}

float CameraManager3D::GetTransSpeed()
{
	return this->transSpeed;
}

void CameraManager3D::SetTransSpeed(float transSpeed)
{
	this->transSpeed = transSpeed;
}

void CameraManager3D::SetRotSpeed(float rotSpeed)
{
	this->rotSpeed = rotSpeed;
}

void CameraManager3D::SetViewDir(glm::vec3 viewDir)
{
	this->viewDir = glm::normalize(viewDir);

	this->ResetViewMatrix();
}

float CameraManager3D::GetXMouse()
{
	return this->xMouse;
}

float CameraManager3D::GetYMouse()
{
	return this->yMouse;
}

float CameraManager3D::GetMouseSenzitivity()
{
	return this->mouseSenzitivity;
}

float CameraManager3D::GetMaxViewAngle()
{
	return this->MAX_VIEW_ANGLE;
}

void CameraManager3D::SetMouseSenzitivity(float mouseSenzitivity)
{
	this->mouseSenzitivity = mouseSenzitivity;
}

void CameraManager3D::SetMaxViewAngle(float MAX_VIEW_ANGLE)
{
	this->MAX_VIEW_ANGLE = MAX_VIEW_ANGLE;
}

void CameraManager3D::SetXMouse(float xMouse)
{
	this->xMouse = xMouse;
}

void CameraManager3D::SetYMouse(float yMouse)
{
	this->yMouse = yMouse;
}

float CameraManager3D::GetXAngle()
{
	return this->xAngle;
}

float CameraManager3D::GetYAngle()
{
	return this->yAngle;
}

void CameraManager3D::ModifyXAngle(float dxAngle)
{
	this->xAngle += dxAngle;
}

void CameraManager3D::ModifyYAngle(float dyAngle)
{
	this->yAngle += dyAngle;
}

void CameraManager3D::SetXAngle(float xAngle)
{
	this->xAngle = xAngle;
}

void CameraManager3D::SetYAngle(float yAngle)
{
	this->yAngle = yAngle;
}
