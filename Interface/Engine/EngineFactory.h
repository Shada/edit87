#pragma once

#include "Controller.h"
#include "EngineInterface.h"


class EngineFactory
{
public:
	static __declspec(dllexport) EngineInterface *createGraphics(HWND hWnd);

	static __declspec(dllexport) void deleteGraphics(EngineInterface *gfx);

	static __declspec(dllexport) Controller* createController();

	static __declspec(dllexport) void deleteController(Controller *controller);
};