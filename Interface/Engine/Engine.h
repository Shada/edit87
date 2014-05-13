#pragma once
#include <thread>

#include "EngineInterface.h"
#include "RenderDX11.h"
#include "Terrain.h"
#include "Camera.h"
#include "Quadnode.h"
#include "ModelDefinitions.h"

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
	Quadnode	*node;

	std::vector<Quadnode*> leafNodes;

	RECT r;

	elm::vec3 mouseWorldPos;

	Tools selectedTool;

	bool minmaxCalcDone;
	std::thread minmaxCalc;

	HWND hWnd;
	POINT mousePos;

	void findMinMaxValues();

	/**********************************
		External Data Representation
	***********************************/
	/* Raw data linkers */
	map< unsigned int, IModel* >		m_properties;

	/* Generic objects */
	map< unsigned int, Composition* >	m_compositions;

public:
	Engine(HWND hwnd);
	~Engine();

	void init();
	void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

	void setRect(RECT t);
	void renderScene()						{ dx->renderScene(); }
	void move(float alongX, float alongZ);

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