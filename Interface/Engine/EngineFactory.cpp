#include "EngineFactory.h"
#include "RenderDX11.h"

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