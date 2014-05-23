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
	}

	void GraphicsCommunicator::setHandle(System::IntPtr _handle, System::String^ _name)
	{
		HWND hWnd = (HWND)((void*)_handle);
		gfx = EngineFactory::createEngine();
		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(_name);
		gfx->addHandels(hWnd, standardString);

		setRenderArea(0, 0, 850, 600);
	}
	void GraphicsCommunicator::resizeWindow(int width, int height)
	{
		gfx->resizeWindow(width, height);
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

	void GraphicsCommunicator::setBrushIntensity(int _val)
	{
		gfx->setBrushIntensity(_val);
	}

	void GraphicsCommunicator::setBrushSize(int _val)
	{
		gfx->setBrushSize(_val);
	}

	void GraphicsCommunicator::updateMouse()
	{
		gfx->updateMouse();
	}

	GraphicsCommunicator::~GraphicsCommunicator()
	{
		delete(gfx);
	}
}