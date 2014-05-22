#include "EngineFactory.h"
#include "Engine.h"

EngineInterface* EngineFactory::gfx = NULL;

void EngineFactory::addHandle(HWND _hWnd, std::string _name)
{
	gfx->addHandels(_hWnd, _name);
}

EngineInterface *EngineFactory::createEngine()
{
	gfx = new Engine();
	return gfx;
}

void EngineFactory::deleteEngine()
{
	if(gfx)
		delete gfx;
	gfx = nullptr;
}