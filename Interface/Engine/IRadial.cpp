#include "IRadial.h"
#include "Engine.h"

IRadial::IRadial(void)
{
	m_toolBufferId = -1;
}


IRadial::~IRadial(void)
{
}

void IRadial::init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, float _width, float _height, RenderDX11* _dx)
{
	dxPtr			= _dx;
	m_state			= RState::HIDE;
	screenWidth		= _width;
	screenHeight	= _height;
	float rad		= 360.f / _numIcons * 0.0174532925f;
	m_iconSize		= _iconDimension;
	m_numIcons		= _numIcons;
	radius			= _radius;
	m_origin		= elm::vec2(0);

	m_selectedToolFunction	= -1;
}

void IRadial::setSpawn(elm::vec2 _origin)
{
	m_origin = _origin;
}

void IRadial::select(elm::vec2 _mouse)
{
	if(m_state != RState::SELECT)
		return;

	m_mouse		= _mouse;
	float rad	= 360.f / m_numIcons * 0.0174532925f;

	m_icons.clear();

	for(int i = 0; i < m_numIcons; i++)
	{
		elm::vec2 p( (int)(radius * std::sin(i * rad)), (int)(radius * std::cos(i * rad)));
		
		Icon icon;

		icon.m_pos	= elm::vec2((p.x + m_origin.x) / screenWidth * 2 - 1, -((p.y + m_origin.y) / screenHeight * 2 - 1));
		icon.m_size	= elm::vec2(m_iconSize.x / screenWidth * 2, m_iconSize.y / screenHeight * 2);

		elm::vec2 m = elm::vec2(m_mouse.x / screenWidth * 2 - 1, m_mouse.y / screenHeight * 2 - 1);
		if(	m.x > (icon.m_pos.x - icon.m_size.x) && m.x < (icon.m_pos.x + icon.m_size.x) &&
			-m.y > (icon.m_pos.y - icon.m_size.y) && -m.y < (icon.m_pos.y + icon.m_size.y) )
		{
			icon.m_color = m_defColor;
			m_selectedToolFunction = i;
		}
		else icon.m_color = elm::vec4(1);

		m_icons.push_back( icon );
	}

	if(m_toolBufferId == -1)
	{
		dxPtr->createBuffer((void**)&m_icons[0], m_icons.size(), sizeof(Icon), m_toolBufferId, true);
	}
	else
	{
		D3D11_MAPPED_SUBRESOURCE resource;
		HRESULT hr = dxPtr->g_deviceContext->Map(dxPtr->g_buffers.at(m_toolBufferId), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

		if(FAILED(hr))
			MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

		memcpy(resource.pData, (void**)&m_icons[0], sizeof(Icon) * m_icons.size());

		dxPtr->g_deviceContext->Unmap(dxPtr->g_buffers.at(m_toolBufferId), 0);
	}
}

void IRadial::draw()
{
	if(m_state != RState::HIDE && m_toolBufferId != -1)
	{
		dxPtr->g_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);

		unsigned int stride = sizeof(Icon);
		unsigned int offset = 0;

		dxPtr->g_deviceContext->VSSetShader(dxPtr->g_toolVS, NULL, 0);
		dxPtr->g_deviceContext->GSSetShader(dxPtr->g_toolGS, NULL, 0);
		dxPtr->g_deviceContext->PSSetShader(dxPtr->g_toolPS, NULL, 0);
		dxPtr->g_deviceContext->IASetInputLayout(dxPtr->g_billboardlayout);

		dxPtr->g_deviceContext->IASetVertexBuffers(0, 1, &dxPtr->g_buffers.at(m_toolBufferId), &stride, &offset);

		dxPtr->g_deviceContext->Draw(m_icons.size(), 0);

		dxPtr->g_deviceContext->GSSetShader(NULL, NULL, 0);
	}
}

void IRadial::setState(RState _state)
{
	m_state = _state;
}

ObjectRadial::ObjectRadial(ObjectTool* _tool)
{
	m_tool = _tool;
	m_defColor = elm::vec4(1,0,0,1);
}

void ObjectRadial::update()
{
	switch(m_selectedToolFunction)
	{
	case 0:
		// translate
		m_tool->setState(OTState::TRANSLATE);
		m_tool->setAxis( elm::vec3(1,0,1) ); 
		setState(RState::HIDE);
		break;
	case 1:
		// scale
		m_tool->setState(OTState::SCALE);
		m_tool->setAxis( elm::vec3(1) ); 
		setState(RState::HIDE);
		break;
	case 2:
		// rotate
		m_tool->setState(OTState::ROTATE);
		m_tool->setAxis( elm::vec3(0,1,0) ); 
		setState(RState::HIDE);
		
		break;
	default:
		m_tool->setState(OTState::NONE);
		m_tool->setAxis( elm::vec3(0) ); 
		break;
	}
	m_selectedToolFunction = -1;
}

TerrainRadial::TerrainRadial(Tools* _toolPtr)
{
	m_defColor		= elm::vec4(0,1,0,1);
	m_selectedTool	= _toolPtr;
}

void TerrainRadial::update()
{

	switch(m_selectedToolFunction)
	{
	case 0:
		// raise
		*m_selectedTool = Tools::ELEVATION;
		setState(RState::HIDE);
		break;
	case 1:
		// lower

		setState(RState::HIDE);
		break;
	case 2:
		// equalise

		setState(RState::HIDE);
		
		break;
	default:
		*m_selectedTool = Tools::SELECTOR;
		break;
	}
	m_selectedToolFunction = -1;
}