#pragma once

#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface() {}
	virtual ~EngineInterface() {}

	virtual HRESULT init() = 0;

	virtual void renderScene() = 0;

	virtual void setRect(RECT t) = 0;

	virtual HRESULT createTerrain(int width, int height, int pointStep, bool fromPerlinMap) = 0;
};