//#include "../cproject/printClass.h"
#include "stfdafx.h"
#include "../Engine/EngineInterface.h"
#include "../Engine/Controller.h"

namespace wrap
{
	public ref class GraphicsCommunicator
	{
	private:
		HWND hWnd;
		EngineInterface *gfx;
		Controller		*controller;
	public:
		GraphicsCommunicator(System::IntPtr win);
		~GraphicsCommunicator();

		void setRenderArea(int x, int y, int width, int height);

		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap);

		void renderScene();
		void mouseReleased(MouseKeyType mType);
		void mousePressed(MouseKeyType mType);
		void sendMousePos(int x, int y);

		void moveCamera(int xDir, int zDir);
	};
}