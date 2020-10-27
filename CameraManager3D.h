#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class CameraManager3D
{
private:
	float fieldOfView = 45.0f;

	float nearClipPlane = 0.1f;
	float farClipPlane = 100.0f;

	float transSpeed = 10.0f;
	float rotSpeed = 5.0f;

	float MAX_VIEW_ANGLE = 89.0f;
	float xMouse = 0.0f;
	float yMouse = 0.0f;
	float mouseSenzitivity = 5.0f;

	float xAngle = -90.0f;
	float yAngle = 0.0f;

	glm::vec3 cameraPos;
	glm::vec3 viewDir;
	glm::vec3 normalDir;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;

	int width;
	int height;

	void ResetProjectionMatrix();
	void ResetViewMatrix();

public:
	//CameraManager3D(float x, float y, float z, float xView, float yView, float zView, float xNormal, float yNormal, float zNormal, int width, int height);
	CameraManager3D(float x, float y, float z, int width, int height);
	~CameraManager3D();

	void SetFieldOfView(float fieldOfView);
	void SetNearClipPlane(float nearClipPlane);
	void SetFarClipPlane(float farClipPlane);

	float GetX();
	float GetY();
	float GetZ();

	float GetXView();
	float GetYView();
	float GetZView();

	glm::vec3 GetCameraPos();
	glm::vec3 GetViewDir();
	glm::vec3 GetNormalDir();

	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetViewMatrix();

	void Translate(float dx, float dy, float dz);
	void Translate(glm::vec3 translation);

	float GetTransSpeed();

	void SetTransSpeed(float transSpeed);
	void SetRotSpeed(float rotSpeed);

	void SetViewDir(glm::vec3 viewDir);

	float GetXMouse();
	float GetYMouse();

	float GetMouseSenzitivity();
	float GetMaxViewAngle();

	void SetMouseSenzitivity(float mouseSenzitivity);
	void SetMaxViewAngle(float MAX_VIEW_ANGLE);

	void SetXMouse(float xMouse);
	void SetYMouse(float yMouse);

	float GetXAngle();
	float GetYAngle();

	void ModifyXAngle(float dxAngle);
	void ModifyYAngle(float dyAngle);

	void SetXAngle(float xAngle);
	void SetYAngle(float yAngle);
};

