#pragma once

#include "../elm/elm.hpp"
#include "RenderDX11.h"
#include "Event.h"
#include "ObjectTool.h"

class SubIcon;

class IIcon
{
public:
	IIcon(elm::vec2 _offset, elm::vec2 _size, float _radius, int _textureId);
	virtual ~IIcon(void);

	virtual void	update();
	virtual void	updateShader(RenderDX11* _dx);

	virtual bool	collide(elm::vec2 _mouse, elm::vec2 _origin);
	void			addSubIcon(int _textureId, elm::vec2 _offset, elm::vec2 _size);

	vector<SubIcon*>&	getSubIcons();
	elm::vec2			getOffset();

protected:
	elm::vec2			m_size;
	elm::vec2			m_offset;
	float				m_radius;
	unsigned int		m_textureId;
	bool				m_highlighted;
	
	vector<SubIcon*>	m_subIcons;
};

class SubIcon
	: public IIcon
{
public:
	SubIcon(elm::vec2 _offset, elm::vec2 _size, float _radius, int _textureId);
	~SubIcon(){}

	bool collide(elm::vec2 _mouse, elm::vec2 _origin) override;
	void setLeftMouseButton(bool _isDown);
private:
	bool m_isLeftMouseButton;
	ObjectTool*	m_tool;
	elm::vec3 m_axis;
};