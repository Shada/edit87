#include <windows.h>
#include <sstream>
#include <thread>
#include "Camera.h"

Camera::Camera(int width, int height, const Terrain *terrain)
{
	vEye		= elm::vec3(100, 300, 100);
	vRight		= elm::vec3(1, 0, 0);
	vUp			= elm::vec3(0, 1, 0);
	vLook		= elm::vec3(0, 0, 1);

	this->terrain = terrain;
	terrainPos = terrain->getPosition();

	minX = terrainPos.x;
	maxX = terrainPos.x + terrain->getWidth();
	minZ = terrainPos.z;
	maxZ = terrainPos.z + terrain->getDepth();

	this->height = height;
	this->width = width;

	elm::rotationAxis(mRot, elm::vec3(1, 0, 0), -ELM_PI / 4);
	vLook = mRot * vLook;
	vUp = mRot * vUp;

	elm::perspectiveFovLH(mProj, ELM_PI / 4, (float)width / height, 1.f, 20000.f);
	elm::lookAtLH(mView, vLook, vUp, vEye);

	frustum = elm::buildViewFrustum(mView, mProj);
}

void Camera::resizeWindow(int width, int height)
{
	this->width = width;
	this->height = height;
	elm::perspectiveFovLH(mProj, ELM_PI / 4, (float)width / height, 1.f, 20000.f);
}

void Camera::move(elm::vec2 direction)
{
	if(direction != 0)
		vEye.xz += elm::normalize(direction.y * vRight.xz + direction.x * vLook.xz) * 7;

	if(vEye.x > maxX)	vEye.x = maxX;
	if(vEye.x < minX)	vEye.x = minX;
	if(vEye.z > maxZ)	vEye.z = maxZ;
	if(vEye.z < minZ)	vEye.z = minZ;

	elm::vec3 eyeCopy = vEye;

	eyeCopy.y = terrain->getHeightAt(vEye.xz) + 30.f;
	if(eyeCopy.y < vEye.y)
		eyeCopy.y = vEye.y;

	elm::lookAtLH(mView, vLook, vUp, eyeCopy);
	frustum = elm::buildViewFrustum(mView, mProj);
}

void Camera::rotate(float angle)
{
	elm::rotationAxis(mRot, elm::vec3(0, 1, 0), angle);
	vLook = mRot * vLook;
	elm::lookAtLH(mView, vLook, vUp, vEye);

	frustum = elm::buildViewFrustum(mView, mProj);
}

elm::vec3 Camera::getWorldPos(int mousePosX, int mousePosY, Quadnode *node)
{
	elm::vec3 vPickRayDir, vPickRayOrig;

    // Compute the vector of the pick ray in screen space
    elm::vec3 v;
	v.x =  (((2.f * mousePosX) / width) - 1) / mProj._11;
	v.y = -(((2.f * mousePosY) / height) - 1) / mProj._22;
    v.z =  1.f;

    // Get the inverse view matrix
    elm::mat4 m = elm::inverse(mView);

    // Transform the screen space pick ray into 3D space
    vPickRayDir.x  = v.x * m._11 + v.y * m._21 + v.z * m._31;
    vPickRayDir.y  = v.x * m._12 + v.y * m._22 + v.z * m._32;
    vPickRayDir.z  = v.x * m._13 + v.y * m._23 + v.z * m._33;

	vPickRayDir = elm::normalize(vPickRayDir);
	vPickRayOrig = m.r[3].xyz;
    //vPickRayOrig.x = m._41;
    //vPickRayOrig.y = m._42;
    //vPickRayOrig.z = m._43;

	// calc origin as intersection with near frustum
	vPickRayOrig += vPickRayDir;

	std::vector<Quadnode*> intersectingQuads = node->rayIntersects(1.f / vPickRayDir, vPickRayOrig);
	if(intersectingQuads.size() == 0)
		return elm::vec3(-100);

	float pointStep = terrain->getStep();

	elm::vec3 step = vLook * (pointStep * 0.5f);
	const std::vector<uint> *iBuffer = terrain->getIBuffer();
	const std::vector<elm::vec3> *points = terrain->getPoints();

	float minLen = 999999.f, len;
	uint at;

	float a, b, c, d;
	elm::vec3 e1, e2, u, w, p0, p1, p2;

	std::vector<int> ats(intersectingQuads.size(), -1);
	std::vector<std::thread> threads(intersectingQuads.size());

	for(uint i = 0; i < intersectingQuads.size(); i++)
	{
		uint start = intersectingQuads.at(i)->getBufferStart();
		uint end = intersectingQuads.at(i)->getBufferEnd();
		for(uint j = start; j < end - 2; j += 3)
		{
			p0 = points->at(iBuffer->at(j));
			p1 = points->at(iBuffer->at(j + 1));
			p2 = points->at(iBuffer->at(j + 2));

			e1 = p1 - p0;
			u = elm::cross(vPickRayDir, p2 - p0);
			a = elm::dot(e1, u);

			// Acceptance rate
			if(a > -0.00001 && a < 0.00001)
				continue;

			b = 1.f / a;
			v = vPickRayOrig - p0;
			c = b * elm::dot(u, v);

			if(c < 0.f)
				continue;

			d = b * elm::dot(vPickRayDir, elm::cross(v, e1));

			if(d < 0.0f || c + d > 1.0f)
				continue;

			len = elm::vecLength(vPickRayOrig - p0);
			if(len < minLen)
			{
				minLen = len;
				at = j;
			}
		}
	}

	if(minLen == 999999.f)
		return elm::vec3(-100);

	return points->at(iBuffer->at(at));
}

Camera::~Camera()
{
}