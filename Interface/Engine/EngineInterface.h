#pragma once

#include <Windows.h>

class EngineInterface
{
public:
	EngineInterface(){}
	virtual ~EngineInterface(){}

	virtual void renderScene() = 0;

	virtual void setRect(RECT t) = 0;
};