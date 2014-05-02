#pragma once

#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface() {}
	virtual ~EngineInterface() {}

	virtual void renderScene() = 0;

	virtual void setRect(RECT t) = 0;

	virtual HRESULT createTerrain(int width, int height, float pointStep, bool fromPerlinMap) = 0;

	virtual void move(float alongX, float alongZ) = 0;
};