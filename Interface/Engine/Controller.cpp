#include "Controller.h"

D3D11_INPUT_ELEMENT_DESC standardLayout[] =
{
	{ "POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL",		0, DXGI_FORMAT_R32G32B32_FLOAT, 0, sizeof(float) * 3, D3D11_INPUT_PER_VERTEX_DATA, 0},
	{ "TEXCOORD",	0, DXGI_FORMAT_R32G32_FLOAT,	0, sizeof(float) * 6, D3D11_INPUT_PER_VERTEX_DATA, 0}
};

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

bool Controller::init(RenderDX11* _renderer, string _workingDirectory)
{
	m_terrain = new Terrain();
	HRESULT hr;
	bool res;

	if(!_renderer)					// no rendering available, go home
		return false;
	if(_workingDirectory == "")		// dont set the current environment as a working directory you bozo
		return false;

	m_pWorkingDirectory	= _workingDirectory;
	m_renderer			= _renderer;

	/*	--- Overview of how the data linking and abstraction works --- 

		Property { struct<T>[] }				--- Refs by Id (explicit) --->				Resources<T>[Id]
		Composition { Interface<Property>[] }	--- Refs by Datatype (Id is implicit) --->	Property<T>[Id]

		LLC: Create raw data
		MLL: Create 'property struct', link to desired raw data
		HLC: Create 'composition struct', link to all desired properties		(note: as of now only one property per type is allowed)
	*/

	/************************
		LOW LEVEL CREATION 
	*************************/

	/* init default render resources  */
	
	// blendstates
	unsigned int ref;
	hr = createBlendState(ref, D3D11_BLEND_ONE, D3D11_BLEND_ONE, D3D11_BLEND_ONE, TRUE);
	hr = createBlendState(ref, D3D11_BLEND_ONE, D3D11_BLEND_ONE, D3D11_BLEND_ONE, FALSE);
	hr = createBlendState(ref, D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA, D3D11_BLEND_SRC_ALPHA, TRUE);

	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory( &sampDesc, sizeof(sampDesc));
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

	hr = createSamplerState(ref, sampDesc);

	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	hr = createSamplerState(ref, sampDesc);

	// cbuffers
	unsigned onceRef, changeRef;
	hr = createCBuffer(onceRef, sizeof(CBOnce));
	hr = createCBuffer(changeRef, sizeof(CBOnChange));

	m_renderer->cbOnceID		= onceRef;
	m_renderer->cbOnChangeID	= changeRef;

	// shaders
	unsigned int vRef, pRef;
	hr = createShader<ID3D11VertexShader>(vRef, standardLayout, "defaultVS", "vs_4_0");
	hr = createShader<ID3D11PixelShader>(pRef, standardLayout, "defaultPS", "ps_4_0");

	// SRV's
	hr = createSRV(ref, "grass.png");
	hr = createSRV(ref, "bozo.jpg");

	/***************************
		MEDIUM LEVEL LINKING
	****************************/

	/* Init default properties */
	unsigned int sRef, mRef, tRef;
	// Shader
	Shader*			s	= new Shader(vRef, pRef);
	CModel<Shader>* cs	= new CModel<Shader>("default_shader", s);
	
	// Mesh
	createCube(vRef, pRef);	// notice reuse of paramaters
	Mesh*			m	= new Mesh(vRef, pRef, 36, ref);
	CModel<Mesh>*	cm	= new CModel<Mesh>("default_mesh", m);

	// Transform
	Transform*			t	= new Transform(elm::vec3(100,100,100), elm::vec3(0), elm::vec3(10));
	CModel<Transform>*	ct	= new CModel<Transform>("default_transform", t);

	/* register properties */
	addProperty(cs);
	addProperty(cm);
	addProperty(ct);

	/*****************************
		HIGH LEVEL COMPOSITION
	******************************/

	// Composition
	Composition* c = new Composition();
	c->setName("default_object");

	c->setProperty<Shader>(cs);
	c->setProperty<Mesh>(cm);
	c->setProperty<Transform>(ct);

	addComposition(c);

	return true;
}

bool Controller::createTerrain(int width, int height, float pointStep, bool fromPerlinMap)
{
	HRESULT hr;
	unsigned int vRef, iRef;
	vector<unsigned int> indexBuffer;
	vector<Vertex> vertexBuffer;

	m_terrain->createTerrain(width, height, pointStep, fromPerlinMap, vertexBuffer, indexBuffer);

	int w = abs(m_renderer->r.right - m_renderer->r.left);
	int h = abs(m_renderer->r.bottom - m_renderer->r.top);
	if(!m_renderer->camera)
		m_renderer->camera = new Camera(w, h, m_terrain);
	else
		m_renderer->camera->resizeWindow(w, h);

	hr = createBuffer<Vertex>(vRef, vertexBuffer, D3D11_BIND_VERTEX_BUFFER, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE);
	if( FAILED(hr) )
		return false;

	hr = createBuffer<unsigned int>(iRef, indexBuffer, D3D11_BIND_INDEX_BUFFER, D3D11_USAGE_IMMUTABLE);
	if( FAILED(hr) )
		return false;

	/* construct mesh */
	Mesh*			m	= new Mesh(vRef, iRef, indexBuffer.size(), 0);
	CModel<Mesh>*	im	= new CModel<Mesh>("terrain_mesh", m);
	addProperty(im);

	/* construct shader */
	Shader*			s	= new Shader();
	CModel<Shader>* sm	= new CModel<Shader>("terrain_shader", s);
	addProperty(sm);

	/* construct transformation */
	Transform*			t	= new Transform();
	CModel<Transform>*	tm	= new CModel<Transform>("terrain_transform", t);
	addProperty(tm);

	/* construct composition */
	Composition* c = new Composition();
	
	c->setProperty<Mesh>(im);
	c->setProperty<Shader>(sm);
	c->setProperty<Transform>(tm);

	c->setName("terrain_object");
	addComposition(c);

	/* for fun create a mini duplicate */
	//t = new Transform(elm::vec3(200,500,200), elm::vec3(0), elm::vec3(0.25));
	t = new Transform(elm::vec3(50,100,100), elm::vec3(0), elm::vec3(0.25));
	tm	= new CModel<Transform>("terrain_transform", t);

	m	= new Mesh(vRef, iRef, indexBuffer.size(), 1);
	im	= new CModel<Mesh>("terrain_mesh", m);
	addProperty(im);

	c = new Composition();
	c->setProperty<Mesh>(im);
	c->setProperty<Shader>(sm);
	c->setProperty<Transform>(tm);
	addComposition(c);

	return true;
}

bool Controller::addComposition(Composition* _composition)
{
	m_compositions[_composition->getId()] = _composition;	/* this needs to be changed, otherwise duplicates ahoy! */

	return true;
}

bool Controller::addProperty(IModel* _model)
{
	if(!_model)
		return false;

	if( m_properties.count( _model->getId() ) > 0 )
	{
		delete _model;
		return false;
	}

	m_properties[ _model->getId() ] = _model;

	return true;
}

template<typename T>
HRESULT Controller::createBuffer(unsigned int& _outId, std::vector<T>& _data, 
							D3D11_BIND_FLAG _bindFlag, D3D11_USAGE _usage, D3D11_CPU_ACCESS_FLAG _accessFlag)
{
	HRESULT hr;

	ID3D11Buffer* b = nullptr;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

	bd.Usage			= _usage;
    bd.ByteWidth		= sizeof(T) * _data.size();
    bd.BindFlags		= _bindFlag;
    bd.CPUAccessFlags	= _accessFlag;
	bd.MiscFlags		= 0;

	D3D11_SUBRESOURCE_DATA initData;

	initData.pSysMem			= &_data.at(0);
	initData.SysMemPitch		= 0;
	initData.SysMemSlicePitch	= 0;

	hr = m_renderer->g_device->CreateBuffer(&bd, &initData, &b);

	if(FAILED(hr))
	{
        MessageBox(NULL,"could not create vertexbuffer", "ERROR", S_OK);
		_outId = 0;	/* point to default buffer */
		return hr;
	}
	
	_outId				= m_buffers.size();
	m_buffers[_outId]	= b;

	return S_OK;
}

HRESULT Controller::createBlendState(unsigned int& _outId, D3D11_BLEND _srcBlend, D3D11_BLEND _destBlend, D3D11_BLEND _srvBlendAlpha, bool _enable)
{
	HRESULT hr;

	ID3D11BlendState* blendState = nullptr;

	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc,sizeof(blendDesc));
	blendDesc.RenderTarget[0].BlendEnable			= _enable;
	blendDesc.RenderTarget[0].SrcBlend				= _srcBlend;
    blendDesc.RenderTarget[0].DestBlend				= _destBlend;
    blendDesc.RenderTarget[0].BlendOp				= D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].SrcBlendAlpha			= _srvBlendAlpha;
    blendDesc.RenderTarget[0].DestBlendAlpha		= D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].BlendOpAlpha			= D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].RenderTargetWriteMask = 0x0f;

	hr = m_renderer->g_device->CreateBlendState(&blendDesc, &blendState);
    if(FAILED(hr))
	{
		MessageBox(m_renderer->hWnd, "blendenable made fail, lol", "fail, yo", 0);
		_outId = 0;		/* point to default blend */ 
        return hr;
	}

	_outId					= m_blendStates.size();
	m_blendStates[_outId]	= blendState;

	return S_OK;
}

HRESULT Controller::createCBuffer(unsigned int& _outId, unsigned int _sizeOf)
{
	HRESULT hr;
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage			= D3D11_USAGE_DEFAULT;
	bd.ByteWidth		= _sizeOf;
	bd.BindFlags		= D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags	= 0;

	ID3D11Buffer *b = nullptr;
	hr				= m_renderer->g_device->CreateBuffer(&bd, NULL, &b);

	if(FAILED(hr))
	{
		_outId = 0;	/* not a good solution */
		return hr;
	}

	_outId				= m_buffers.size();
	m_buffers[_outId]	= b;

	return S_OK;
}

template<typename T>
HRESULT Controller::createShader(unsigned int& _outId, const D3D11_INPUT_ELEMENT_DESC _layout[],
								string _shaderName, string _shaderModel)
{
	HRESULT hr;
	ID3DBlob *blob;
	ID3D11InputLayout* layout = nullptr;

	string fullPath;
	string model;

	T* shader = nullptr;

	/* Vertex */
	if(_shaderName != "")
	{
		fullPath	= m_pWorkingDirectory + "Shaders/" + _shaderName + ".hlsl";

		hr = m_renderer->compileShader(fullPath.c_str(), _shaderModel.c_str(), &blob);

		if(FAILED(hr))
			return hr;

		/* work out what kind of shader we want to construct 
			- yes I know, it's not a pretty solution */
		if( typeid(T) == typeid(ID3D11VertexShader) )
			hr = m_renderer->g_device->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &(ID3D11VertexShader*&)shader);
		else if( typeid(T) == typeid(ID3D11GeometryShader) )
			hr = m_renderer->g_device->CreateGeometryShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &(ID3D11GeometryShader*&)shader);
		else if( typeid(T) == typeid(ID3D11PixelShader) )
			hr = m_renderer->g_device->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &(ID3D11PixelShader*&)shader);
		else
			return S_FALSE;

		if(FAILED(hr))
			return hr;

		if( typeid(T) == typeid(ID3D11VertexShader) )
		{
			hr = m_renderer->g_device->CreateInputLayout(_layout, ARRAYSIZE(standardLayout), 
													blob->GetBufferPointer(), blob->GetBufferSize(), &layout);

			m_layouts[0] = layout;

			if(FAILED(hr))
				return hr;
		}
		blob->Release();

		if( typeid(T) == typeid(ID3D11VertexShader) )
		{
			_outId = m_vertexShaders.size();
			m_vertexShaders[_outId] = (ID3D11VertexShader*&)shader;
		}
		else if( typeid(T) == typeid(ID3D11GeometryShader) )
		{
			_outId = m_geometryShaders.size();
			m_geometryShaders[_outId] = (ID3D11GeometryShader*&)shader;
		}
		else if( typeid(T) == typeid(ID3D11PixelShader) )
		{
			_outId = m_pixelShaders.size();
			m_pixelShaders[_outId] = (ID3D11PixelShader*&)shader;
		}
		else	// this shouldn't be able to happen
		{
			return S_FALSE;
		}
	}

	return S_OK;
}


HRESULT Controller::createSRV(unsigned int& _outId, string _fileName)
{
	HRESULT hr;

	string fullPath					= m_pWorkingDirectory + "Textures/" +  _fileName;
	ID3D11ShaderResourceView *tex	= nullptr;	

	hr = m_renderer->createSRV(fullPath.c_str(), tex);

	if(FAILED(hr))
	{
		MessageBox(m_renderer->hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
	}
	
	_outId			= m_SRVs.size();
	m_SRVs[_outId]	= tex;

	return S_OK;
}

HRESULT Controller::createSamplerState(unsigned int& _outId, D3D11_SAMPLER_DESC _desc)
{
	HRESULT hr;
	ID3D11SamplerState* sampler = nullptr;

	hr = m_renderer->g_device->CreateSamplerState(&_desc, &sampler);

	if( FAILED(hr) )
	{
		MessageBox(m_renderer->hWnd, "Error creating sampler state", "ERROR", MB_OK);
		return hr;
	}

	_outId = m_samplerStates.size();
	m_samplerStates[_outId] = sampler;

	return S_OK;
}

void Controller::draw()
{
	m_renderer->setupScene( m_blendStates[1], m_layouts[0] );
	m_renderer->g_deviceContext->PSSetSamplers(0, 1, &m_samplerStates[0]);

	for(auto c : m_compositions)
	{
		Mesh*		mm	= c.second->getProperty<Mesh>();
		Transform*	mt	= c.second->getProperty<Transform>();
		Shader*		ms	= c.second->getProperty<Shader>();

		if(!mm || !ms)
			continue;

		/* need some better rules for this */

		/* link shaders */
		if(ms)
			m_renderer->setShaders(m_vertexShaders[ms->m_vRef], nullptr, m_pixelShaders[ms->m_pRef]);

		///* push transformation */
		if(mt)
			m_renderer->setTransformation(m_buffers[1], mt->m_scale, mt->m_rotate, mt->m_translate);

		///* push srv and draw */
		if(mm)
			m_renderer->drawMesh(m_buffers[mm->m_vBufferRef], m_SRVs[mm->m_SRVRef], mm->m_iCount, m_buffers[mm->m_iBufferRef]);
	}

	
	m_renderer->g_swapChain->Present(0, 0);
}

HRESULT Controller::createCube(unsigned int& _vId, unsigned int& _iId)
{
	HRESULT hr;
	std::vector<Vertex> vertices;
	elm::vec3 pos[8] = {	elm::vec3(-1,1,1), elm::vec3(-1,-1,1), elm::vec3(1,-1,1), elm::vec3(1,1,1),
							elm::vec3(-1,1,-1), elm::vec3(-1,-1,-1), elm::vec3(1,-1,-1), elm::vec3(1,1,-1) };

	// vertex culling issues, some vertices backwards
	unsigned int ind[36]	= {		0,1,2,	0,2,3,	// front
									4,5,6,	4,6,7,	// back
									4,5,1,	4,1,0,	// left
									7,6,2,	7,2,3,	// right
									4,0,3,	4,3,7,	// top
									5,1,2,	5,2,6	// bottom
									};

	elm::vec2 uv[4]		= {		elm::vec2(0), elm::vec2(0,1), elm::vec2(1), elm::vec2(1,0) };	// not correct, too lazt to fix


	for(int i = 0; i < 8; i++)
	{
		Vertex v;
		v.pos		= pos[i];
		v.normal	= elm::vec3(1);	// no normal calculations
		v.texCoord	=uv[i%4];

		vertices.push_back(v);
	}

	std::vector<unsigned int> indices(std::begin(ind), std::end(ind));

	hr = createBuffer<Vertex>(_vId, vertices, D3D11_BIND_VERTEX_BUFFER, D3D11_USAGE_IMMUTABLE);

	if(FAILED(hr))
		return hr;

	hr = createBuffer<unsigned int>(_iId, indices, D3D11_BIND_INDEX_BUFFER, D3D11_USAGE_IMMUTABLE);

	if(FAILED(hr))
		return hr;

	return S_OK;
}