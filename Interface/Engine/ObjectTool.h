#pragma once

#include "../elm/elm.hpp"
#include "Object3D.h"
#include "Mesh3D.h"
#include "KeyDefines.h"
#include "Model.h"

class Camera;
class RenderDX11;
class Terrain;

enum class OTState
{
	SCALE,
	ROTATE,
	TRANSLATE,
	FOLLOWTERRAIN,
	NONE
};

class ObjectTool
{
public:
	ObjectTool(RenderDX11	*_dxPtr, Terrain *_terrain);
	~ObjectTool(void);

	void update(Composition* _composition, elm::vec2 _mouse, elm::vec2 _oldMouse);
	void setAxis( elm::vec3 _axis );
	void setState(OTState _state);
	OTState getState()
	{ return currentState; }
private:
	
	void rotate(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis);
	void scale(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis);
	void translate(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis);

	void moveToTerrainHeight(Object3D* _object);
	void elevate(Object3D* _object);
	void lower(Object3D* _object);

	void pickRay(elm::vec2 _xy, elm::vec3& _outRayDir, elm::vec3& _outRayOrigin);

	RenderDX11	*dxPtr;
	Terrain		*terrain;
	Camera		*cameraPtr;
	elm::vec3	currentAxis;

	OTState		currentState;

	
};

