#include "en

EngineInterface *EngineFactory::createGraphics(HWND hWnd);

	static __declspec(dllexport) void deleteGraphics(EngineInterface *gfx);