#pragma once

#include "stfdafx.h"
#include "../Engine/EngineInterface.h"

#include <windows.system.h>



namespace wrap
{
	public ref class GraphicsCommunicator
	{
	private:
		HWND hWnd;
		EngineInterface *gfx;
	public:
		GraphicsCommunicator(System::IntPtr win);
		~GraphicsCommunicator();

		void setRenderArea(int x, int y, int width, int height);

		void renderScene();
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

		void moveCamera(int xDir, int zDir);

		/* Mouse calls */
		void rightMouseDown();
		void leftMouseDown();
		void rightMouseUp();
		void leftMouseUp();
		void updateMouse(int x, int y, float delta);
		void keyboardEvent(unsigned int _key, bool _isDown);
		
		
		/* Tool calls */
		void setElevationTool();
		void setTextureTool();
		void setObjectPlacerTool();
		void setSelctorTool();
	};
}