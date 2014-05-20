#pragma once
#include <thread>

#include "EngineInterface.h"
#include "RenderDX11.h"
#include "Terrain.h"
#include "Camera.h"
#include "Quadnode.h"
#include "ModelDefinitions.h"
#include "KeyDefines.h"

enum class Tools
{
	ELEVATION = 0,
	TEXTURING = 1,
	OBJECTPLACER = 2,
	SELECTOR = 3,
};

class Engine : public EngineInterface
{
private:
	RenderDX11	*dx;
	Terrain		*terrain;
	Camera		*camera;
	Quadnode	*node;

	std::vector<Quadnode*> leafNodes;

	RECT r;

	elm::vec3 mouseWorldPos;

	Tools selectedTool;

	bool minmaxCalcDone;
	std::thread minmaxCalc;

	HWND hWnd;
	POINT mousePos;
	POINT oldMousePos;
	float mouseDelta;
	
	void findMinMaxValues();
	void pickRay(POINT _xy, elm::vec3& _outRayDir, elm::vec3& _outRayOrigin);

	Composition*	m_selectedObject;
	KeyBinding		m_currentKeyBinding;

	elm::vec3	m_defaultScale;
	elm::vec3	m_defaultRotation;

public:
	Engine(HWND hwnd);
	~Engine();

	void init();
	void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

	void setRect(RECT t);
	void renderScene()						{ dx->renderScene(node); }
	void move(float alongX, float alongZ);

	/* Mouse calls */ // Maybe we want to handle mouse up and down entirely in c#. Discuss this with other ppl
	void rightMouseDown();
	void leftMouseDown();
	void rightMouseUp();
	void leftMouseUp();
	void scroll();
	void updateMouse(POINT mouse, float delta);
	void keyboardEvent(unsigned int _key, bool _isDown);

	/* Tool calls */
	void setElevationTool()					{ selectedTool = Tools::ELEVATION; }
	void setTextureTool()					{ selectedTool = Tools::TEXTURING; }
	void setObjectPlacerTool()				{ selectedTool = Tools::OBJECTPLACER; }
	void setSelctorTool()					{ selectedTool = Tools::SELECTOR; }

	void placeObject(unsigned int _objectId);
	void moveObject();
	void selectObject();
	void scaleObject();
	void rotateObject();
	void moveObjectToTerrainHeight();
	void elevateObject();
	void lowerObject();

	void updateFollowTerrainObjects();
};