#pragma once

#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface() {}
	virtual ~EngineInterface() {}

	virtual void renderScene() = 0;

	virtual void setRect(RECT t) = 0;

	virtual void setMouse(POINT pos) = 0;

	virtual HRESULT createTerrain(int width, int height, float pointStep, bool fromPerlinMap) = 0;

	virtual void move(float alongX, float alongZ) = 0;

	/* Tool calls */
	virtual void setTextureTool() = 0;
	virtual void setSelectorTool() = 0;
	virtual void setElevationTool() = 0;
	virtual void setObjectPlacerTool() = 0;

	virtual void useTool() = 0;
};