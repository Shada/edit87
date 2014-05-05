#include "EngineFactory.h"
#include "Engine.h"

EngineInterface *EngineFactory::createEngine(HWND hWnd)
{
	EngineInterface *gfx;
	gfx = new Engine(hWnd);
	return gfx;
}

void EngineFactory::deleteEngine(EngineInterface *gfx)
{
	if(gfx)
		delete gfx;
	gfx = nullptr;
}