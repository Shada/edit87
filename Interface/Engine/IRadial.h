#pragma once

#include <vector>

using std::vector;

#include "../elm/elm.hpp"
#include "ObjectTool.h"
#include "RenderDX11.h"

#include "IIcon.h"

enum class Tools;

enum class RState
{
	OPEN,
	CLOSE,
	SELECT,
	HIDE
};

struct Icon
{
	elm::vec2	m_pos;
	elm::vec2	m_size;
	elm::vec4	m_color;
};

class IRadial
{
public:
	IRadial(void);
	virtual ~IRadial(void);

	virtual void init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, RenderDX11* _dx) = 0;

	void select(elm::vec2 _mouse, bool _leftMouseDown);
	void draw();

	virtual void update(bool _leftMouseDown) = 0;
	void setState(RState _state);

	void setSpawn(elm::vec2 _origin);

	RState getState()
	{ return m_state; }

protected:
	int				m_toolBufferId;
	vector<IIcon>	m_icons;
	elm::vec2		m_iconSize;
	elm::vec2		m_origin;

	float screenWidth, screenHeight;
	elm::vec2			m_mouse;
	float				radius;
	int					m_numIcons;
	RState				m_state;
	RenderDX11*			dxPtr;
	int					m_selectedToolFunction;
	elm::vec4			m_defColor;
	elm::vec3			m_axis;
};

class ObjectRadial
	: public IRadial
{
public:
	ObjectRadial(ObjectTool* _tool);

	void update(bool _leftMouseDown) override;
	void init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, RenderDX11* _dx) override;

private:
	ObjectTool*	m_tool;
};

class TerrainRadial
	: public IRadial
{
public:
	TerrainRadial(Tools* _toolPtr);

	void update(bool _leftMouseDown) override;
	void setWorldPos(elm::vec3 _worldPos)
	{ m_mouseWorldPos = _worldPos; }
	void init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, RenderDX11* _dx) override;
private:

	elm::vec3	m_mouseWorldPos;
	Tools*		m_selectedTool;
};