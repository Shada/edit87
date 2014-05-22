#pragma once

#include "../elm/elm.hpp"
#include "RenderDX11.h"

class IIcon
{
public:
	IIcon(elm::vec2 _offset, elm::vec2 _size, float _radius, int _textureId);
	virtual ~IIcon(void);

	void			addFunction();
	virtual void	update();
	virtual void	updateShader(RenderDX11* _dx);

	bool			collide(elm::vec2 _mouse, elm::vec2 _origin);

private:
	elm::vec2		m_size;
	elm::vec2		m_offset;
	float			m_radius;
	unsigned int	m_textureId;
	bool			m_highlighted;
};
