#pragma once
#include "Terrain.h"
#include "Quadnode.h"

class Camera
{
private:
	HWND hWnd;

	int width, height;

	const Terrain *terrain;

	float minX, maxX, minZ, maxZ;

	std::vector<elm::vec4> frustum;

	elm::mat4 mProj, mView, mRot;
	
	elm::vec3 terrainPos;
	elm::vec3 vEye, vLook, vUp, vRight;
public:
	Camera(int width, int height, const Terrain *terrain, HWND hwnd);
	~Camera();

	void move(elm::vec2 direction);
	void rotate(float angle);

	void resizeWindow(int width, int height) { elm::perspectiveFovLH(mProj, ELM_PI / 2, (float)width / height, 1.f, 20000.f); }

	elm::vec3 getEye()	{ return vEye; }
	elm::mat4 getProj() { return mProj; }
	elm::mat4 getView() { return mView; }

	std::vector<elm::vec4> getFrustum()	{ return frustum; }

	elm::vec3 getWorldPos(int mousePosX, int mousePosY, Quadnode *node);

	friend class Engine;
};