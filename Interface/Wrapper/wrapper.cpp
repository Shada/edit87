#include "wrapper.h"
#include "../Engine/EngineFactory.h"
#include <Windows.h>

#include "../Engine/RenderDX11.h" 
#include "../Engine/Controller.h"

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator(System::IntPtr win)
	{
		hWnd = (HWND)((void*)win);
		gfx = EngineFactory::createGraphics(hWnd);
		setRenderArea(232, 58, 1048, 670);
		
		bool result;

		controller = EngineFactory::createController();
		result = controller->init( (RenderDX11*)gfx, "../");
		int i = 42;
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
		//gfx->createTerrain(width, height, pointStep, fromPerlinMap);
		controller->createTerrain(width, height, pointStep, fromPerlinMap);
	}

	void GraphicsCommunicator::renderScene()
	{
		controller->draw();
		//gfx->renderScene();
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
		//gfx->renderScene();
		controller->draw();
	}
	
	GraphicsCommunicator::~GraphicsCommunicator()
	{
	}
}