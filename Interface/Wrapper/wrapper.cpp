#include "wrapper.h"
#include "../Engine/EngineFactory.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator(System::IntPtr win)
	{
		hWnd = (HWND)((void*)win);
		gfx = EngineFactory::createEngine(hWnd);
	}

	void GraphicsCommunicator::setRenderArea(int x, int y, int width, int height)
	{
		RECT r;
		r.top = y;
		r.left = x; 
		r.bottom = y + height;
		r.right = x + width;
		gfx->setRect(r);
	}

	void GraphicsCommunicator::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
	{
		gfx->createTerrain(width, height, pointStep, fromPerlinMap, seed);
	}

	void GraphicsCommunicator::renderScene()
	{
		gfx->renderScene();
	}

	void GraphicsCommunicator::moveCamera(int xDir, int zDir)
	{
		gfx->move((float)xDir, (float)zDir);
	}

	void GraphicsCommunicator::rightMouseDown(int brushSize, int brushIntensity)
	{
		gfx->rightMouseDown(brushSize, (float)brushIntensity / 100);
	}

	void GraphicsCommunicator::leftMouseDown(int brushSize, int brushIntensity)
	{
		gfx->leftMouseDown(brushSize, (float)brushIntensity / 100);
	}

	void GraphicsCommunicator::rightMouseUp()
	{
		gfx->rightMouseUp();
	}

	void GraphicsCommunicator::leftMouseUp()
	{
		gfx->leftMouseUp();
	}

	void GraphicsCommunicator::updateMouse(int x, int y)
	{
		POINT p;
		p.x = x;
		p.y = y;
		gfx->updateMouse(p);
	}

	GraphicsCommunicator::~GraphicsCommunicator()
	{
		delete(gfx);
	}
}