#pragma once

#include <vector>
#include "../elm/elm.hpp"

class Terrain
{
private:
	int width, height, step;
	std::vector<elm::vec3> points;
public:
	Terrain();
	~Terrain();
	const unsigned int getSize() { return points.size();}
	std::vector<elm::vec3> *createTerrain(int w, int h, int pointStep, bool fromPerlinMap = false);
};

