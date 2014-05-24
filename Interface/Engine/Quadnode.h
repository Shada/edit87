#pragma once

#include "../elm/elm.hpp"

typedef unsigned int uint;

class Quadnode
{
private:
	uint bufferStart, bufferEnd;
	Quadnode *nodes[4];

	elm::vec3 max, min;

	void getIntersectingQuads(std::vector<Quadnode*> &quadnodes, elm::vec3 dir, elm::vec3 orig);

	bool planeAABBIntersection(const elm::vec4 &plane);
	bool rayVsAABB(elm::vec3 rayDirFrac, elm::vec3 rayOrig);
public:
	Quadnode();
	~Quadnode();

	uint getBufferStart()	{ return bufferStart; }
	uint getBufferEnd()		{ return bufferEnd; }

	float getMinY()			{ return min.y; }
	float getMaxY()			{ return max.y; }
	void setMinY(float y)	{ min.y = y; }
	void setMaxY(float y)	{ max.y = y; }

	void fillTree(uint bufferStart, uint bufferEnd, elm::vec2 min, elm::vec2 max, int depth);

	bool frustumIntersects(const std::vector<elm::vec4> &frustum);
	
	void Quadnode::getIndexBufferValues(const std::vector<elm::vec4> &frustum, std::vector<int> &id, int depth);
	void findAllLeaves(std::vector<Quadnode*> &leafNodes);
	std::vector<Quadnode*> rayIntersects(elm::vec3 rayDirFrac, elm::vec3 rayOrig);
};