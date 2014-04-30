#include "wrapper.h"
#include "../Engine/EngineFactory.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator(System::IntPtr win)
	{
		hWnd = (HWND)((void*)win);
		gfx = EngineFactory::createGraphics(hWnd);
		setRenderArea(0,0,200,200);
		gfx->init();
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

	void GraphicsCommunicator::createTerrain(int width, int height, int pointStep, bool fromPerlinMap)
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
	
	GraphicsCommunicator::~GraphicsCommunicator()
	{
	}
}