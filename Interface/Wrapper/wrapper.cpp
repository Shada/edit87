#include "wrapper.h"
#include <Windows.h>

namespace wrap
{
	GraphicsCommunicator::GraphicsCommunicator(System::IntPtr win)
	{
		HWND hWnd = (HWND)((void*)win);
		//gfx = new DX11((void*)win);
	}

	int GraphicsCommunicator::onButtonClick()
	{
		//return gfx->printNumber();
		return 42;
	}

	void GraphicsCommunicator::setRenderArea(int x, int y, int width, int height)
	{
		RECT r;
		r.top = y;
		r.left = x; 
		r.bottom = y + height;
		r.right = x + width;
		//gfx->setRenderArea(r);
	}

	void GraphicsCommunicator::updateScene()
	{

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
	
	GraphicsCommunicator::~GraphicsCommunicator()
	{
	}
}