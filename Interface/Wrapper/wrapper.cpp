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
	}

	void GraphicsCommunicator::createTerrain(int width, int height, float pointStep, bool fromPerlinMap)
	{
		gfx->createTerrain(width, height, pointStep, fromPerlinMap);
	}

	void GraphicsCommunicator::renderScene()
	{
		gfx->renderScene();
	}

	void GraphicsCommunicator::mouseDown(int x, int y)
	{

	}

	void GraphicsCommunicator::mouseUp()
	{
		
	}

	void GraphicsCommunicator::mouseMoved(int x, int y)
	{
		POINT p;
		p.x = x;
		p.y = y;
		gfx->setMouse(p);
	}

	void GraphicsCommunicator::moveCamera(int xDir, int zDir)
	{
		gfx->move((float)xDir, (float)zDir);
		gfx->renderScene();
	}

	void GraphicsCommunicator::setElevationTool()
	{
		
	}

	void GraphicsCommunicator::setTextureTool()
	{

	}

	void GraphicsCommunicator::setObjectPlacerTool()
	{

	}

	void GraphicsCommunicator::setSelectorTool()
	{

	}

	void GraphicsCommunicator::useTool()
	{

	}
	
	GraphicsCommunicator::~GraphicsCommunicator()
	{
	}
}