#include "RenderDX11.h"
#pragma comment(lib, "D3DX11.lib")
#include <D3DX11async.h>
#include <d3dcompiler.h>
#include "..\DirectXTex\DirectXTex.h"
#include "Utility.h"

RenderDX11::RenderDX11()
{
	terrainVertexBufferID = terrainIndexBufferID = -1;
	blendmap = new Blendmap();

	g_meshes = std::vector<Mesh3D*>(1, nullptr);
	g_objects = std::vector<Object3D*>(1);

	hWnd = nullptr;
}

void RenderDX11::addHandle(HWND _hWnd, std::string _name, int width, int height)
{
	Handle h;
	h.hwnd = _hWnd;
	h.name = _name;
	h.device = nullptr;
	h.deviceContext = nullptr;
	h.renderTargetView = nullptr;
	h.swapChain = nullptr;
	h.depthStencilView = nullptr;
	h.camera = nullptr;

	h.buffers = std::vector<ID3D11Buffer*>(2);
	h.textures = std::vector<ID3D11ShaderResourceView*>(2);

	handles.push_back(h);
	handles.back().buffers = std::vector<ID3D11Buffer*>(handles.at(0).buffers.size());

	init(handles.back(), width, height);

	if(_name == "main")
	{
		//primaryHandle = &handles.back();
		hWnd = _hWnd;
	}
}

void RenderDX11::updateHandle(HWND _hWnd, std::string _name, int width, int height)
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == _name)
		{
			handles.at(i).hwnd = nullptr;
			handles.at(i).hwnd = _hWnd;

			init(handles.at(i), width, height);
			break;
		}
	}
}

void RenderDX11::setCamera(Camera *cam, std::string name)
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == name)
		{
			handles.at(i).camera = cam;
			break;
		}
	}
}

void RenderDX11::resizeSurface(int width, int height, std::string _name)
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == _name)
		{
			init(handles.at(i), width, height);
			break;
		}
	}
}

HRESULT RenderDX11::init(Handle &h, int width, int height)
{
	HRESULT hr = S_OK;

	UINT createDeviceFlags = 0;

	D3D_DRIVER_TYPE driverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = (UINT)width;
    sd.BufferDesc.Height = (UINT)height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = h.hwnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    for(UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
		h.driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain(NULL, h.driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
                                           D3D11_SDK_VERSION, &sd, &h.swapChain, &h.device, &h.featureLevel, &h.deviceContext);
        if(SUCCEEDED(hr))
            break;
    }
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Swapchain made fail, lol", "fail, yo", 0);
        	return hr;
	}

	 // Create a render target view
    ID3D11Texture2D *pBackBuffer = NULL;
    hr = h.swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Backbuffer made fail, lol", "fail, yo", 0);
        	return hr;
	}

    hr = h.device->CreateRenderTargetView(pBackBuffer, NULL, &h.renderTargetView);
    SAFE_RELEASE(pBackBuffer);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Rendertargetview made fail, lol", "fail, yo", 0);
       	return hr;
	}

	// Create depth stencil texture
    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory(&descDepth, sizeof(descDepth));
    descDepth.Width = (UINT)width;
    descDepth.Height = (UINT)height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;

	ID3D11Texture2D *depthStencil = nullptr;
    hr = h.device->CreateTexture2D(&descDepth, NULL, &depthStencil);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "depthstencil made fail, lol", "fail, yo", 0);
		return hr;
	}

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory( &descDSV, sizeof(descDSV) );
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = h.device->CreateDepthStencilView(depthStencil, &descDSV, &h.depthStencilView);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "depthstencilview made fail, lol", "fail, yo", 0);
        	return hr;
	}

	SAFE_RELEASE(depthStencil);

	// Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.f;
    vp.MaxDepth = 1.f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    h.deviceContext->RSSetViewports(1, &vp);

    h.deviceContext->OMSetRenderTargets(1, &h.renderTargetView, h.depthStencilView);

	D3D11_RASTERIZER_DESC rasterDesc;

	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = true;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.f;

	// Create the rasterizer state from the description we just filled out.
	hr = h.device->CreateRasterizerState(&rasterDesc, &h.rasterizerState);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "rasterizerstate made fail, lol", "fail, yo", 0);
        	return hr;
	}

	// Now set the rasterizer state.
	h.deviceContext->RSSetState(h.rasterizerState);

	//create blendstates
	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc,sizeof(blendDesc));
	blendDesc.RenderTarget[0].BlendEnable = TRUE;
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].RenderTargetWriteMask = 0x0f;
	hr = h.device->CreateBlendState(&blendDesc, &h.blendEnable);
	
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "blendenable made fail, lol", "fail, yo", 0);
        	return hr;
	}

	blendDesc.RenderTarget[0].BlendEnable = FALSE;
	hr = h.device->CreateBlendState(&blendDesc, &h.blendDisable);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "blenddisable made fail, lol", "fail, yo", 0);
		return hr;
	}

	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	blendDesc.RenderTarget[0].BlendEnable = TRUE;
	hr = h.device->CreateBlendState(&blendDesc, &h.blendAlpha);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "blendalpha made fail, lol", "fail, yo", 0);
		return hr;
	}

	//create depthstencil states
	D3D11_DEPTH_STENCIL_DESC depthDesc;
	depthDesc.DepthEnable = TRUE;
	depthDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthDesc.StencilEnable = FALSE;
	depthDesc.StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
	depthDesc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;
	depthDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	depthDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	depthDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	depthDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	depthDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	hr = h.device->CreateDepthStencilState(&depthDesc, &h.depthStencilStateEnable);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "h.depthStencilStateEnable made fail, lol", "fail, yo", 0);
		return hr;
	}

	depthDesc.DepthEnable = FALSE;
	hr = h.device->CreateDepthStencilState(&depthDesc, &h.depthStencilStateDisable);
	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "h.depthStencilStateDisable made fail, lol", "fail, yo", 0);
        	return hr;
	}

	//create constant buffers
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(CBOnce);
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;

	ID3D11Buffer *b = nullptr;
	hr = h.device->CreateBuffer(&bd, NULL, &b);
	if(FAILED(hr))
		return hr;

	SAFE_RELEASE(h.buffers.at(0));
	cbOnceID = 0;
	h.buffers.at(0) = b;

	bd.ByteWidth = sizeof(CBOnChange);
	b = nullptr;
	hr = h.device->CreateBuffer(&bd, NULL, &b);
	if(FAILED(hr))
		return hr;

	SAFE_RELEASE(h.buffers.at(1));
	cbOnChangeID = 1;
	h.buffers.at(1) = b;

	D3D11_INPUT_ELEMENT_DESC standardLayout[] =
	{
		{ "POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "NORMAL",		0, DXGI_FORMAT_R32G32B32_FLOAT, 0, sizeof(float) * 3, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "TEXCOORD",	0, DXGI_FORMAT_R32G32_FLOAT,	0, sizeof(float) * 6, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	D3D11_INPUT_ELEMENT_DESC aLittleLessStandardLayout[] =
	{
		{ "POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "NORMAL",		0, DXGI_FORMAT_R32G32B32_FLOAT, 1, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "TEXCOORD",	0, DXGI_FORMAT_R32G32_FLOAT,	2, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	/* Create shaders */
	ID3DBlob *shaderBlob;
	compileShader("..\\Shaders\\defaultVS.hlsl", "vs_4_0", &shaderBlob);
	h.device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &h.terrainVS);
	h.device->CreateInputLayout(standardLayout, ARRAYSIZE(standardLayout), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &h.layout);
	shaderBlob->Release();

	compileShader("..\\Shaders\\defaultPS.hlsl", "ps_4_0", &shaderBlob);
	h.device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &h.terrainPS);

	shaderBlob->Release();

	hr = compileShader("..\\Shaders\\modelVS.hlsl", "vs_4_0", &shaderBlob);
	hr = h.device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &h.modelVS);
	hr = h.device->CreateInputLayout(aLittleLessStandardLayout, ARRAYSIZE(aLittleLessStandardLayout), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &h.otherlayout);
	shaderBlob->Release();

	hr = compileShader("..\\Shaders\\modelPS.hlsl", "ps_4_0", &shaderBlob);
	h.device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &h.modelPS);

	shaderBlob->Release();

	ID3D11ShaderResourceView *tex;

	hr = D3DX11CreateShaderResourceViewFromFile(h.device, "..\\Textures\\grass.png", NULL, NULL, &tex, NULL);
	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
	}

	SAFE_RELEASE(h.textures.at(0));
	h.textures.at(0) = tex;
	createSampleStates(h);

	if(!g_meshes.at(0))
	{
		Mesh3D *mesh = new Mesh3D();
		if(!mesh->loadMesh("../Models/Collada/cube.dae"))
		{
			MessageBoxA(hWnd, "Model load fail", "FAIL", 0);
		}
		g_meshes.at(0) = mesh;
	}

	int id = g_meshes[0]->getVertexBufferID();
	if(FAILED(createBuffer((void*)g_meshes[0]->getVertices().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id, h)))
	{
		MessageBox(this->hWnd, "VertexBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setVertexBufferID(id);
	id = g_meshes[0]->getNormalBufferID();
	if(FAILED(createBuffer((void*)g_meshes[0]->getNormals().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id, h)))
	{
		MessageBox(this->hWnd, "NormalBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setNormalBufferID(id);
	id = g_meshes[0]->getTexCoordBufferID();
	if(FAILED(createBuffer((void*)g_meshes[0]->getTexCoords().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id, h)))
	{
		MessageBox(this->hWnd, "TexCoordsBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setTexCoordBufferID(id);
	id = g_meshes[0]->getIndexBufferID();
	if(FAILED(createIndexBuffer((void*)g_meshes[0]->getIndices().data(), g_meshes[0]->getNumIndices(), id, h)))
	{
		MessageBox(this->hWnd, "IndexBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setIndexBufferID(id);

	Object3D *obj = new Object3D();
	obj->setMeshID(g_meshes.size()-1);
	obj->setPosition(elm::vec3(200,100,200));
	obj->setScale(elm::vec3(.2f,.2f,.2f));

	g_objects.at(0) = obj;

	CModel<Object3D>* co = new CModel<Object3D>("test", obj);

	Composition c;
	c.setName("test");
	c.setProperty(co);
	g_comps.push_back(c);

	if(g_meshes[0]->getTexDiffusePath().size() == 0)
	{
		tex = nullptr;
	}
	else if(g_meshes[0]->getTexDiffusePath().substr(g_meshes[0]->getTexDiffusePath().size()-4, g_meshes[0]->getTexDiffusePath().size()) != ".tga")
	{
		hr = D3DX11CreateShaderResourceViewFromFile(h.device, g_meshes[0]->getTexDiffusePath().c_str(), NULL, NULL, &tex, NULL);
	}
	else
	{
		DirectX::ScratchImage *image = new DirectX::ScratchImage();
		hr = DirectX::LoadFromTGAFile(s2ws(g_meshes[0]->getTexDiffusePath()).c_str(), nullptr, *image);
		hr = DirectX::CreateShaderResourceView(h.device, image->GetImages(), image->GetImageCount(), image->GetMetadata(), &tex);
	}
	if(FAILED(hr))
	{
		return hr;
	}
	h.textures.at(1) = tex;

	g_meshes[0]->setTexDiffuseID(h.textures.size() - 1);

	blendmap->init(h.device, h.deviceContext, &h.textures, &h.hwnd);

    return S_OK;
}

HRESULT RenderDX11::createBuffer(void *data, int numElements, int bytesPerElement, int &bufferID, Handle &h)
{
	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = data;
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_IMMUTABLE;
    bd.ByteWidth = bytesPerElement * numElements;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = 0;
	bd.MiscFlags      = 0;

	ID3D11Buffer *buffer = nullptr;
	HRESULT hr = h.device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create vertexbuffer", "ERROR", S_OK);
		return hr;
	}

	if(bufferID == -1)
	{
		bufferID = h.buffers.size();
		h.buffers.push_back(buffer);
	}
	else
	{
		SAFE_RELEASE(h.buffers.at(bufferID));
		h.buffers.at(bufferID) = buffer;
	}

	return S_OK;
}

HRESULT RenderDX11::createIndexBuffer(void* data, int numElements, int &bufferID, Handle &h)
{
	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = data;
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_IMMUTABLE;
    bd.ByteWidth = sizeof(unsigned int) * numElements;
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bd.CPUAccessFlags = 0;
	bd.MiscFlags      = 0;

	ID3D11Buffer *buffer = nullptr;
	HRESULT hr = h.device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create indexbuffer", "ERROR", S_OK);
		return hr;
	}

	if(bufferID == -1)
	{
		bufferID = handles.at(0).buffers.size();
		h.buffers.push_back(buffer);
	}
	else
	{
		SAFE_RELEASE(h.buffers.at(bufferID));
		h.buffers.at(bufferID) = buffer;
	}

	return S_OK;
}

HRESULT RenderDX11::compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob)
{
	UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    flags |= D3DCOMPILE_DEBUG;
#else
	flags |= D3DCOMPILE_OPTIMIZATION_LEVEL3;
#endif

    ID3DBlob* errorBlob = nullptr;
	HRESULT hr = D3DX11CompileFromFile(filePath, NULL, NULL, "main", shaderType, flags, 0, NULL, shaderBlob, &errorBlob, NULL);
	if(FAILED(hr))
    {
        if(errorBlob != NULL)
            OutputDebugStringA((char*)errorBlob->GetBufferPointer());
        SAFE_RELEASE( errorBlob );
        return hr;
    }
    SAFE_RELEASE(errorBlob);

	return hr;
}

HRESULT RenderDX11::createSampleStates(Handle &h)
{
	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory( &sampDesc, sizeof(sampDesc));
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

	HRESULT hr;
	hr = h.device->CreateSamplerState(&sampDesc, &h.wrap);
	if(FAILED(hr))
		MessageBox(hWnd, "Error creating sampler state", "ERROR", MB_OK);

	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	hr = h.device->CreateSamplerState(&sampDesc, &h.clamp);
	if(FAILED(hr))
		MessageBox(hWnd, "Error creating sampler state", "ERROR", MB_OK);

	return hr;
}

HRESULT RenderDX11::createSRV(unsigned int& _outId, string _fileName)
{
	HRESULT hr;

	ID3D11ShaderResourceView *tex	= nullptr;	

	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == "main")
		{
			hr = D3DX11CreateShaderResourceViewFromFile(handles.at(i).device, _fileName.c_str(), NULL, NULL, &tex, NULL);

			if(FAILED(hr))
			{
				MessageBox(hWnd, "Image load made fail, lol", "fail, yo", 0);
				return hr;
			}
			break;
		}
	}

	_outId			= m_SRVs.size();
	m_SRVs[_outId]	= tex;
	return S_OK;
}

void RenderDX11::createAndSetTerrainBuffers(std::vector<Vertex> *vBuffer, std::vector<uint> *iBuffer)
{
	this->iBuffer = iBuffer;

	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = &vBuffer->at(0);
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(Vertex) * vBuffer->size();
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	ID3D11Buffer *buffer;
	HRESULT hr;

	if(terrainVertexBufferID == -1)
	{
		terrainVertexBufferID = handles.at(0).buffers.size();
		for(unsigned int i = 0; i < handles.size(); i++)
		{
			buffer = nullptr;
			hr = handles.at(i).device->CreateBuffer(&bd, &initData, &buffer);
			if(FAILED(hr))
				MessageBox(NULL, "could not create terrain indexbuffer", "ERROR", S_OK);

			handles.at(i).buffers.push_back(buffer);
		}
	}
	else
	{
		for(unsigned int i = 0; i < handles.size(); i++)
		{
			SAFE_RELEASE(handles.at(i).buffers.at(terrainVertexBufferID));

			buffer = nullptr;
			hr = handles.at(i).device->CreateBuffer(&bd, &initData, &buffer);
			if(FAILED(hr))
				MessageBox(NULL, "could not create terrain indexbuffer", "ERROR", S_OK);

			handles.at(i).buffers.at(terrainVertexBufferID) = buffer;
		}
	}

	initData.pSysMem = &iBuffer->at(0);

	bd.Usage = D3D11_USAGE_IMMUTABLE;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.ByteWidth = sizeof(unsigned int) * iBuffer->size();
	bd.CPUAccessFlags = 0;

	if(terrainIndexBufferID == -1)
	{
		terrainIndexBufferID = handles.at(0).buffers.size();
		for(unsigned int i = 0; i < handles.size(); i++)
		{
			buffer = nullptr;
			hr = handles.at(i).device->CreateBuffer(&bd, &initData, &buffer);
			if(FAILED(hr))
				MessageBox(NULL, "could not create terrain indexbuffer", "ERROR", S_OK);

			handles.at(i).buffers.push_back(buffer);
		}
	}
	else
	{
		for(unsigned int i = 0; i < handles.size(); i++)
		{
			SAFE_RELEASE(handles.at(i).buffers.at(terrainIndexBufferID));

			buffer = nullptr;
			hr = handles.at(i).device->CreateBuffer(&bd, &initData, &buffer);
			if(FAILED(hr))
				MessageBox(NULL, "could not create terrain indexbuffer", "ERROR", S_OK);

			handles.at(i).buffers.at(terrainIndexBufferID) = buffer;
		}
	}
}

void RenderDX11::updateTerrainBuffer(std::vector<Vertex> *vBuffer)
{
	D3D11_MAPPED_SUBRESOURCE resource;
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		HRESULT hr = handles.at(i).deviceContext->Map(handles.at(i).buffers.at(terrainVertexBufferID), 0, D3D11_MAP_WRITE_NO_OVERWRITE, 0, &resource);

		if(FAILED(hr))
			MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

		memcpy(resource.pData, (void**)&vBuffer->at(0), sizeof(Vertex)* vBuffer->size());

		handles.at(i).deviceContext->Unmap(handles.at(i).buffers.at(terrainVertexBufferID), 0);
	}
}

const float color[4] = {0.f, 1.f, 1.f, 1.f};
void RenderDX11::renderScene()
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == "main")
		{
			render(handles.at(i));
			break;
		}
	}
}

void RenderDX11::renderScene(std::string _name)
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		if(handles.at(i).name == _name)
		{
			render(handles.at(i));
			break;
		}
	}
}

void RenderDX11::render(const Handle &h)
{
	h.deviceContext->ClearRenderTargetView(h.renderTargetView, color);
	h.deviceContext->ClearDepthStencilView(h.depthStencilView, D3D11_CLEAR_DEPTH, 1.f, 0);

	CBOnChange cb;
	cb.viewProj = h.camera->getView() * h.camera->getProj();
	cb.position = elm::vec4(h.camera->getEye(), 1.f);
	cb.world = elm::mat4();

	h.deviceContext->UpdateSubresource(h.buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

	// Terrain
	h.deviceContext->OMSetDepthStencilState(h.depthStencilStateEnable, 0);
	h.deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	h.deviceContext->IASetInputLayout(h.layout);
	
	h.deviceContext->PSSetSamplers(0, 1, &h.wrap);
	
	h.deviceContext->PSSetSamplers(0, 1, &h.wrap);
	h.deviceContext->PSSetShaderResources(0, 1, &h.textures.at(0));
	//blendmap->CSexec();

	h.deviceContext->VSSetConstantBuffers(0, 1, &h.buffers.at(cbOnChangeID));

	float blendFactor[4] = {0.f, 0.f, 0.f, 0.f};
	h.deviceContext->OMSetBlendState(h.blendDisable, blendFactor, 0xffffffff);

	// Set vertex buffer
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	h.deviceContext->IASetVertexBuffers(0, 1, &h.buffers.at(terrainVertexBufferID), &stride, &offset);
	h.deviceContext->IASetIndexBuffer(h.buffers.at(terrainIndexBufferID), DXGI_FORMAT_R32_UINT, offset);

	h.deviceContext->VSSetShader(h.terrainVS, NULL, 0);
	h.deviceContext->PSSetShader(h.terrainPS, NULL, 0);

	h.deviceContext->DrawIndexed(terrainIndexCount, 0, 0);
	
	/************************************************************/
	//						DRAWING A MESH						//
	/************************************************************/

	int i = g_comps.size();
	h.deviceContext->VSSetShader(h.modelVS, NULL, 0);
	h.deviceContext->PSSetShader(h.modelPS, NULL, 0);
	h.deviceContext->IASetInputLayout(h.otherlayout);

	stride = sizeof(elm::vec3);
	for(unsigned int i = 0; i < g_comps.size(); i++)
	{
		Object3D* o = g_comps[i].getProperty<Object3D>();

		if(!o)
			continue;
		
		cb.world = elm::translationMatrix(o->getPosition());
		cb.world = elm::scalingMatrix(o->getScale()) * cb.world;
		h.deviceContext->UpdateSubresource(h.buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

		h.deviceContext->IASetVertexBuffers(0, 1, &h.buffers.at(g_meshes[o->getMeshID()]->getVertexBufferID()), &stride, &offset);
		h.deviceContext->IASetVertexBuffers(1, 1, &h.buffers.at(g_meshes[o->getMeshID()]->getNormalBufferID()), &stride, &offset);
		h.deviceContext->IASetVertexBuffers(2, 1, &h.buffers.at(g_meshes[o->getMeshID()]->getTexCoordBufferID()), &stride, &offset);

		h.deviceContext->PSSetShaderResources(0, 1, &h.textures.at(g_meshes[o->getMeshID()]->getTexDiffuseID()));

		h.deviceContext->IASetIndexBuffer(h.buffers.at(g_meshes[o->getMeshID()]->getIndexBufferID()), DXGI_FORMAT_R32_UINT, 0);

		h.deviceContext->DrawIndexed(g_meshes[o->getMeshID()]->getNumIndices(), 0, 0);
	}

	h.swapChain->Present(0, 0);
}

RenderDX11::~RenderDX11()
{
	for(unsigned int i = 0; i < handles.size(); i++)
	{
		Handle &h = handles.at(i);

		h.deviceContext->Flush();
		h.deviceContext->ClearState();
		SAFE_RELEASE(h.swapChain);
		SAFE_RELEASE(h.renderTargetView);
		SAFE_RELEASE(h.depthStencilView);
		SAFE_RELEASE(h.deviceContext);
		SAFE_RELEASE(h.device);

		SAFE_RELEASE(h.blendEnable);
		SAFE_RELEASE(h.blendDisable);

		SAFE_RELEASE(h.depthStencilStateDisable);
		SAFE_RELEASE(h.depthStencilStateEnable);

		SAFE_RELEASE(h.terrainPS);
		SAFE_RELEASE(h.terrainVS);
		SAFE_RELEASE(h.modelPS);
		SAFE_RELEASE(h.modelVS);
		SAFE_RELEASE(h.layout);
		SAFE_RELEASE(h.otherlayout);
		SAFE_RELEASE(h.blendAlpha);

		for(unsigned int i = 0; i < h.buffers.size(); i++)
			SAFE_RELEASE(h.buffers[i]);

		h.buffers.clear();

		SAFE_RELEASE(h.clamp);
		SAFE_RELEASE(h.rasterizerState);

		for(unsigned int i = 0; i < h.textures.size(); i++)
			SAFE_RELEASE(h.textures[i]);

		h.textures.clear();
		SAFE_RELEASE(h.wrap);
	}

	for(unsigned int i = 0; i < g_meshes.size(); i++)
		SAFE_DELETE(g_meshes[i]);

	g_meshes.clear();
}

void RenderDX11::blendmapBrush(float _radius, float _intensity, elm::vec2 _origin, char* _texture, float _step)
{
	blendmap->applayBrush(_radius, _intensity, _origin, _texture, _step);
}