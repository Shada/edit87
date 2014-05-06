#include "Engine.h"


Engine::Engine(HWND hwnd)
{
	hWnd = hwnd;

	selectedTool = Tools::SELECTOR;

	camera = nullptr;
	terrain = nullptr;

	dx = new RenderDX11(hWnd);

	mouseWorldPos = elm::vec3(200, 0, 1000);
}

void Engine::setRect(RECT t)
{
	r = t;
	dx->setRect(t);
}

void Engine::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
{
	if(!terrain)
		terrain = new Terrain();

	terrain->createTerrain(width, height, pointStep, fromPerlinMap, seed);
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
	terrain->applyBrush(100, -1, mouseWorldPos.xz);
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