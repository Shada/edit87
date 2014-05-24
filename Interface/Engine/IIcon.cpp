#include "IIcon.h"



IIcon::IIcon(elm::vec2 _offset, elm::vec2 _size, int _textureId)
	: m_offset(_offset), m_size(_size), m_textureId(_textureId), m_highlighted(false)
{
	
}


IIcon::~IIcon(void)
{
}

void IIcon::update()
{

}

bool IIcon::collide(elm::vec2 _mouse, elm::vec2 _origin)
{
	elm::vec2 rPos = _origin + m_offset;

	if( _mouse.x > (rPos.x - m_size.x) && _mouse.x < (rPos.x + m_size.x) &&
		-_mouse.y > (rPos.y - m_size.y) && -_mouse.y < (rPos.y + m_size.y) )
	{
		m_highlighted = true;
	}
	else
	{
		m_highlighted = false;
	}

	return m_highlighted;
}

void IIcon::updateShader(RenderDX11* _dx)
{
	/* only push up instance specific data */

	// icon spec texture
	_dx->g_deviceContext->PSSetShaderResources(0, 1, &_dx->g_textures[m_textureId] );

	// icon spec buffer (select/unselect color + offset)
	CBIcon cicon;

	if(m_highlighted)
	{
		cicon.color	= elm::vec4(1);
	}
	else
	{
		cicon.color	= elm::vec4(0.25, 0.25, 0.25, 0.75);
	}

	cicon.positonOffset	= elm::vec4(m_offset.x, m_offset.y, 0, 0);
	cicon.dimension		= elm::vec4(m_size.x, m_size.y, 0, 0);

	_dx->g_deviceContext->UpdateSubresource(_dx->g_buffers[_dx->iconCBufferId], 0, NULL, &cicon, 0, 0);

	_dx->g_deviceContext->GSSetConstantBuffers(0, 1, &_dx->g_buffers[_dx->iconCBufferId]);
}

void IIcon::addSubIcon(int _textureId, elm::vec2 _offset, elm::vec2 _size)
{
	m_subIcons.push_back( new SubIcon(_offset, _size, _textureId) );
}

vector<SubIcon*>& IIcon::getSubIcons()
{
	return m_subIcons;
}

elm::vec2 IIcon::getOffset()
{
	return m_offset;
}

bool SubIcon::toggleHighlight()
{
	m_highlighted = !m_highlighted;
	//m_oldMouse	= m_isLeftMouseButton;
	return m_highlighted;
}


SubIcon::SubIcon(elm::vec2 _offset, elm::vec2 _size, int _textureId)
	: IIcon(_offset, _size, _textureId)
{

}