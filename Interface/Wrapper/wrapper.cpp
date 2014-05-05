#include "wrapper.h"
#include "../Engine/EngineFactory.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator(System::IntPtr win)
	{
		hWnd = (HWND)((void*)win);
		gfx = EngineFactory::createGraphics(hWnd);
		setRenderArea(232, 58, 1048, 670);
	}

	void GraphicsCommunicator::setRenderArea(int x, int y, int width, int height)
	{
		RECT r;
		r.top = y;
		r.left = x; 
		r.bottom = y + height;
		r.right = x + width;
		gfx->setRect(r);
		//gfx->createTerrain(256, 256, 5.f, false);
	}

	void GraphicsCommunicator::createTerrain(int width, int height, float pointStep, bool fromPerlinMap)
	{
		gfx->createTerrain(width, height, pointStep, fromPerlinMap);
	}

	void GraphicsCommunicator::renderScene()
	{
		gfx->renderScene();
	}

	void GraphicsCommunicator::mouseReleased(MouseKeyType mType)
	{

	}

	void GraphicsCommunicator::mousePressed(MouseKeyType mType)
	{

	}

	void GraphicsCommunicator::sendMousePos(int x, int y)
	{
		POINT p;
		p.x = x;
		p.y = y;
		//gfx->setMousePos(p);
	}

	void GraphicsCommunicator::moveCamera(int xDir, int zDir)
	{
		gfx->move((float)xDir, (float)zDir);
		gfx->renderScene();
	}
	
	GraphicsCommunicator::~GraphicsCommunicator()
	{
		EngineFactory::deleteGraphics(gfx);
	}
}