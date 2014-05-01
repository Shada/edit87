#include "Terrain.h"

Terrain::Terrain()
{
}

std::vector<elm::vec3> *Terrain::createTerrain(int w, int h, float pointStep, bool fromPerlinMap)
{
	width = w;
	height = h;
	step = pointStep;

	position = elm::vec3(0);

	points = std::vector<elm::vec3>(width * height, elm::vec3());
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			points.at(i * width + j) = elm::vec3(j * step, (float)rand() / RAND_MAX * 100, i * step);
		}
	}
	points.shrink_to_fit();

	//if(!fromPerlinMap)
		//perlinNoiseMap(....);

	return &points;
}

Terrain::~Terrain()
{
}