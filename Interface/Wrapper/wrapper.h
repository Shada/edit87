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
		GraphicsCommunicator();
		~GraphicsCommunicator();

		void setRenderArea(int x, int y, int width, int height);

		void renderScene();
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

		void moveCamera(int xDir, int zDir);

		/* Mouse calls */
		void rightMouseDown(int brushSize, int brushIntensity);
		void leftMouseDown(int brushSize, int brushIntensity);
		void rightMouseUp();
		void leftMouseUp();
		void updateMouse(int x, int y);

		/* Tool calls */
		void setTextureTool()			{ gfx->setTextureTool();		}
		void setSelctorTool()			{ gfx->setSelctorTool();		}
		void setElevationTool()			{ gfx->setElevationTool();		}
		void setNormalizerTool()		{ gfx->setNormalizerTool();		}
		void setObjectPlacerTool()		{ gfx->setObjectPlacerTool();	}

		void setHandle(System::IntPtr _handle, System::String^ _name, int width, int height);
	};
}