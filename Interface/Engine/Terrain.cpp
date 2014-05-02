#include "Terrain.h"

Terrain::Terrain()
{
}

void Terrain::createTerrain(int w, int h, float pointStep, bool fromPerlinMap, std::vector<Vertex> &vBuffer, std::vector<unsigned int> &iBuffer)
{
	width = w;
	height = h;
	step = pointStep;

	position = elm::vec3(0);

	points = std::vector<elm::vec3>(width * height);
	vBuffer = std::vector<Vertex>(width * height);
	iBuffer = std::vector<unsigned int>((width - 1) * (height - 1) * 6);

	int index1, index2, ii = 0;
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			vBuffer.at(y * width + x).pos = points.at(y * width + x) = elm::vec3(x * step, 0, y * step);
			vBuffer.at(y * width + x).texCoord.x = (vBuffer.at(y * width + x).pos.x + (0.5f * width)) / width;
			vBuffer.at(y * width + x).texCoord.y = (vBuffer.at(y * width + x).pos.z - (0.5f * height)) / -height;

			if(x == width - 1 || y == height - 1)
				continue;

			index1 = x + y * width;
			index2 = x + (y + 1) * width;

			iBuffer.at(ii++) = index1;
			iBuffer.at(ii++) = index2 + 1;
			iBuffer.at(ii++) = index2;
			iBuffer.at(ii++) = index1;
			iBuffer.at(ii++) = index1 + 1;
			iBuffer.at(ii++) = index2 + 1;
		}
	}

	//if(fromPerlinMap)
		//perlinNoiseMap(....);

	createTerrainNormals(vBuffer);
}

void Terrain::createTerrainNormals(std::vector<Vertex> &vBuffer)
{
	std::vector<int> indices = std::vector<int>(points.size());
	std::vector<elm::vec3> norms = std::vector<elm::vec3>(points.size());

	elm::vec3 norm;
	int index1, index2;

	for(int y = 0; y < height - 1; y++)
	{
		for(int x = 0; x < width - 1; x++)
		{
			index1 = (int)(y		* width + x);
			index2 = (int)((y + 1)	* width + x);

			norm = elm::cross(	vBuffer.at(index1).pos - vBuffer.at(index2).pos,
								vBuffer.at(index1).pos - vBuffer.at(index2 + 1).pos);

			norms.at(index1) += norm;
			norms.at(index2 + 1) += norm;
			norms.at(index2) += norm;

			norm = elm::cross(	vBuffer.at(index1).pos - vBuffer.at(index2 + 1).pos,
								vBuffer.at(index1).pos - vBuffer.at(index1 + 1).pos);

			norms.at(index1) += norm;
			norms.at(index1 + 1) += norm;
			norms.at(index2 + 1) += norm;

			vBuffer.at(index1).normal = elm::normalize(norms.at(index1));
		}
	}
	for(int i = index1; i < index2; i++)
	{
		vBuffer.at(i).normal = elm::normalize(norms.at(i));
		vBuffer.at((i - index1) * height + width - 1).normal = elm::normalize(norms.at((i - index1) * height + width - 1));
	}

	vBuffer.at(width * height - 1).normal = elm::normalize(norms.at(width * height - 1));
	vBuffer.at(width * height - 2).normal = elm::normalize(norms.at(width * height - 2));
}

Terrain::~Terrain()
{
}