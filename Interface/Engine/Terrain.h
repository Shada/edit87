#pragma once

#include <vector>
#include "../elm/elm.hpp"

class Terrain
{
private:
	int width, height;
	float step;
	std::vector<elm::vec3> points;

	elm::vec3 position;
public:
	Terrain();
	~Terrain();

	elm::vec3 getPosition()			{ return position; }
	float getWidth()				{ return width * step; }
	float getHeight()				{ return height * step; }
	const unsigned int getSize()	{ return points.size(); }

	std::vector<elm::vec3> *createTerrain(int w, int h, float pointStep, bool fromPerlinMap = false);
};