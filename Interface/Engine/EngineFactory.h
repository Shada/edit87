#pragma once

#include "EngineInterface.h"

class EngineFactory
{
public:
	static __declspec(dllexport) EngineInterface *createEngine(HWND hWnd);

	static __declspec(dllexport) void deleteEngine(EngineInterface *gfx);
};