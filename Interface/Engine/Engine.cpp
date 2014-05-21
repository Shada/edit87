#include "Engine.h"


Engine::Engine()
{
	selectedTool = Tools::SELECTOR;

	camera = nullptr;
	terrain = nullptr;
	dx = nullptr;

	//dx = new RenderDX11(hWnd);

	mouseWorldPos = elm::vec2(200, 1000);
}

void Engine::addHandels(HWND _hWnd, std::string _name)
{
	if(!dx)
		dx = new RenderDX11();
	
	dx->addHandle(_hWnd, _name);
}

void Engine::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
{
	if(!terrain)
		terrain = new Terrain();

	terrain->createTerrain(width, height, pointStep, fromPerlinMap, seed);
	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());

	if(!camera)
		camera = new Camera(width, height, terrain);

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
	terrain->applyBrush(100, 1, elm::vec2(200, 1000));
	camera->move(elm::vec2(0));
	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());
	dx->renderScene();
}

void Engine::rightMouseDown()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		break;
	}
	terrain->applyBrush(100, -1, elm::vec2(200, 1000));
	camera->move(elm::vec2(0));
	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());
	dx->renderScene();
}

void Engine::updateMouse(POINT mouse)
{
	mousePos = mouse;
	mouseWorldPos = camera->getWorldPos(mousePos.x, mousePos.y);
}

Engine::~Engine()
{
	SAFE_DELETE(dx);
	SAFE_DELETE(camera);
	SAFE_DELETE(terrain);
}