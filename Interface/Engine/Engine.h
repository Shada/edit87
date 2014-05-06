#pragma once
#include "EngineInterface.h"
#include "RenderDX11.h"
#include "Terrain.h"
#include "Camera.h"

enum class Tools
{
	ELEVATION = 0,
	TEXTURING = 1,
	OBJECTPLACER = 2,
	SELECTOR = 3
};

class Engine : public EngineInterface
{
private:
	RenderDX11	*dx;
	Terrain		*terrain;
	Camera		*camera;

	RECT r;

	elm::vec3 mouseWorldPos;

	Tools selectedTool;

	HWND hWnd;
	POINT mousePos;
public:
	Engine(HWND hwnd);
	~Engine();

	void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

	void setRect(RECT t);
	void renderScene()						{ dx->renderScene(); }
	void move(float alongX, float alongZ)	{ camera->move(elm::vec2(alongX, alongZ)); }

	/* Mouse calls */ // Maybe we want to handle mouse up and down entirely in c#. Discuss this with other ppl
	void rightMouseDown();
	void leftMouseDown();
	void rightMouseUp()						{}
	void leftMouseUp()						{}
	void updateMouse(POINT mouse);

	/* Tool calls */
	void setElevationTool()					{ selectedTool = Tools::ELEVATION; }
	void setTextureTool()					{ selectedTool = Tools::TEXTURING; }
	void setObjectPlacerTool()				{ selectedTool = Tools::OBJECTPLACER; }
	void setSelctorTool()					{ selectedTool = Tools::SELECTOR; }
};