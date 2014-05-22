#pragma once
#include <thread>

#include "EngineInterface.h"
#include "RenderDX11.h"
#include "Terrain.h"
#include "Camera.h"
#include "Quadnode.h"
#include "ModelDefinitions.h"
#include <vector>

enum class Tools
{
	ELEVATION = 0,
	TEXTURING = 1,
	OBJECTPLACER = 2,
	SELECTOR = 3,
	NORMALIZER = 4
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
	Engine();
	~Engine();

	void init();
	void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

	void setRect(RECT t);
	void renderScene()						{ dx->renderScene(); }
	void move(float alongX, float alongZ);

	/* Mouse calls */ // Maybe we want to handle mouse up and down entirely in c#. Discuss this with other ppl
	void rightMouseDown(int brushSize, float brushIntensity);
	void leftMouseDown(int brushSize, float brushIntensity);
	void rightMouseUp();
	void leftMouseUp();
	void updateMouse(POINT mouse);

	/* Tool calls */
	void setTextureTool()					{ selectedTool = Tools::TEXTURING;		}
	void setSelctorTool()					{ selectedTool = Tools::SELECTOR;		}
	void setElevationTool()					{ selectedTool = Tools::ELEVATION;		}
	void setNormalizerTool()				{ selectedTool = Tools::NORMALIZER;		}
	void setObjectPlacerTool()				{ selectedTool = Tools::OBJECTPLACER;	}
	void addHandels(HWND _hWnd, std::string _name);
};