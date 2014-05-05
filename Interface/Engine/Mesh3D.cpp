#include "Mesh3D.h"
#include <assimp\cimport.h>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include <vector>
#include "..\elm\elm.hpp"
Mesh3D::Mesh3D()
{
	vertexBufferID = -1;
	numVertices = -1;
}

bool Mesh3D::loadMesh(const char* filePath)
{

	const aiScene* scene = NULL;
	scene = aiImportFile(filePath, aiProcessPreset_TargetRealtime_Fast);
	if(!scene)
	{
		return false;
	}

	if(!scene->HasMeshes())
	{
		return false;
	}
	int tempPos = 0;
	for(int i = 0; i < scene->mNumMeshes; i++)
	{
		tempPos = vertices.size();
		vertices.resize(vertices.size() + scene->mMeshes[i]->mNumVertices);
		normals.resize(normals.size() + scene->mMeshes[i]->mNumVertices);
		texCoords.resize(texCoords.size() + scene->mMeshes[i]->mNumVertices);
	
		memcpy(&vertices[tempPos], &scene->mMeshes[i]->mVertices[0], sizeof(elm::vec3) * scene->mMeshes[i]->mNumVertices);
		if(scene->mMeshes[i]->HasNormals())
		{
			memcpy(&normals[tempPos], &scene->mMeshes[i]->mNormals[0], sizeof(elm::vec3) * scene->mMeshes[i]->mNumVertices);
		}
		if(scene->mMeshes[i]->HasTextureCoords(0))
		{
			memcpy(&texCoords[tempPos], &scene->mMeshes[i]->mTextureCoords[0][0], sizeof(elm::vec3) * scene->mMeshes[i]->mNumVertices);
		}
		tempPos = indices.size();
		indices.resize(indices.size() + scene->mMeshes[i]->mFaces->mNumIndices * scene->mMeshes[i]->mNumFaces);
		for(int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
		{
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos] = scene->mMeshes[i]->mFaces[j].mIndices[0]; 
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos + 1] = scene->mMeshes[i]->mFaces[j].mIndices[1]; 
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos + 2] = scene->mMeshes[i]->mFaces[j].mIndices[2]; 
		}
	}
	numVertices = vertices.size();
	numIndices = indices.size();

	aiReleaseImport(scene);
	return true;
}

Mesh3D::~Mesh3D()
{
}
