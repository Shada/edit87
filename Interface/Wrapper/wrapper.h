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

		void renderScene();
		void createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed);

		void moveCamera(int xDir, int zDir);

		void setBrushIntensity(int _val);
		void setBrushSize(int _val);

		/* Mouse calls */
		void updateMouse();

		/* Tool calls */
		void setTextureTool()			{ gfx->setTextureTool();		}
		void setSelctorTool()			{ gfx->setSelctorTool();		}
		void setElevationTool()			{ gfx->setElevationTool();		}
		void setNormalizerTool()		{ gfx->setNormalizerTool();		}
		void setObjectPlacerTool()		{ gfx->setObjectPlacerTool();	}

		void resizeWindow(int width, int height);
		void addHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height);
		void updateHandle(System::IntPtr _handle, System::String^ _name, int _width, int _height);

		void cleanUp();
	};
}