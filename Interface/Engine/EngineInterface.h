#pragma once

#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface() {}
	virtual ~EngineInterface() {}

	virtual void renderScene() = 0;

	virtual void setRect(RECT t) = 0;

	virtual void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed) = 0;

	virtual void move(float alongX, float alongZ) = 0;

	/* Mouse calls */
	virtual void rightMouseDown(int brushSize, float brushIntensity) = 0;
	virtual void leftMouseDown(int brushSize, float brushIntensity) = 0;
	virtual void rightMouseUp() = 0;
	virtual void leftMouseUp() = 0;
	virtual void updateMouse(POINT mouse) = 0;

	/* Tool calls */
	virtual void setTextureTool() = 0;
	virtual void setSelctorTool() = 0;
	virtual void setElevationTool() = 0;
	virtual void setNormalizerTool() = 0;
	virtual void setObjectPlacerTool() = 0;
};