#include "wrapper.h"
#include <msclr\marshal_cppstd.h>
#include "../Engine/EngineFactory.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator()
	{
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

	void GraphicsCommunicator::setHandle(System::IntPtr _handle, System::String^ _name, int width, int height)
	{
		HWND hWnd = (HWND)((void*)_handle);
		gfx = EngineFactory::createEngine();
		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(_name);
		gfx->addHandels(hWnd, standardString, width, height);

		//setRenderArea(232, 58, 1048, 670);
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