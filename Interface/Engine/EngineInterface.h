#pragma once
#include <string>
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

	virtual void setBrushIntensity(int _val) = 0;
	virtual void setBrushSize(int _val) = 0;

	/* Mouse calls */
	virtual void updateMouse() = 0;
	virtual void resizeWindow(int width, int height) = 0;

	/* Tool calls */
	virtual void setTextureTool() = 0;
	virtual void setElevationTool() = 0;
	virtual void setNormalizerTool() = 0;
	virtual void setObjectPlacerTool() = 0;
	virtual void setSelctorTool() = 0;
	virtual void addHandels(HWND _hWnd, std::string _name) = 0;
};