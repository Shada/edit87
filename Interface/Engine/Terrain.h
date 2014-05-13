#pragma once

#include <vector>
#include "../elm/elm.hpp"
#include "Quadnode.h"

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
	uint width, height, maxDepth;
	float step;
	std::vector<elm::vec3> points;

	std::vector<Vertex> vBuffer;
	std::vector<uint> iBuffer;

	elm::vec3 position;

	void normalizeTerrain();

	void createTerrainNormals(std::vector<Vertex> &vBuffer);

	void fillIndexBuffer(int startX, int startY);
	void createQuadTree(int startX, int startY, int depth);

	void perlinNoise(uint startFrequency, uint frequency, float amplitude, int seed, float persistence = 0.5f);
public:
	Terrain();
	~Terrain();

	/* Camera can only access const functions */
	float getStep() const						{ return step; }
	float getWidth() const						{ return width * step; }
	float getDepth() const						{ return height * step; }
	elm::vec3 getPosition() const				{ return position; }
	unsigned int getSize() const				{ return points.size(); }
	unsigned int getIndexCount() const			{ return width * height * 6; }

	float getHeightAt(elm::vec2 pos) const;

	int getTreeDepth() { return maxDepth; }

	std::vector<Vertex> *getVBuffer()			{ return &vBuffer; }
	std::vector<uint>	*getIBuffer()			{ return &iBuffer; }

	const std::vector<elm::vec3> *getPoints() const { return &points; }
	const std::vector<uint>	*getIBuffer() const	{ return &iBuffer; }

	elm::vec2 getDim() { return elm::vec2(position.x + width * step, position.z + height * step); }

	void createTerrain(int w, int h, float pointStep, bool fromPerlinMap, int seed);

	void applyBrush(float radius, float intensity, elm::vec2 origin, uint &startID, uint &amount);
	void findMinMaxValues(std::vector<Quadnode*> &nodes);
};