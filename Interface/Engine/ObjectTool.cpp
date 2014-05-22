#include "ObjectTool.h"

#include "RenderDX11.h"

ObjectTool::ObjectTool(RenderDX11	*_dxPtr)
{
	dxPtr = _dxPtr;
	cameraPtr = _dxPtr->camera;
	currentState = OTState::NONE;
}


ObjectTool::~ObjectTool(void)
{
}

void ObjectTool::setAxis( elm::vec3 _axis )
{
	currentAxis = _axis;
}

void ObjectTool::update(Composition* _composition, elm::vec2 _mouse, elm::vec2 _oldMouse)
{
	Object3D* object	= _composition->getProperty<Object3D>();
	Mesh3D* mesh		= dxPtr->g_meshes[object->getMeshID()];

	if( !mesh || !object )
		return;

	switch(currentState)
	{
	case OTState::ROTATE:
		rotate(_mouse, _oldMouse, object, mesh, currentAxis);
		break;
	case  OTState::SCALE:
		scale(_mouse, _oldMouse, object, mesh, currentAxis);
		break;
	case  OTState::TRANSLATE:
		translate(_mouse, _oldMouse, object, mesh, currentAxis);
		break;
	}
}

void ObjectTool::pickRay(elm::vec2 _xy, elm::vec3& _outRayDir, elm::vec3& _outRayOrigin)
{
	// Compute the vector of the pick ray in screen space
    elm::vec3 v;
	v.x =  (((2.f * (float)_xy.x) / (float)cameraPtr->width) - 1.f) /  cameraPtr->mProj._11;
	v.y = -(((2.f * (float)_xy.y) /  (float)cameraPtr->height) - 1.f) /  cameraPtr->mProj._22;
    v.z =  1.f;

    // Get the inverse view matrix
    elm::mat4 m = elm::inverse( cameraPtr->mView);
	// Transform the screen space pick ray into 3D space
    _outRayDir.x  = v.x * m._11 + v.y * m._21 + v.z * m._31;
    _outRayDir.y  = v.x * m._12 + v.y * m._22 + v.z * m._32;
    _outRayDir.z  = v.x * m._13 + v.y * m._23 + v.z * m._33;

	_outRayDir = elm::normalize(_outRayDir);
	_outRayOrigin = m.r[3].xyz;

	// calc origin as intersection with near frustum
	_outRayOrigin += _outRayDir;
}

bool ray(elm::vec3 rayDirFrac, elm::vec3 rayOrig, elm::vec3 min, elm::vec3 max)
{
	float t1 = (min.x - rayOrig.x) * rayDirFrac.x;
	float t2 = (max.x - rayOrig.x) * rayDirFrac.x;
	float t3 = (min.y - rayOrig.y) * rayDirFrac.y;
	float t4 = (max.y - rayOrig.y) * rayDirFrac.y;
	float t5 = (min.z - rayOrig.z) * rayDirFrac.z;
	float t6 = (max.z - rayOrig.z) * rayDirFrac.z;

	float tmin = std::max<float>(std::max<float>(std::min<float>(t1, t2), std::min<float>(t3, t4)), std::min<float>(t5, t6));
	float tmax = std::min<float>(std::min<float>(std::max<float>(t1, t2), std::max<float>(t3, t4)), std::max<float>(t5, t6));

	// if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behind us
	if(tmax < 0)
		return false;

	// if tmin > tmax, ray doesn't intersect AABB
	return !(tmin > tmax);
}

void ObjectTool::setState(OTState _state)
{
	currentState = _state;
}

void ObjectTool::rotate(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis)
{
	elm::vec3 rotation;

	elm::vec3 min, max;
	min = _mesh->getMinVertex() * _object->getScale() + _object->getPosition();
	max = _mesh->getMaxVertex() * _object->getScale() + _object->getPosition();

	float xDiff, yDiff;
	xDiff = _mouse.x - _oldMouse.x;
	yDiff = _mouse.y - _oldMouse.y;

	elm::vec3 nrot = elm::vec3(yDiff + xDiff) * _axis / 10.f;

	_object->setRotation( nrot + _object->getRotation() );
}

void ObjectTool::scale(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis)
{
	elm::vec3 vPickRayDir, vPickRayOrig;
	pickRay(_mouse, vPickRayDir, vPickRayOrig);

	float xDiff, yDiff;
	xDiff = _mouse.x - _oldMouse.x;
	yDiff = _mouse.y - _oldMouse.y;

	elm::vec3 nscale = elm::vec3( (xDiff + yDiff) * _axis / 10.f ) + _object->getScale();

	float min = 0.1f;
	float max = 5.0f;
	if(nscale.x > max || nscale.y > max ||nscale.z > max)
		nscale = elm::vec3(max);
	if(nscale.x < min || nscale.y < min || nscale.z < min)
		nscale = elm::vec3(min);

	_object->setScale( nscale );
	
}

void ObjectTool::translate(elm::vec2 _mouse, elm::vec2 _oldMouse, Object3D* _object, Mesh3D* _mesh, elm::vec3 _axis)
{
	elm::vec3 vPickRayDir, vPickRayOrig;
	pickRay(_mouse, vPickRayDir, vPickRayOrig);
	//min max to world
	elm::vec3 min, max;
	min = _mesh->getMinVertex() * _object->getScale() + _object->getPosition();
	max = _mesh->getMaxVertex() * _object->getScale() + _object->getPosition();

	elm::vec3 diff = vPickRayOrig - _object->getPosition();

	float len = elm::vecLength(diff);

	float y = _object->getPosition().y;
	_object->setPosition(vPickRayOrig + (vPickRayDir * len));
	elm::vec3 np = _object->getPosition();
	np.y = y;
	_object->setPosition(np);
}