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

		void setBrushIntensity(int _val);
		void setBrushSize(int _val);
		void setBrushTexture(System::String^ _name);

		/* Mouse calls */
		void updateMouse();

		/* Tool calls */
		void setTextureTool()			{ gfx->setTextureTool();		}
		void setSelctorTool()			{ gfx->setSelctorTool();		}
		void setElevationTool()			{ gfx->setElevationTool();		}
		void setNormalizerTool()		{ gfx->setNormalizerTool();		}
		void setObjectPlacerTool()		{ gfx->setObjectPlacerTool();	}

		void resizeWindow(int width, int height);
		void setHandle(System::IntPtr _handle, System::String^ _name);
		void updateHandle(System::IntPtr _handle, System::String^ _name);
	};
}