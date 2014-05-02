#pragma once

#include <vector>
#include "../elm/elm.hpp"

struct Vertex
{
	elm::vec3 pos;
	elm::vec3 normal;
	elm::vec2 texCoord;
};

class Terrain
{
private:
	int width, height;
	float step;
	std::vector<elm::vec3> points;

	elm::vec3 position;

	void createTerrainNormals(std::vector<Vertex> &vBuffer);
public:
	Terrain();
	~Terrain();

	elm::vec3 getPosition()			{ return position; }
	float getWidth()				{ return width * step; }
	float getHeight()				{ return height * step; }
	const unsigned int getSize()	{ return points.size(); }
	const unsigned int getIndexCount() { return (width - 1) * (height - 1) * 6; }

	void createTerrain(int w, int h, float pointStep, bool fromPerlinMap, std::vector<Vertex> &vBuffer, std::vector<unsigned int> &iBuffer);
};