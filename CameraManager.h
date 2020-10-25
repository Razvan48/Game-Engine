#pragma once

class CameraManager
{
private:
	float x;
	float y;
	float z;

	float xRot;
	float yRot;
	float zRot;

public:
	CameraManager(float x, float y, float z, float xRot, float yRot, float zRot);
	~CameraManager();

	float GetX();
	float GetY();
	float GetZ();

	float GetXRot();
	float GetYRot();
	float GetZRot();
};

