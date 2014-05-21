#include "stfdafx.h"
#include "../Engine/EngineInterface.h"

namespace wrap
{
	public ref class GraphicsCommunicator
	{
	private:
		EngineInterface *gfx;
	public:
		GraphicsCommunicator();
		~GraphicsCommunicator();

		void setRenderArea(int x, int y, int width, int height);

		void renderScene();
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

		void moveCamera(int xDir, int zDir);

		void setHandle(System::IntPtr _handle, System::String^ _name);

		/* Mouse calls */
		void rightMouseDown();
		void leftMouseDown();
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