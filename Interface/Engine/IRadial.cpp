#include "IRadial.h"
#include "Engine.h"


IRadial::IRadial(void)
{
	m_toolBufferId = -1;
}


IRadial::~IRadial(void)
{
}

void ObjectRadial::init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, RenderDX11* _dx)
{
	dxPtr			= _dx;
	m_state			= RState::HIDE;
	screenWidth		= (float)dxPtr->width;
	screenHeight	= (float)dxPtr->height;
	m_numIcons		= _numIcons;
	
	m_iconSize		= elm::vec2(_iconDimension.x / screenWidth * 2, _iconDimension.y / screenHeight * 2);

	radius			= _radius;
	m_origin		= elm::vec2(0);

	m_selectedToolFunction	= -1;
	m_icons.clear();

	float rad		= 360.f / m_numIcons * 0.0174532925f;
	for(int i = 0; i < m_numIcons; i++)
	{
		elm::vec2 p( (int)(radius * std::sin(i * rad)), (int)(radius * std::cos(i * rad)));
		float x = p.x / screenWidth * 2.f;
		float y = p.y / screenHeight * 2.f;
		elm::vec2 scrnp = elm::vec2(x,y);
		IIcon icon(scrnp, m_iconSize, radius, 1);

		m_icons.push_back(icon);	
	}

	float srad = 360.f / (3 * m_numIcons) * 0.0174532925f;
	for(int j = 0; j <  3; j++)
	{		
		elm::vec2 sp( (int)(radius * 2 * std::sin(j * srad)), (int)(radius * 2 * std::cos(j * srad)));
		float sx = sp.x / screenWidth * 2.f;
		float sy = sp.y / screenHeight * 2.f;

		m_icons[ m_icons.size() - 1 ].addSubIcon(1, elm::vec2(sx,sy), m_iconSize * 0.5);
	}
	
}

void TerrainRadial::init(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension, RenderDX11* _dx)
{
	dxPtr			= _dx;
	m_state			= RState::HIDE;
	screenWidth		= (float)dxPtr->width;
	screenHeight	= (float)dxPtr->height;
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
		IIcon icon(scrnp, m_iconSize, radius, 0);

		m_icons.push_back(icon);	
	}
}

void IRadial::setSpawn(elm::vec2 _origin)
{
	m_origin = elm::vec2(_origin.x / screenWidth * 2 - 1, _origin.y / screenHeight * 2 - 1);
}

void IRadial::select(elm::vec2 _mouse, bool _leftMouseDown)
{
	elm::vec2 scrnm = elm::vec2(_mouse.x / screenWidth * 2 - 1, _mouse.y / screenHeight * 2 - 1);
	elm::vec2 scrno = m_origin;

	bool selected;
	m_axis = elm::vec3(1);
	for(int i = 0; i < m_icons.size(); i++)
	{
		IIcon& icon = m_icons[i];

		selected = icon.collide(scrnm, scrno);
		
		if(selected)
		{	
			m_selectedToolFunction = i;
		}

		
		for(int j = 0; j < icon.getSubIcons().size(); j++)
		{
			SubIcon* sub = icon.getSubIcons()[j];
			sub->setLeftMouseButton(_leftMouseDown);
			bool res = selected = sub->collide(scrnm, scrno);

			if(!res)
				m_axis[j] = 0;
		}
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
	float blend[4] = { 0.5,0.5,0.5,0.5 };
	dxPtr->g_deviceContext->OMSetBlendState(dxPtr->g_blendAlpha, blend, 0xffffffff);
	dxPtr->g_deviceContext->VSSetShader(dxPtr->g_toolVS, NULL, 0);
	dxPtr->g_deviceContext->GSSetShader(dxPtr->g_toolGS, NULL, 0);
	dxPtr->g_deviceContext->PSSetShader(dxPtr->g_toolPS, NULL, 0);
	dxPtr->g_deviceContext->IASetInputLayout(dxPtr->g_billboardlayout);

	dxPtr->g_deviceContext->IASetVertexBuffers(0, 1, &dxPtr->g_buffers.at(m_toolBufferId), &stride, &offset);

	for(IIcon& icon : m_icons)
	{
		icon.updateShader(dxPtr);
		dxPtr->g_deviceContext->Draw(1, 0);

		for(IIcon* sub : icon.getSubIcons())
		{
			sub->updateShader(dxPtr);
			dxPtr->g_deviceContext->Draw(1, 0);
		}
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

void ObjectRadial::update(bool _leftMouseDown)
{
	if(m_state == RState::HIDE)
		return;

	// check for icon selection
	select(m_mouse, _leftMouseDown);
	m_tool->setAxis(m_axis);
	switch(m_selectedToolFunction)
	{
	case 0:
		// translate
		m_tool->setState(OTState::TRANSLATE);
		setState(RState::HIDE);
		break;
	case 1:
		// scale
		m_tool->setState(OTState::SCALE); 
		setState(RState::HIDE);
		break;
	case 2:
		// rotate
		m_tool->setState(OTState::ROTATE);
		setState(RState::HIDE);
		
		break;
	case 3:
		// follow terrain
		m_tool->setState(OTState::FOLLOWTERRAIN);
		setState(RState::HIDE);
		break;
	default:
		m_tool->setState(OTState::NONE);
		break;
	}
	m_selectedToolFunction = -1;
}

TerrainRadial::TerrainRadial(Tools* _toolPtr)
{
	m_defColor		= elm::vec4(0,1,0,1);
	m_selectedTool	= _toolPtr;
}

void TerrainRadial::update(bool _leftMouseDown)
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