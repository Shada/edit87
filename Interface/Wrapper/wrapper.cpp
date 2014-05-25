#include "wrapper.h"
#include <msclr\marshal_cppstd.h>
#include "../Engine/EngineFactory.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator()
	{
		gfx = EngineFactory::createEngine();
	}

	void GraphicsCommunicator::addHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height)
	{
		HWND hWnd = (HWND)((void*)_handle);

		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(_name);

		gfx->addHandle(hWnd, standardString, _width, _height);
	}

	void GraphicsCommunicator::updateHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height)
	{
		HWND hWnd = (HWND)((void*)_handle);

		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(_name);

		gfx->updateHandle(hWnd, standardString, _width, _height);
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
	
	void GraphicsCommunicator::cleanUp()
	{
		EngineFactory::deleteEngine();
	}

	GraphicsCommunicator::~GraphicsCommunicator()
	{
	}
}