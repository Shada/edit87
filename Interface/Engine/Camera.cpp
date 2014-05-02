#include "Camera.h"

Camera::Camera(int width, int height, elm::vec3 terrainPosition, float dimX, float dimY)
{
	vEye		= elm::vec3(100, 40, 100);
	vRight		= elm::vec3(1, 0, 0);
	vUp			= elm::vec3(0, 1, 0);
	vLook		= elm::vec3(0, 0, 1);

	//elm::rotationAxis(mRot, elm::vec3(1, 0, 0), PI / 6);
	//vLook = mRot * vLook;
	//vUp = mRot * vUp;

	elm::perspectiveFovLH(mProj, PI / 2, (float)width / height, 1.f, 20000.f);
	elm::lookAtLH(mView, vLook, vUp, vEye);
}

void Camera::move(elm::vec2 direction)
{
	vEye.xz += direction;
	elm::lookAtLH(mView, vLook, vUp, vEye);
}

void Camera::rotate(float angle)
{
	elm::rotationAxis(mRot, elm::vec3(0, 1, 0), angle);
	vLook = mRot * vLook;
	elm::lookAtLH(mView, vLook, vUp, vEye);
}

Camera::~Camera()
{
}