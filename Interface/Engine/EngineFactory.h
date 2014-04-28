#pragma once

#include "EngineInterface.h"

class EngineFactory
{
public:
	static __declspec(dllexport) EngineInterface *createGraphics(HWND hWnd);

	static __declspec(dllexport) void deleteGraphics(EngineInterface *gfx);
};