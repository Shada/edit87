//#include "../cproject/printClass.h"
#include "stfdafx.h"
#include "../Engine/EngineInterface.h"

namespace wrap
{
	public ref class GraphicsCommunicator
	{
	private:
		EngineInterface *gfx;
	public:
		GraphicsCommunicator(System::IntPtr win);
		~GraphicsCommunicator();

		void setRenderArea(int x, int y, int width, int height);

		void renderScene();
		void mouseReleased(MouseKeyType mType);
		void mousePressed(MouseKeyType mType);
		void sendMousePos(int x, int y);
	};
}