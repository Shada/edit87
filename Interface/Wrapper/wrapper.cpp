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

	std::string GraphicsCommunicator::toString(System::String^ text)
	{
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(text);
	}

	void GraphicsCommunicator::addHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height)
	{
		HWND hWnd = (HWND)((void*)_handle);
		gfx->addHandle(hWnd, toString(_name), _width, _height);
	}

	void GraphicsCommunicator::updateHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height)
	{
		HWND hWnd = (HWND)((void*)_handle);

		gfx->updateHandle(hWnd, toString(_name), _width, _height);
	}

	void GraphicsCommunicator::resizeWindow(int _width, int _height, System::String ^_name)
	{
		gfx->resizeWindow(_width, _height, toString(_name));
	}

	void GraphicsCommunicator::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
	{
		gfx->createTerrain(width, height, pointStep, fromPerlinMap, seed);
	}

	void GraphicsCommunicator::renderScene()
	{
		gfx->renderScene();
	}

	void GraphicsCommunicator::renderScene(System::String ^_name)
	{
		gfx->renderScene(toString(_name));
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

	void GraphicsCommunicator::setBrushTexture(System::String^ _name)
	{
		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(_name);
		gfx->setBrushTexture(standardString);
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