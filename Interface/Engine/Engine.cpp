#include "Engine.h"


Engine::Engine(HWND hwnd)
{
	hWnd = hwnd;

	selectedTool = Tools::SELECTOR;

	camera = nullptr;
	terrain = nullptr;

	dx = new RenderDX11(hWnd);
}

void Engine::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
{
	if(!terrain)
		terrain = new Terrain();

	terrain->createTerrain(width, height, pointStep, fromPerlinMap, seed);
	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());

	dx->setTerrainIndexCount(terrain->getIndexCount());
	dx->setCamera(camera);
	
	if(!camera)
		camera = new Camera(width, height, terrain);
}

Engine::~Engine()
{
	SAFE_DELETE(dx);
	SAFE_DELETE(camera);
	SAFE_DELETE(terrain);
}