#include "MeshObject.h"

#pragma comment(lib, "..\\Interface\\bin\\Debug\\assimp.lib")

#include <assimp\cimport.h>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include <vector>
#include "../elm/elm.hpp"

const struct aiScene* scene = NULL;
//unsigned int scene_list = 0;
//struct aiVector3D scene_min, scene_max, scene_center;

//static float angel = 0.f;

//#define aisgl_min(x,y) (x<y?x:y)
//#define aisgl_max(x,y) (y>x?y:x) 

MeshObject::MeshObject()
{
	scene = aiImportFile("D:\\dontpeek\\edit87\\Interface\\Interface\\bin\\Meshes\\IronMan\\IronMan.obj", aiProcessPreset_TargetRealtime_MaxQuality);
	
	std::vector<elm::vec3> vertPoints;
	std::vector<elm::vec3> vertNorms;
	std::vector<elm::vec3> vertTexcoords;

	for(int i = 0;i < scene->mNumMeshes;i++)
	{
		int st = vertPoints.size();
		vertPoints.resize(st + scene->mMeshes[i]->mNumVertices);
		memcpy(&vertPoints.at(st), scene->mMeshes[i]->mVertices, scene->mMeshes[i]->mNumVertices * sizeof(elm::vec3));
		if(scene->mMeshes[i]->HasNormals())
		{
			st = vertNorms.size();
			vertNorms.resize(st + scene->mMeshes[i]->mNumVertices);
			memcpy(&vertNorms.at(st), scene->mMeshes[i]->mNormals, scene->mMeshes[i]->mNumVertices * sizeof(elm::vec3));
		}
		if(scene->mMeshes[i]->HasTextureCoords(0))
		{
			st = vertTexcoords.size();
			vertTexcoords.resize(st + scene->mMeshes[i]->mNumVertices);
			memcpy(&vertTexcoords.at(st), scene->mMeshes[i]->mTextureCoords[0], scene->mMeshes[i]->mNumVertices * sizeof(elm::vec3));
		}
	}
}


MeshObject::~MeshObject()
{
}
