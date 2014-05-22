#include "Engine.h"


Engine::Engine(HWND hwnd)
{
	hWnd = hwnd;

	selectedTool = Tools::ELEVATION;

	minmaxCalcDone = true;

	camera = nullptr;
	terrain = nullptr;

	dx = new RenderDX11(hWnd);

	mouseWorldPos = elm::vec3(200, 0, 1000);
}

void Engine::init()
{
	// create ref struct
	CModel<Object3D>* co = new CModel<Object3D>("test", dx->g_objects[0]);

	// create composition
	Composition c;
	c.setProperty(co);
}

void Engine::setRect(RECT t)
{
	r = t;
	dx->setRect(t);
	if(camera)
		camera->resizeWindow(r.right - r.left, r.bottom - r.top);
}

void Engine::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
{
	if(!terrain)
		terrain = new Terrain();

	terrain->createTerrain(width, height, pointStep, fromPerlinMap, seed);

	node = new Quadnode();
	node->fillTree(0, terrain->getIBuffer()->size(), terrain->getPosition().xz, terrain->getDim(), terrain->getTreeDepth());
	node->findAllLeaves(leafNodes);

	terrain->findMinMaxValues(leafNodes);

	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());

	if(!camera)
		camera = new Camera(r.right - r.left, r.bottom - r.top, terrain, hWnd);

	dx->setTerrainIndexCount(terrain->getIndexCount());
	dx->setCamera(camera);
}

void Engine::leftMouseDown(int brushSize, float brushIntensity)
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		terrain->applyElevationBrush((float)brushSize, brushIntensity, mouseWorldPos.xz);
		dx->updateTerrainBuffer(terrain->getVBuffer());
		break;
	case Tools::NORMALIZER:
		terrain->applyNormalizeBrush((float)brushSize, brushIntensity, mouseWorldPos.xz);
		dx->updateTerrainBuffer(terrain->getVBuffer());
		break;
	}

	

	if(minmaxCalcDone)
	{
		minmaxCalc = std::thread(&Engine::findMinMaxValues, this);
		minmaxCalc.detach();
	}

	camera->move(elm::vec2(0));

	
}

void Engine::rightMouseDown(int brushSize, float brushIntensity)
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		terrain->applyElevationBrush((float)brushSize, -brushIntensity, mouseWorldPos.xz);
		dx->updateTerrainBuffer(terrain->getVBuffer());
		break;
	case Tools::NORMALIZER:
		terrain->applyDefaultNormalizeBrush((float)brushSize, brushIntensity, mouseWorldPos.xz);
		dx->updateTerrainBuffer(terrain->getVBuffer());
		break;
	case Tools::TEXTURING:
		dx->blendmapBrush((float)brushSize, brushIntensity, mouseWorldPos.xz, "..\\Textures\\lavag.jpg", terrain->getStep());
		break;
	}


	if(minmaxCalcDone)
	{
		minmaxCalc = std::thread(&Engine::findMinMaxValues, this);
		minmaxCalc.detach();
	}

	camera->move(elm::vec2(0));

}

void Engine::leftMouseUp()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		break;
	case Tools::NORMALIZER:
		terrain->resetNormalizer();
		break;
	}
}

void Engine::rightMouseUp()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		break;
	case Tools::NORMALIZER:
		terrain->resetNormalizer();
		break;
	}
}

void Engine::move(float alongX, float alongZ)
{
	camera->move(elm::vec2(alongX, alongZ));
	mouseWorldPos = camera->getWorldPos(mousePos.x, mousePos.y, node);
}

void Engine::updateMouse(POINT mouse)
{
	mousePos = mouse;
	mouseWorldPos = camera->getWorldPos(mousePos.x, mousePos.y, node);
}

void Engine::findMinMaxValues()
{
	minmaxCalcDone = false;
	terrain->findMinMaxValues(leafNodes);
	minmaxCalcDone = true;
}

Engine::~Engine()
{
	SAFE_DELETE(dx);
	SAFE_DELETE(node);
	SAFE_DELETE(camera);
	SAFE_DELETE(terrain);
}