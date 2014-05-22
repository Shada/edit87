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
	m_iconSize		= elm::vec2(_iconDimension.x / screenWidth * 2, _iconDimension.y / screenHeight * 2);
	m_numIcons		= _numIcons;
	radius			= _radius;
	m_origin		= elm::vec2(0);

	m_selectedToolFunction	= -1;
	m_icons.clear();

	for(int i = 0; i < m_numIcons; i++)
	{
		elm::vec2 p( (int)(radius * std::sin(i * rad)), (int)(radius * std::cos(i * rad)));
		float x = p.x / screenWidth * 2.f;
		float y = p.y / screenHeight * 2.f;
		elm::vec2 scrnp = elm::vec2(x,y);
		IIcon icon(scrnp, m_iconSize, radius, i % 2);

		m_icons.push_back(icon);
	}
}

void IRadial::setSpawn(elm::vec2 _origin)
{
	m_origin = elm::vec2(_origin.x / screenWidth * 2 - 1, _origin.y / screenHeight * 2 - 1);
}

void IRadial::select(elm::vec2 _mouse)
{
	elm::vec2 scrnm = elm::vec2(_mouse.x / screenWidth * 2 - 1, _mouse.y / screenHeight * 2 - 1);
	elm::vec2 scrno = m_origin;

	bool selected;
	for(IIcon& icon : m_icons)
	{
		selected = icon.collide(scrnm, scrno);
		//if(selected)
		//	break;
	}

	//update quad buffer
	if(m_toolBufferId == -1)
	{
		elm::vec4 p(m_origin.x, m_origin.y, m_iconSize.x, m_iconSize.y);
		dxPtr->createBuffer((void**)&p, m_icons.size(), sizeof(IIcon), m_toolBufferId, true);
	}
	else
	{
		D3D11_MAPPED_SUBRESOURCE resource;
		HRESULT hr = dxPtr->g_deviceContext->Map(dxPtr->g_buffers.at(m_toolBufferId), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

		if(FAILED(hr))
			MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

		elm::vec4 p(m_origin.x, m_origin.y, m_iconSize.x, m_iconSize.y);
		memcpy(resource.pData, (void**)&p, sizeof(IIcon));

		dxPtr->g_deviceContext->Unmap(dxPtr->g_buffers.at(m_toolBufferId), 0);
	}
}

void IRadial::draw()
{
	if(m_state == RState::HIDE || m_toolBufferId == -1)
		return;

	dxPtr->g_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);

	unsigned int stride = sizeof(IIcon);
	unsigned int offset = 0;
	
	dxPtr->g_deviceContext->VSSetShader(dxPtr->g_toolVS, NULL, 0);
	dxPtr->g_deviceContext->GSSetShader(dxPtr->g_toolGS, NULL, 0);
	dxPtr->g_deviceContext->PSSetShader(dxPtr->g_toolPS, NULL, 0);
	dxPtr->g_deviceContext->IASetInputLayout(dxPtr->g_billboardlayout);

	dxPtr->g_deviceContext->IASetVertexBuffers(0, 1, &dxPtr->g_buffers.at(m_toolBufferId), &stride, &offset);

	for(IIcon& icon : m_icons)
	{
		icon.updateShader(dxPtr);
		dxPtr->g_deviceContext->Draw(1, 0);
	}

	dxPtr->g_deviceContext->GSSetShader(NULL, NULL, 0);
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
	// check for icon selection
	select(m_mouse);

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