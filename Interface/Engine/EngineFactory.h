#pragma once

#include "EngineInterface.h"

class EngineFactory
{
public:

	static __declspec(dllexport) void addHandle(HWND _hWnd, std::string _name);

	static __declspec(dllexport) EngineInterface *createEngine();

	static __declspec(dllexport) void deleteEngine();

private:
	static EngineInterface* gfx;
};