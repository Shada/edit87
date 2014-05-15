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
	virtual void rightMouseDown() = 0;
	virtual void leftMouseDown() = 0;
	virtual void rightMouseUp() = 0;
	virtual void leftMouseUp() = 0;
	virtual void updateMouse(POINT mouse, float delta) = 0;
	virtual void keyboardEvent(unsigned int _key, bool _isDown) = 0;
	virtual void scroll() = 0;
	/* Tool calls */
	virtual void setElevationTool() = 0;
	virtual void setTextureTool() = 0;
	virtual void setObjectPlacerTool() = 0;
	virtual void setSelctorTool() = 0;

	virtual void placeObject(unsigned int _objectId) = 0;
};