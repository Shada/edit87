#pragma once
#include "Terrain.h"

class Camera
{
private:
	const Terrain *terrain;

	float minX, maxX, minZ, maxZ;

	elm::mat4 mProj, mView, mRot;
	
	elm::vec3 terrainPos;
	elm::vec3 vEye, vLook, vUp, vRight;
public:
	Camera(int width, int height, const Terrain *terrain);
	~Camera();

	void move(elm::vec2 direction);
	void rotate(float angle);

	void resizeWindow(int width, int height) { elm::perspectiveFovLH(mProj, ELM_PI / 2, (float)width / height, 1.f, 20000.f); }

	elm::vec3 getEye()	{ return vEye; }
	elm::mat4 getProj() { return mProj; }
	elm::mat4 getView() { return mView; }

	elm::vec2 getWorldPos(int mousePosX, int mousePosY);
};