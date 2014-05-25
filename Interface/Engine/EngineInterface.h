#pragma once
#include <string>
#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface() {}
	virtual ~EngineInterface() {}

	virtual void renderScene() = 0;
	virtual void renderScene(std::string name) = 0;

	virtual void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed) = 0;

	virtual void move(float alongX, float alongZ) = 0;

	virtual void setBrushIntensity(int _val) = 0;
	virtual void setBrushSize(int _val) = 0;
	virtual void setBrushTexture(std::string _val) = 0;

	/* Mouse calls */
	virtual void updateMouse() = 0;
	virtual void resizeWindow(int width, int height, std::string name) = 0;

	/* Tool calls */
	virtual void setSelctorTool() = 0;
	virtual void setTextureTool() = 0;
	virtual void setElevationTool() = 0;
	virtual void setNormalizerTool() = 0;
	virtual void setObjectPlacerTool() = 0;

	virtual void addHandle(HWND _hWnd, std::string _name, int width, int height) = 0;
	virtual void updateHandle(HWND _hWnd, std::string _name, int width, int height) = 0;
};