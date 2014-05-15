#include "Mesh3D.h"
#include <assimp\cimport.h>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include <vector>
#include <cstdint>
#include "..\elm\elm.hpp"
#include "Utility.h"

Mesh3D::Mesh3D()
{
	vertexBufferID = -1;
	normalBufferID = -1;
	texCoordBufferID = -1;
	indexBufferID = -1;
	texDiffuseID = -1;

	numVertices = 0;
	numIndices = 0;
}

bool Mesh3D::loadMesh(const char* filePath)
{

	const aiScene* scene = NULL;
	scene = aiImportFile(filePath, aiProcessPreset_TargetRealtime_MaxQuality);
	if(!scene)
	{
		return false;
	}

	if(!scene->HasMeshes())
	{
		return false;
	}
	
	if(scene->HasMaterials())
	{
		for(unsigned int i = 0; i < scene->mNumMaterials; i++)
		{
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_DIFFUSE))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_DIFFUSE,0,&texturePath);
				texDiffusePath = texturePath.C_Str();
				texDiffusePath = combinePaths(filePath, texDiffusePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_AMBIENT))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_AMBIENT,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_DISPLACEMENT))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_DISPLACEMENT,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_EMISSIVE))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_EMISSIVE,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_HEIGHT))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_HEIGHT,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_LIGHTMAP))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_LIGHTMAP,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_NORMALS))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_NORMALS,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_OPACITY))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_OPACITY,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_REFLECTION))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_REFLECTION,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_SHININESS))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_SHININESS,0,&texturePath);
			}
			if(scene->mMaterials[i]->GetTextureCount(aiTextureType_SPECULAR))
			{
				aiString texturePath;
				scene->mMaterials[i]->GetTexture(aiTextureType_SPECULAR,0,&texturePath);
			}
		}
	}

	int tempPos = 0;
	for(unsigned int i = 0; i < scene->mNumMeshes; i++) // load all meshes.. should save meshes as polygroups? Maybe need to do that for multi-material support..
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
		for(unsigned int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
		{
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos] = scene->mMeshes[i]->mFaces[j].mIndices[0]; 
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos + 1] = scene->mMeshes[i]->mFaces[j].mIndices[1]; 
			indices[j * scene->mMeshes[i]->mFaces->mNumIndices + tempPos + 2] = scene->mMeshes[i]->mFaces[j].mIndices[2]; 
		}
	}

	
	numVertices = vertices.size();
	numIndices = indices.size();

	for(int i = 0; i < numVertices; i++)
	{
		min.x = std::min<float>(min.x, vertices[i].x);
		min.y = std::min<float>(min.y, vertices[i].y);
		min.z = std::min<float>(min.z, vertices[i].z);

		max.x = std::max<float>(max.x, vertices[i].x);
		max.y = std::max<float>(max.y, vertices[i].y);
		max.z = std::max<float>(max.z, vertices[i].z);
	}

	aiReleaseImport(scene);
	return true;
}

Mesh3D::~Mesh3D()
{
}
