#include <random>

#include "Terrain.h"

Terrain::Terrain()
{
	position = elm::vec3(0);
}

void Terrain::createTerrain(int w, int h, float pointStep, bool fromPerlinMap, std::vector<Vertex> &vBuffer, std::vector<uint> &iBuffer)
{
	width = w;
	height = h;
	step = pointStep;

	points = std::vector<elm::vec3>(width * height, elm::vec3());
	vBuffer = std::vector<Vertex>(width * height);
	iBuffer = std::vector<uint>((width - 1) * (height - 1) * 6);

	if(fromPerlinMap)
	{
		perlinNoise(32, 64, 128);
		normalizeTerrain();
	}

	int index1, index2, ii = 0;
	for(uint y = 0; y < height; y++)
	{
		for(uint x = 0; x < width; x++)
		{
			int index = x + y * width;
			vBuffer.at(index).pos = points.at(y * width + x) = elm::vec3(x * step, points.at(index).y, y * step);
			vBuffer.at(index).texCoord.x = (vBuffer.at(index).pos.x + (0.5f * width)) / width;
			vBuffer.at(index).texCoord.y = (vBuffer.at(index).pos.z - (0.5f * height)) / -(int)height;

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

	createTerrainNormals(vBuffer);
}


void Terrain::perlinNoise(uint startFrequency, uint frequency, float amplitude, float persistence)
{
	std::uniform_real_distribution<float> range(0, 1);
	std::mt19937 numberGenerator;
	numberGenerator.seed(rand());

	std::vector<float> randomMap((width + 1) * (height + 1));
	for(uint x = 0; x < width + 1; x++)
		for(uint y = 0; y < height + 1; y++)
			randomMap[x + y * (height + 1)] = range(numberGenerator);

	auto value = [&](uint x, uint y)->float&{ return randomMap[(y + 1) * width + (x + 1)]; };
	auto interpolate = [](float a, float b, float x)->float
	{
		float t = (1 - cos(x * ELM_PI)) * .5f;
		return a * (1 - t) + b * t;
	};

	uint intX, intY;
	float amp, noise, temp, freq;
	float fracX, fracY, xTemp, yTemp;

	float floatStartFrequency = float(startFrequency);

	for(uint x = 0; x < width; x++)
	{
		for(uint y = 0; y < height; y++)
		{
			amp = amplitude;
			noise = 0;
			for(freq = floatStartFrequency; freq <= frequency; freq /= persistence)
			{
				temp = 1 / freq;
				xTemp = x * temp;
				yTemp = y * temp;
				intX = uint(xTemp);
				fracX = xTemp - float(intX);

				intY = uint(yTemp);
				fracY = yTemp - float(intY);

				noise += interpolate(
					interpolate(
					value(intX + 0, intY + 0),
					value(intX + 1, intY + 0),
					fracX),
					interpolate(
					value(intX + 0, intY + 1),
					value(intX + 1, intY + 1),
					fracX),
					fracY) * amp;

				amp *= persistence;
			}
			points.at(x + y * width) += noise;
		}
	}
}

void Terrain::createTerrainNormals(std::vector<Vertex> &vBuffer)
{
	std::vector<int> indices = std::vector<int>(points.size());
	std::vector<elm::vec3> norms = std::vector<elm::vec3>(points.size());

	elm::vec3 norm;
	int index1, index2;

	for(uint y = 0; y < height - 1; y++)
	{
		for(uint x = 0; x < width - 1; x++)
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

void Terrain::normalizeTerrain()
{
	float min = 99999.f;
	for(uint i = 0; i < points.size(); i++)
		if(points.at(i).y < min)
			min = points.at(i).y;

	for(uint i = 0; i < points.size(); i++)
		points.at(i).y -= min;
}

const float Terrain::getHeightAt(elm::vec2 pos) const
{
	uint index1 = (int)((pos.y - position.z + step / 2) / step) * width;
	uint index2 = (int)((pos.x - position.x + step / 2) / step);

	if(index1 < 0) index1 = 0;
	if(index1 > (width - 1) * height) index1 = (width - 1) * height;

	if(index2 < 0) index2 = 0;
	if(index2 > width - 1) index2 = width - 1;

	return points.at(index1 + index2).y;
}

Terrain::~Terrain()
{
}