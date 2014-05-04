#include "Camera.h"

Camera::Camera(int width, int height, const Terrain *terrain)
{
	vEye		= elm::vec3(100, 150, 100);
	vRight		= elm::vec3(1, 0, 0);
	vUp			= elm::vec3(0, 1, 0);
	vLook		= elm::vec3(0, 0, 1);

	this->terrain = terrain;
	terrainPos = terrain->getPosition();

	minX = terrainPos.x;
	maxX = terrainPos.x + terrain->getWidth();
	minZ = terrainPos.z;
	maxZ = terrainPos.z + terrain->getHeight();

	elm::rotationAxis(mRot, elm::vec3(1, 0, 0), -ELM_PI / 6);
	vLook = mRot * vLook;
	vUp = mRot * vUp;

	elm::perspectiveFovLH(mProj, ELM_PI / 4, (float)width / height, 1.f, 20000.f);
	elm::lookAtLH(mView, vLook, vUp, vEye);
}

void Camera::move(elm::vec2 direction)
{
	vEye.xz += elm::normalize(direction.y * vRight.xz + direction.x * vLook.xz) * 5;

	if(vEye.x > maxX)	vEye.x = maxX;
	if(vEye.x < minX)	vEye.x = minX;
	if(vEye.z > maxZ)	vEye.z = maxZ;
	if(vEye.z < minZ)	vEye.z = minZ;

	elm::vec3 eyeCopy = vEye;

	eyeCopy.y = terrain->getHeightAt(vEye.xz) + 30.f;
	if(eyeCopy.y < vEye.y)
		eyeCopy.y = vEye.y;

	elm::lookAtLH(mView, vLook, vUp, eyeCopy);
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