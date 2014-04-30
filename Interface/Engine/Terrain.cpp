#include "Terrain.h"

Terrain::Terrain()
{
}

std::vector<elm::vec3> *Terrain::createTerrain(int w, int h, int pointStep, bool fromPerlinMap)
{
	width = w;
	height = h;
	step = pointStep;

	points = std::vector<elm::vec3>(width * height, elm::vec3());
	points.shrink_to_fit();

	//if(!fromPerlinMap)
		//perlinNoiseMap(....);

	return &points;
}

Terrain::~Terrain()
{
}