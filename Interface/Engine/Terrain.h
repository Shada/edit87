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

	std::vector<Vertex> vBuffer;
	std::vector<uint> iBuffer;

	elm::vec3 position;

	void normalizeTerrain();

	void createTerrainNormals(std::vector<Vertex> &vBuffer);

	void perlinNoise(uint startFrequency, uint frequency, float amplitude, int seed, float persistence = 0.5f);
public:
	Terrain();
	~Terrain();

	/* Camera can only access const functions */
	const float getStep() const					{ return step; }
	const float getWidth() const				{ return width * step; }
	const float getHeight() const				{ return height * step; }
	const elm::vec3 getPosition() const			{ return position; }
	const unsigned int getSize() const			{ return points.size(); }
	const unsigned int getIndexCount() const	{ return (width - 1) * (height - 1) * 6; }

	const float getHeightAt(elm::vec2 pos) const;

	std::vector<Vertex> *getVBuffer()			{ return &vBuffer; }
	std::vector<uint>	*getIBuffer()			{ return &iBuffer; }

	const std::vector<elm::vec3> &getPoints() const { return points; }
	const std::vector<uint>	*getIBuffer() const	{ return &iBuffer; }

	void createTerrain(int w, int h, float pointStep, bool fromPerlinMap, int seed);

	void applyBrush(float radius, float intensity, elm::vec2 origin);
};