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

		void renderScene();
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

		void moveCamera(int xDir, int zDir);

		/* Mouse calls */
		void rightMouseDown(int x, int y);
		void leftMouseDown(int x, int y);
		void rightMouseUp();
		void leftMouseUp();
		void updateMouse(int x, int y);

		/* Tool calls */
		void setElevationTool();
		void setTextureTool();
		void setObjectPlacerTool();
		void setSelctorTool();
	};
}