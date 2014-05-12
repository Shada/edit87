#include "Engine.h"


Engine::Engine(HWND hwnd)
{
	hWnd = hwnd;

	selectedTool = Tools::SELECTOR;

	minmaxCalcDone = true;

	camera = nullptr;
	terrain = nullptr;

	dx = new RenderDX11(hWnd);

	mouseWorldPos = elm::vec3(200, 0, 1000);
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

	minmaxCalc = std::thread(&Terrain::findMinMaxValues, terrain, std::ref(leafNodes));
	minmaxCalc.join();

	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());

	if(!camera)
		camera = new Camera(r.right - r.left, r.bottom - r.top, terrain, hWnd);

	dx->setTerrainIndexCount(terrain->getIndexCount());
	dx->setCamera(camera);
}

void Engine::leftMouseDown()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		break;
	}
	terrain->applyBrush(100, 1, mouseWorldPos.xz);
	if(minmaxCalcDone)
		findMinMaxValues();

	camera->move(elm::vec2(0));

	dx->updateTerrainBuffer(terrain->getVBuffer());
	dx->renderScene(node);
}

void Engine::rightMouseDown()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		break;
	}
	terrain->applyBrush(100, -1, mouseWorldPos.xz);
	if(minmaxCalcDone)
		findMinMaxValues();

	camera->move(elm::vec2(0));

	dx->updateTerrainBuffer(terrain->getVBuffer());
	dx->renderScene(node);
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
	minmaxCalc = std::thread(&Terrain::findMinMaxValues, terrain, std::ref(leafNodes));
	minmaxCalc.detach();
	minmaxCalcDone = true;
}

Engine::~Engine()
{
	SAFE_DELETE(dx);
	SAFE_DELETE(node);
	SAFE_DELETE(camera);
	SAFE_DELETE(terrain);
}