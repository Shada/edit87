#include "Quadnode.h"

Quadnode::Quadnode()
{
	min = max = elm::vec3();

	bufferStart = bufferEnd = 0;

	nodes[0] = nullptr;
	nodes[1] = nullptr;
	nodes[2] = nullptr;
	nodes[3] = nullptr;
}

void Quadnode::fillTree(uint bufferStart, uint bufferEnd, elm::vec2 min, elm::vec2 max, int depth)
{
	this->bufferStart = bufferStart;
	this->bufferEnd = bufferEnd;

	this->min.xz = min;
	this->min.y = -1000;
	this->max.xz = max;
	this->max.y = 1000;

	if(depth == 0)
		return;

	int sigmaX[] = { 0, 1, 0, 1 };
	int sigmaY[] = { 0, 0, 1, 1 };
	
	float diffX = (max.x - min.x) / 2;
	float diffY = (max.y - min.y) / 2;
	
	for(int i = 0; i < 4; i++)
	{
		uint start = bufferStart + i * (bufferEnd - bufferStart) / 4;
		uint end = bufferEnd - (3 - i) * (bufferEnd - bufferStart) / 4;
	
		elm::vec2 _min = elm::vec2(min.x + sigmaX[i] * diffX,		min.y + sigmaY[i] * diffY);
		elm::vec2 _max = elm::vec2(max.x - sigmaX[3 - i] * diffX,	max.y - sigmaY[3 - i] * diffY);
	
		nodes[i] = new Quadnode();
		nodes[i]->fillTree(start, end, _min, _max, depth - 1);
	}
}

std::vector<Quadnode*> Quadnode::rayIntersects(elm::vec3 rayDirFrac, elm::vec3 rayOrig)
{
	std::vector<Quadnode*> intersectingNodes;
	if(rayVsAABB(rayDirFrac, rayOrig))
		getIntersectingQuads(intersectingNodes, rayDirFrac, rayOrig);
	
	return intersectingNodes;
}

void Quadnode::getIntersectingQuads(std::vector<Quadnode*> &quadnodes, elm::vec3 dir, elm::vec3 orig)
{
	if(rayVsAABB(dir, orig))
	{
		if(!nodes[0])
			quadnodes.push_back(this);
		else
			for(uint i = 0; i < 4; i++)
				nodes[i]->getIntersectingQuads(quadnodes, dir, orig);
	}
}

bool Quadnode::rayVsAABB(elm::vec3 rayDirFrac, elm::vec3 rayOrig)
{
	float t1 = (min.x - rayOrig.x) * rayDirFrac.x;
	float t2 = (max.x - rayOrig.x) * rayDirFrac.x;
	float t3 = (min.y - rayOrig.y) * rayDirFrac.y;
	float t4 = (max.y - rayOrig.y) * rayDirFrac.y;
	float t5 = (min.z - rayOrig.z) * rayDirFrac.z;
	float t6 = (max.z - rayOrig.z) * rayDirFrac.z;

	float tmin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
	float tmax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

	// if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behind us
	if(tmax < 0)
		return false;

	// if tmin > tmax, ray doesn't intersect AABB
	return !(tmin > tmax);
}

bool Quadnode::frustumIntersects(const std::vector<elm::vec4> &frustum)
{
	for(int i = 0; i < 6; i++)
		if(!planeAABBIntersection(frustum.at(i)))
			return false;
	
	return true;
}

bool Quadnode::planeAABBIntersection(const elm::vec4 &plane)
{
	elm::vec3 planeNormal = elm::vec3(plane.xyz);
	float planeConstant = plane.w;

	// Check each axis (x,y,z) to get the AABB vertex furthest away from the direction the plane is facing (plane normal)
	elm::vec3 axisVert;

	axisVert.x = plane.x < 0.f ? min.x : max.x;
	axisVert.y = plane.y < 0.f ? min.y : max.y;
	axisVert.z = plane.z < 0.f ? min.z : max.z;

	// Now we get the signed distance from the AABB vertex that's furthest down the frustum planes normal,
	// and if the signed distance is negative, then the entire bounding box is behind the frustum plane, which means
	// that it should be culled

	return !(elm::dot(planeNormal, axisVert) + planeConstant < 0.f);
}

void Quadnode::findAllLeaves(std::vector<Quadnode*> &leafNodes)
{
	if(nodes[0])
	{
		nodes[0]->findAllLeaves(leafNodes);
		nodes[1]->findAllLeaves(leafNodes);
		nodes[2]->findAllLeaves(leafNodes);
		nodes[3]->findAllLeaves(leafNodes);
	}
	else
	{
		leafNodes.push_back(this);
	}
}

void Quadnode::getIndexBufferValues(const std::vector<elm::vec4> &frustum, std::vector<int> &id, int depth)
{
	if(frustumIntersects(frustum))
	{
		if(!nodes[0] || depth == 0)
		{
			id.push_back(bufferStart);
			id.push_back(bufferEnd);
		}
		else
			for(uint i = 0; i < 4; i++)
				nodes[i]->getIndexBufferValues(frustum, id, depth - 1);
	}
}

Quadnode::~Quadnode()
{
	for(int i = 0; i < 4; i++)
	{
		if(nodes[i])
		{
			delete nodes[i];
			nodes[i] = nullptr;
		}
	}
}