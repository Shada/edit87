#pragma once
#include "..\elm\elm.hpp"

class Object3D
{
public:
	Object3D();
	~Object3D();

	void setPosition(elm::vec3 inpos)			{ position = inpos; }
	void setRotation(elm::vec3 inrot)		{ rotation = inrot; }
	void setScale(elm::vec3 inscale)		{ scale = inscale; }

	void setMeshID(int id)					{ meshID = id; }
	
	elm::vec3 getPosition()		{ return position; }
	elm::vec3 getRotation()		{ return rotation; }
	elm::vec3 getScale()		{ return scale; }

	bool getIsFollowingTerrain() { return isFollowingTerrain; }
	void setIsFollowingTerrain(bool value) { isFollowingTerrain = value; }

	int getMeshID()				{ return meshID; }

private:
	elm::vec3 position;
	elm::vec3 rotation;
	elm::vec3 scale;

	bool isFollowingTerrain;

	int meshID;
};