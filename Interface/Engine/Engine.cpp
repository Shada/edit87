#include "Engine.h"

Engine::Engine(HWND hwnd)
{
	hWnd = hwnd;

	selectedTool = Tools::SELECTOR;

	minmaxCalcDone = true;

	camera = nullptr;
	terrain = nullptr;

	dx = new RenderDX11(hWnd);

	m_selectedObject	= nullptr;
	m_defaultRotation	= elm::vec3(0);
	m_defaultScale		= elm::vec3(1);


	mouseWorldPos = elm::vec3(200, 0, 1000);
}

void Engine::init()
{
	unsigned int ref;
	
	// create ref struct
	CModel<Object3D>* co = new CModel<Object3D>("test", dx->g_objects[0]);

	// create composition
	Composition c;
	c.setProperty(co);
}

void Engine::setRect(RECT t)
{
	r = t;
	dx->setRect(t);
	if(camera)
		camera->resizeWindow(r.right - r.left, r.bottom - r.top);
}

void Engine::createTerrain(int width, int height, float pointStep, bool fromPerlinMap, int seed)
{
	if(!terrain)
		terrain = new Terrain();

	terrain->createTerrain(width, height, pointStep, fromPerlinMap, seed);

	node = new Quadnode();
	node->fillTree(0, terrain->getIBuffer()->size(), terrain->getPosition().xz, terrain->getDim(), terrain->getTreeDepth());
	node->findAllLeaves(leafNodes);

	terrain->findMinMaxValues(leafNodes);
	//minmaxCalc = std::thread(&Terrain::findMinMaxValues, terrain, std::ref(leafNodes));
	//minmaxCalc.join();

	dx->createAndSetTerrainBuffers(terrain->getVBuffer(), terrain->getIBuffer());

	if(!camera)
		camera = new Camera(r.right - r.left, r.bottom - r.top, terrain, hWnd);

	dx->setTerrainIndexCount(terrain->getIndexCount());
	dx->setCamera(camera);
}

void Engine::leftMouseDown()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
			terrain->applyBrush(100, 1, mouseWorldPos.xz);
			if(minmaxCalcDone)
				findMinMaxValues();
		break;
	case Tools::SELECTOR:
		
		if(m_currentKeyBinding.second == true)
			switch(m_currentKeyBinding.first)
			{
			case Key::STATE_MOVE:
				moveObject();
				break;
			case Key::STATE_ROTATE:
				rotateObject();
				break;
			case Key::STATE_SCALE:
				scaleObject();
				break;
			case Key::STATE_PLACE:
				m_currentKeyBinding = std::make_pair((unsigned int)Key::STATE_PLACE,true);
				break;
			}
		break;
	}

	camera->move(elm::vec2(0));


	oldMousePos = mousePos;
	dx->updateTerrainBuffer(terrain->getVBuffer());
	dx->renderScene(node);
}

void Engine::leftMouseUp()
{
	if(m_currentKeyBinding.second == true)
	{
		switch(m_currentKeyBinding.first)
		{
		case Key::STATE_PLACE:
			placeObject(0);
			break;
		}
	}

	switch(selectedTool)
	{
	case Tools::OBJECTPLACER:

		break;
	case Tools::SELECTOR:
		selectObject();
		
		break;
	}

	dx->renderScene(node);
}

void Engine::rightMouseDown()
{
	switch(selectedTool)
	{
	case Tools::ELEVATION:
		terrain->applyBrush(100, -1, mouseWorldPos.xz);
		if(minmaxCalcDone)
			findMinMaxValues();
		break;
	}


	camera->move(elm::vec2(0));

	dx->updateTerrainBuffer(terrain->getVBuffer());
	dx->renderScene(node);
}

void Engine::rightMouseUp()
{
	switch(selectedTool)
	{
	case Tools::OBJECTPLACER:
		setSelctorTool();

		break;
	}

	if(m_selectedObject != nullptr)
	{
		m_selectedObject->setSelected(false);
		m_selectedObject = nullptr;
		dx->renderScene(node);
	}

	m_currentKeyBinding = std::make_pair( (unsigned int)Key::NO_STATE, true);
}

void Engine::scroll()
{
}

void Engine::move(float alongX, float alongZ)
{
	camera->move(elm::vec2(alongX, alongZ));
	mouseWorldPos = camera->getWorldPos(mousePos.x, mousePos.y, node);
}

void Engine::updateMouse(POINT mouse, float delta)
{
	oldMousePos = mousePos;
	mousePos = mouse;
	mouseDelta = delta;
	mouseWorldPos = camera->getWorldPos(mousePos.x, mousePos.y, node);
}

void Engine::keyboardEvent(unsigned int _key, bool _isDown)
{
	unsigned int key	= _key;
	bool isDown			= _isDown;

	m_currentKeyBinding = std::make_pair(_key, _isDown);
	int i = 42;

	switch(m_currentKeyBinding.first)
	{
	case Key::STATE_ROTATE:
	case Key::STATE_MOVE:
	case Key::STATE_SCALE:		
	case Key::STATE_PLACE:	
		setSelctorTool();
		break;

	case Key::STATE_TERRAIN:
		setElevationTool();
		break;
		
	case Key::STATE_FOLLOW_TERRAIN:
		moveObjectToTerrainHeight(); // go back to previous state? Might be a good idea you know...
		break;

	default:
		m_currentKeyBinding = std::make_pair( (unsigned int)Key::NO_STATE, true);
		break;

	 }
}
void Engine::findMinMaxValues()
{
	minmaxCalcDone = false;
	minmaxCalc = std::thread(&Terrain::findMinMaxValues, terrain, std::ref(leafNodes));
	minmaxCalc.detach();
	minmaxCalcDone = true;
}

void Engine::pickRay(POINT _xy, elm::vec3& _outRayDir, elm::vec3& _outRayOrigin)
{
	// Compute the vector of the pick ray in screen space
    elm::vec3 v;
	v.x =  (((2.f * (float)_xy.x) / (float)dx->camera->width) - 1.f) /  dx->camera->mProj._11;
	v.y = -(((2.f * (float)_xy.y) /  (float)dx->camera->height) - 1.f) /  dx->camera->mProj._22;
    v.z =  1.f;

    // Get the inverse view matrix
    elm::mat4 m = elm::inverse( dx->camera->mView);

	// Transform the screen space pick ray into 3D space
    _outRayDir.x  = v.x * m._11 + v.y * m._21 + v.z * m._31;
    _outRayDir.y  = v.x * m._12 + v.y * m._22 + v.z * m._32;
    _outRayDir.z  = v.x * m._13 + v.y * m._23 + v.z * m._33;

	_outRayDir = elm::normalize(_outRayDir);
	_outRayOrigin = m.r[3].xyz;

	// calc origin as intersection with near frustum
	_outRayOrigin += _outRayDir;
}

bool rayVsAABB(elm::vec3 rayDirFrac, elm::vec3 rayOrig, elm::vec3 min, elm::vec3 max)
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

void Engine::selectObject()
{
	elm::vec3 vPickRayDir, vPickRayOrig;
	pickRay(mousePos, vPickRayDir, vPickRayOrig);

	for( auto &c : dx->g_comps )
	{
		Object3D* object = c.getProperty<Object3D>();

		if(!object)
			continue;

		// min max to world
		elm::vec3 min, max;
		min = dx->g_meshes[object->getMeshID()]->getMinVertex() * object->getScale() + object->getPosition();
		max = dx->g_meshes[object->getMeshID()]->getMaxVertex() * object->getScale() + object->getPosition();

		if( rayVsAABB(1.f / vPickRayDir, vPickRayOrig, min, max) )
		{
			m_selectedObject = &c;
		}
		else
		{
			c.setSelected(false);
		}
	}

	if(m_selectedObject != nullptr)
		m_selectedObject->setSelected(true);
}

void Engine::scaleObject()
{
	if(!m_selectedObject)
		return;

	elm::vec3 vPickRayDir, vPickRayOrig;
	pickRay(mousePos, vPickRayDir, vPickRayOrig);

	Object3D* object = m_selectedObject->getProperty<Object3D>();

	if(!object)
		return;

	//min max to world
	elm::vec3 min, max;
	min = dx->g_meshes[object->getMeshID()]->getMinVertex() * object->getScale() + object->getPosition();
	max = dx->g_meshes[object->getMeshID()]->getMaxVertex() * object->getScale() + object->getPosition();

	if( rayVsAABB(1.f / vPickRayDir, vPickRayOrig, min, max) )
	{
		float xDiff, yDiff;
		xDiff = mousePos.x - oldMousePos.x;
		yDiff = mousePos.y - oldMousePos.y;

		elm::vec3 nscale = elm::vec3( (xDiff + yDiff) / 10.f ) + object->getScale();

		float min = 0.1f;
		float max = 5.0f;
		if(nscale.x > max || nscale.y > max ||nscale.z > max)
			nscale = elm::vec3(max);
		if(nscale.x < min || nscale.y < min || nscale.z < min)
			nscale = elm::vec3(min);

		object->setScale( nscale );
	}
}

void Engine::rotateObject()
{
	if(!m_selectedObject)
		return;

	elm::vec3 vPickRayDir, vPickRayOrig;
    pickRay(mousePos, vPickRayDir, vPickRayOrig);

	Object3D* object = m_selectedObject->getProperty<Object3D>();

	if(!object)
		return;

	//min max to world
	elm::vec3 min, max;
	min = dx->g_meshes[object->getMeshID()]->getMinVertex() * object->getScale() + object->getPosition();
	max = dx->g_meshes[object->getMeshID()]->getMaxVertex() * object->getScale() + object->getPosition();

	//if( rayVsAABB(1.f / vPickRayDir, vPickRayOrig, min, max) )
	{
		float xDiff, yDiff;
		xDiff = mousePos.x - oldMousePos.x;
		yDiff = mousePos.y - oldMousePos.y;

		elm::vec3 nrot = elm::vec3(xDiff, yDiff, 0) / 10.f;
		object->setRotation( nrot + object->getRotation() );
	}
}

void Engine::moveObject()
{
	if(!m_selectedObject)
		return;

	elm::vec3 vPickRayDir, vPickRayOrig;
	pickRay(mousePos, vPickRayDir, vPickRayOrig);

	Object3D* object = m_selectedObject->getProperty<Object3D>();

	if(!object)
		return;

	//min max to world
	elm::vec3 min, max;
	min = dx->g_meshes[object->getMeshID()]->getMinVertex() * object->getScale() + object->getPosition();
	max = dx->g_meshes[object->getMeshID()]->getMaxVertex() * object->getScale() + object->getPosition();

	if( rayVsAABB(1.f / vPickRayDir, vPickRayOrig, min, max) )
	{
		float xDiff, yDiff;
		xDiff = mousePos.x - oldMousePos.x;
		yDiff = mousePos.y - oldMousePos.y;

		elm::vec3 dpos = elm::vec3(xDiff, 0, -yDiff);
		elm::vec3 npos = object->getPosition() + dpos;

		if( object->getIsFollowingTerrain())
			npos.y = terrain->getHeightAt(npos.xz);
		object->setPosition( npos );
	}
}

void Engine::moveObjectToTerrainHeight()
{
	if(!m_selectedObject)
		return;

	Object3D* object = m_selectedObject->getProperty<Object3D>();

	elm::vec3 v = object->getPosition();
	v.y = terrain->getHeightAt(object->getPosition().xz);
	object->setPosition(v);
	object->setIsFollowingTerrain(true);
	// get terrainheight and set object to this height.
	// maybe we need to set an object property so that it follows terrain when terrain is changed

	renderScene();
}

void Engine::placeObject(unsigned int _objectId)
{
	unsigned int id = dx->g_meshes.size()-1;
	elm::vec3 min, max;


	Object3D *obj = new Object3D();
	obj->setMeshID(id);
	obj->setPosition( elm::vec3(mouseWorldPos.x, 100, mouseWorldPos.z) );
	obj->setScale(elm::vec3(.2f,.2f,.2f));

	dx->g_objects.push_back(obj);

	CModel<Object3D>* co = new CModel<Object3D>("newObject", obj);

	Composition c;
	//dx->g_comps.push_back(Composition());
	c.setName("test");
	c.setProperty(co);
	dx->g_comps.push_back(c);

	//if(m_selectedObject != nullptr)
	//	m_selectedObject->setSelected(false);

	m_selectedObject = &dx->g_comps[ dx->g_comps.size() - 1 ];
	m_selectedObject->setSelected(true);
}

Engine::~Engine()
{
	SAFE_DELETE(dx);
	SAFE_DELETE(node);
	SAFE_DELETE(camera);
	SAFE_DELETE(terrain);
}