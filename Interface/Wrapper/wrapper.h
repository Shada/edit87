#include "stfdafx.h"
#include "../Engine/EngineInterface.h"

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

		void moveCamera(int xDir, int zDir);
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap);

		void renderScene();

		/* Mouse calls */
		void mouseDown(int x, int y);
		void mouseUp();
		void mouseMoved(int x, int y);

		/* Tool calls */
		void setTextureTool();
		void setSelectorTool();
		void setElevationTool();
		void setObjectPlacerTool();

		void useTool();
	};
}