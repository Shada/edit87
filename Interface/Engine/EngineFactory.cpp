#include "EngineFactory.h"
#include "RenderDX11.h"
#include "Controller.h"

EngineInterface *EngineFactory::createGraphics(HWND hWnd)
{
	EngineInterface *gfx;
	gfx = new RenderDX11(hWnd);
	
	return gfx;
}

void EngineFactory::deleteGraphics(EngineInterface *gfx)
{
	if(gfx)
		delete gfx;
	gfx = NULL;
}

Controller* EngineFactory::createController()
{
	return new Controller();
}

void EngineFactory::deleteController(Controller* controller)
{
	if(controller)
	{
		delete controller;
	}

	controller = nullptr;
}