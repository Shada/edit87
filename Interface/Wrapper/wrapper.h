//#include "../cproject/printClass.h"
#include "stfdafx.h"

namespace wrap
{
	public ref class GraphicsCommunicator
	{
	private:
		//DX11 *gfx;
	public:
		GraphicsCommunicator(System::IntPtr win);
		~GraphicsCommunicator();

		int onButtonClick();

		void setRenderArea(int x, int y, int width, int height);

		void updateScene();
		void mouseReleased(MouseKeyType mType);
		void mousePressed(MouseKeyType mType);
		void sendMousePos(int x, int y);
	};
}