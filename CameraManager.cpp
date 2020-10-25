#include "CameraManager.h"

CameraManager::CameraManager(float x, float y, float z, float xRot, float yRot, float zRot)
{
	this->x = x;
	this->y = y;
	this->z = z;

	this->xRot = xRot;
	this->yRot = yRot;
	this->zRot = zRot;
}

CameraManager::~CameraManager()
{

}

float CameraManager::GetX()
{
	return this->x;
}

float CameraManager::GetY()
{
	return this->y;
}

float CameraManager::GetZ()
{
	return this->z;
}

float CameraManager::GetXRot()
{
	return this->xRot;
}

float CameraManager::GetYRot()
{
	return this->yRot;
}

float CameraManager::GetZRot()
{
	return this->zRot;
}
