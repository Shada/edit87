#pragma once

#include <vector>
#include "../elm/elm.hpp"

struct Vertex
{
	elm::vec3 pos;
	elm::vec3 normal;
	elm::vec2 texCoord;
};

typedef unsigned int uint;

class Terrain
{
private:
	uint width, height;
	float step;
	std::vector<elm::vec3> points;

	elm::vec3 position;

	void normalizeTerrain();

	void createTerrainNormals(std::vector<Vertex> &vBuffer);

	void perlinNoise(uint startFrequency, uint frequency, float amplitude, float persistence = 0.5f);
public:
	Terrain();
	~Terrain();

	const float getWidth() const				{ return width * step; }
	const float getHeight() const				{ return height * step; }
	const elm::vec3 getPosition() const			{ return position; }
	const unsigned int getSize() const			{ return points.size(); }
	const unsigned int getIndexCount() const	{ return (width - 1) * (height - 1) * 6; }

	const float getHeightAt(elm::vec2 pos) const;

	void createTerrain(int w, int h, float pointStep, bool fromPerlinMap, std::vector<Vertex> &vBuffer, std::vector<uint> &iBuffer);
};