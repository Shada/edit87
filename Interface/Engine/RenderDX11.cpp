#include "RenderDX11.h"
#pragma comment(lib, "D3DX11.lib")
#include <D3DX11async.h>
#include <d3dcompiler.h>
#include "..\DirectXTex\DirectXTex.h"
#include "Utility.h"
#include "IRadial.h"

RenderDX11::RenderDX11(HWND hWnd)
{
	this->hWnd = hWnd;
	terrainVertexBufferID = terrainIndexBufferID = -1;

	camera			= nullptr;
	g_swapChain		= nullptr;
	specComp		= new Composition();
	toolIsActive	= true;
	toolBufferId	= -1;
	m_currentRadial	= nullptr;
}

void RenderDX11::setRect(RECT t)
{
	r = t;

	if(!g_swapChain)
		init();
}

void RenderDX11::setRadial(IRadial* _radial)
{
	m_currentRadial = _radial;
}

HRESULT RenderDX11::init()
{
	HRESULT hr = S_OK;
	
    width = r.right - r.left;
    height = r.bottom - r.top;

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
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    for(UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
    {
		g_driverType = driverTypes[driverTypeIndex];
        hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
                                           D3D11_SDK_VERSION, &sd, &g_swapChain, &g_device, &g_featureLevel, &g_deviceContext);
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
    hr = g_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Backbuffer made fail, lol", "fail, yo", 0);
        return hr;
	}

    hr = g_device->CreateRenderTargetView(pBackBuffer, NULL, &g_renderTargetView);
    SAFE_RELEASE(pBackBuffer);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Rendertargetview made fail, lol", "fail, yo", 0);
        return hr;
	}

    // Create depth stencil texture
    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory(&descDepth, sizeof(descDepth));
    descDepth.Width = width;
    descDepth.Height = height;
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
    hr = g_device->CreateTexture2D(&descDepth, NULL, &depthStencil);
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
    hr = g_device->CreateDepthStencilView(depthStencil, &descDSV, &g_depthStencilView);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "depthstencilview made fail, lol", "fail, yo", 0);
        return hr;
	}

	SAFE_RELEASE(depthStencil);

    g_deviceContext->OMSetRenderTargets(1, &g_renderTargetView, g_depthStencilView);

	D3D11_RASTERIZER_DESC rasterDesc;

	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_NONE;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = true;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

	// Create the rasterizer state from the description we just filled out.
	hr = g_device->CreateRasterizerState(&rasterDesc, &g_rasterizerState);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "rasterizerstate made fail, lol", "fail, yo", 0);
        return hr;
	}

	// Now set the rasterizer state.
	g_deviceContext->RSSetState(g_rasterizerState);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_deviceContext->RSSetViewports( 1, &vp );

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
	hr = g_device->CreateBlendState(&blendDesc, &g_blendEnable);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "blendenable made fail, lol", "fail, yo", 0);
        return hr;
	}

	blendDesc.RenderTarget[0].BlendEnable = FALSE;
	hr = g_device->CreateBlendState(&blendDesc, &g_blendDisable);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "blenddisable made fail, lol", "fail, yo", 0);
        return hr;
	}

	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	blendDesc.RenderTarget[0].BlendEnable = TRUE;
	hr = g_device->CreateBlendState(&blendDesc, &g_blendAlpha);
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
	hr = g_device->CreateDepthStencilState(&depthDesc, &g_depthStencilStateEnable);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "g_depthStencilStateEnable made fail, lol", "fail, yo", 0);
        return hr;
	}

	depthDesc.DepthEnable = FALSE;
	hr = g_device->CreateDepthStencilState(&depthDesc, &g_depthStencilStateDisable);
	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "g_depthStencilStateDisable made fail, lol", "fail, yo", 0);
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
	hr = g_device->CreateBuffer(&bd, NULL, &b);
	if(FAILED(hr))
		return hr;

	cbOnceID = g_buffers.size();
	g_buffers.push_back(b);

	bd.ByteWidth = sizeof(CBOnChange);
	b = nullptr;
	hr = g_device->CreateBuffer(&bd, NULL, &b);
	if(FAILED(hr))
		return hr;

	cbOnChangeID = g_buffers.size();
	g_buffers.push_back(b);

	bd.ByteWidth = sizeof(CBIcon);
	b = nullptr;
	hr = g_device->CreateBuffer(&bd, NULL, &b);
	iconCBufferId = g_buffers.size();
	g_buffers.push_back(b);

	if(FAILED(hr))
		return hr;

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

	D3D11_INPUT_ELEMENT_DESC billboardLayout[] = 
	{
		{	"POSITION",	0,	DXGI_FORMAT_R32G32_FLOAT,	0,	0,					D3D11_INPUT_PER_VERTEX_DATA,	0 },
		{	"DIMENSION",0,	DXGI_FORMAT_R32G32_FLOAT,	0,	sizeof(float) * 2,	D3D11_INPUT_PER_VERTEX_DATA,	0 }
	};

	/* Create shaders */
	ID3DBlob *shaderBlob;

	// Default
	compileShader("..\\Shaders\\defaultVS.hlsl", "vs_4_0", &shaderBlob);
	g_device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_terrainVS);
	g_device->CreateInputLayout(standardLayout, ARRAYSIZE(standardLayout), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &g_layout);
	shaderBlob->Release();

	compileShader("..\\Shaders\\defaultPS.hlsl", "ps_4_0", &shaderBlob);
	g_device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_terrainPS);

	shaderBlob->Release();

	// Model
	hr = compileShader("..\\Shaders\\modelVS.hlsl", "vs_4_0", &shaderBlob);
	hr = g_device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_modelVS);
	hr = g_device->CreateInputLayout(aLittleLessStandardLayout, ARRAYSIZE(aLittleLessStandardLayout), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &g_otherlayout);
	shaderBlob->Release();

	hr = compileShader("..\\Shaders\\modelPS.hlsl", "ps_4_0", &shaderBlob);
	g_device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_modelPS);

	shaderBlob->Release();

	// Billboard
	hr	= compileShader("../Shaders/ToolBillboardVS.hlsl", "vs_4_0", &shaderBlob);
	hr	= g_device->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_toolVS);
	hr	= g_device->CreateInputLayout(billboardLayout, ARRAYSIZE(billboardLayout), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &g_billboardlayout);
	shaderBlob->Release();

	hr	= compileShader("../Shaders/ToolBillboardGS.hlsl", "gs_4_0", &shaderBlob);
	hr	= g_device->CreateGeometryShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_toolGS);
	shaderBlob->Release();

	hr	= compileShader("../Shaders/ToolBillboardPS.hlsl", "ps_4_0", &shaderBlob);
	g_device->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), NULL, &g_toolPS);

	shaderBlob->Release();

	ID3D11ShaderResourceView *tex;

	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\grass.png", NULL, NULL, &tex, NULL);

	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_textures.push_back(tex);
	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\redIcon.png", NULL, NULL, &tex, NULL);

	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_textures.push_back(tex);

	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\xarr.png", NULL, NULL, &tex, NULL);
	toolXId = g_textures.size();
	g_textures.push_back(tex);

	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\yarr.png", NULL, NULL, &tex, NULL);
	toolYId = g_textures.size();
	g_textures.push_back(tex);

	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\zarr.png", NULL, NULL, &tex, NULL);
	toolZId = g_textures.size();
	g_textures.push_back(tex);

	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\translate.png", NULL, NULL, &tex, NULL);

	toolMoveId = g_textures.size();
	g_textures.push_back(tex);
	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\scale.png", NULL, NULL, &tex, NULL);

	toolScaleId = g_textures.size();
	g_textures.push_back(tex);
	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\rotate.png", NULL, NULL, &tex, NULL);

	toolRotateId = g_textures.size();
	g_textures.push_back(tex);
	tex = nullptr;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\anchor.png", NULL, NULL, &tex, NULL);
	toolAnchorId = g_textures.size();
	g_textures.push_back(tex);


	createSampleStates();

	// default mesh
	Mesh3D *mesh = new Mesh3D();
	if(!mesh->loadMesh("../Models/Collada/duck.dae"))
	{
		MessageBoxA(hWnd, "Model load fail", "FAIL", 0);
	}
	g_meshes.push_back(mesh);
	int id;
	if(FAILED(createBuffer((void*)g_meshes[0]->getVertices().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id)))
	{
		MessageBox(this->hWnd, "VertexBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setVertexBufferID(id);
	if(FAILED(createBuffer((void*)g_meshes[0]->getNormals().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id)))
	{
		MessageBox(this->hWnd, "NormalBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setNormalBufferID(id);
	if(FAILED(createBuffer((void*)g_meshes[0]->getTexCoords().data(), g_meshes[0]->getNumVertices(), sizeof(elm::vec3), id)))
	{
		MessageBox(this->hWnd, "TexCoordsBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setTexCoordBufferID(id);
	if(FAILED(createIndexBuffer((void*)g_meshes[0]->getIndices().data(), g_meshes[0]->getNumIndices(), id)))
	{
		MessageBox(this->hWnd, "IndexBuffer load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_meshes[0]->setIndexBufferID(id);

	//elm::vec2 quad[2] = 
	//{
	//	elm::vec2(0,0), elm::vec2(100.f / (float)width, 100.f / (float)height),
	//};

	//if( FAILED(createBuffer((void*)quad, 1, sizeof(elm::vec2) * 2, toolBufferId, true)) )
	//{
	//	MessageBox(this->hWnd, "VertexBuffer (Billboard) load made fail, lol", "fail, yo", 0);
	//	return hr;
	//}

	// default object + composition
	Object3D *obj = new Object3D();
	obj->setMeshID(g_meshes.size()-1);
	obj->setPosition(elm::vec3(200,100,200));
	obj->setScale(elm::vec3(.2f,.2f,.2f));

	g_objects.push_back(obj);

	CModel<Object3D>* co = new CModel<Object3D>("test", obj);

	// default object
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
		hr = D3DX11CreateShaderResourceViewFromFile(g_device, g_meshes[0]->getTexDiffusePath().c_str(), NULL, NULL, &tex, NULL);
	}
	else
	{
		DirectX::ScratchImage *image = new DirectX::ScratchImage();
		hr = DirectX::LoadFromTGAFile(s2ws(g_meshes[0]->getTexDiffusePath()).c_str(), nullptr, *image);
		hr = DirectX::CreateShaderResourceView(g_device, image->GetImages(), image->GetImageCount(), image->GetMetadata(), &tex);
	}
	if(FAILED(hr))
	{
		return hr;
	}
	g_textures.push_back(tex);

	g_meshes[0]->setTexDiffuseID(g_textures.size() - 1);

	createMenu(20,100, 0.1);


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

HRESULT RenderDX11::createSampleStates()
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
	hr = g_device->CreateSamplerState(&sampDesc, &g_wrap);
	if(FAILED(hr))
		MessageBox(hWnd, "Error creating sampler state", "ERROR", MB_OK);

	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	hr = g_device->CreateSamplerState(&sampDesc, &g_clamp);
	if(FAILED(hr))
		MessageBox(hWnd, "Error creating sampler state", "ERROR", MB_OK);

	return hr;
}

HRESULT RenderDX11::createBuffer(void *data, int numElements, int bytesPerElement, int &bufferID, bool isDynamic)
{
	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = data;
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	if(isDynamic)
	{
		bd.Usage = D3D11_USAGE_DYNAMIC;
		bd.CPUAccessFlags	= D3D11_CPU_ACCESS_WRITE;
	}
	else
	{
		bd.Usage = D3D11_USAGE_IMMUTABLE;
		    bd.CPUAccessFlags = 0;
	}
    bd.ByteWidth = bytesPerElement * numElements;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	bd.MiscFlags      = 0;

	ID3D11Buffer *buffer = nullptr;
	HRESULT hr = g_device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create vertexbuffer", "ERROR", S_OK);
		return hr;
	}

	bufferID = g_buffers.size();
	g_buffers.push_back(buffer);

	
	return S_OK;
}

HRESULT RenderDX11::createIndexBuffer(void* data, int numElements, int &bufferID)
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
	HRESULT hr = g_device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create indexbuffer", "ERROR", S_OK);
		return hr;
	}

	bufferID = g_buffers.size();
	g_buffers.push_back(buffer);

	m_buffers[bufferID] = buffer;

	return S_OK;
}

HRESULT RenderDX11::createSRV(unsigned int& _outId, string _fileName)
{
	HRESULT hr;

	ID3D11ShaderResourceView *tex	= nullptr;	

	hr = D3DX11CreateShaderResourceViewFromFile(g_device, _fileName.c_str(), NULL, NULL, &tex, NULL);

	if(FAILED(hr))
	{
		MessageBox(hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
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

	ID3D11Buffer *buffer = nullptr;
	HRESULT hr = g_device->CreateBuffer(&bd, &initData, &buffer);
	if(FAILED(hr))
		MessageBox(NULL, "could not create terrain vertexbuffer", "ERROR", S_OK);

	if(terrainVertexBufferID == -1)
	{
		terrainVertexBufferID = g_buffers.size();
		g_buffers.push_back(buffer);
	}
	else
	{
		SAFE_RELEASE(g_buffers.at(terrainVertexBufferID));
		g_buffers.at(terrainVertexBufferID) = buffer;
	}

	initData.pSysMem = &iBuffer->at(0);

	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.ByteWidth = sizeof(unsigned int) * iBuffer->size();

	buffer = nullptr;
	hr = g_device->CreateBuffer(&bd, &initData, &buffer);
	if(FAILED(hr))
		MessageBox(NULL, "could not create terrain indexbuffer", "ERROR", S_OK);

	if(terrainIndexBufferID == -1)
	{
		terrainIndexBufferID = g_buffers.size();
		g_buffers.push_back(buffer);
	}
	else
	{
		SAFE_RELEASE(g_buffers.at(terrainIndexBufferID));
		g_buffers.at(terrainIndexBufferID) = buffer;
	}

	// 3d mini
	
	//Mesh3D* m = new Mesh3D();
	//m->setVertexBufferID(terrainVertexBufferID);
	//m->setIndexBufferID(terrainIndexBufferID);
	//m->setMinMax( elm::vec3(-100), elm::vec3(100) );
	//g_meshes.push_back(m);

	//Object3D* mo = new Object3D();
	//mo->setMeshID(g_meshes.size() - 1);
	//mo->setScale(elm::vec3(0.25));
	//mo->setRotation(elm::vec3(0));
	//mo->setPosition(elm::vec3(200,100,200));
	//
	//g_objects.push_back(mo);

	//CModel<Object3D>* ct = new CModel<Object3D>("terrain_mini", mo);

	//specComp->setName("terrain_mini");
	//specComp->setProperty(ct);
	//g_comps.push_back(*specComp);
	
}

void RenderDX11::updateTerrainBuffer(std::vector<Vertex> *vBuffer)
{
	D3D11_MAPPED_SUBRESOURCE resource;
	HRESULT hr = g_deviceContext->Map(g_buffers.at(terrainVertexBufferID), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

	if(FAILED(hr))
		MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

	memcpy(resource.pData, (void**)&vBuffer->at(0), sizeof(Vertex)* vBuffer->size());

	g_deviceContext->Unmap(g_buffers.at(terrainVertexBufferID), 0);
}

const float color[4] = {0.f, 1.f, 1.f, 1.f};
void RenderDX11::renderScene(Quadnode *node)
{
	g_deviceContext->ClearRenderTargetView(g_renderTargetView, color);
	g_deviceContext->ClearDepthStencilView(g_depthStencilView, D3D11_CLEAR_DEPTH, 1.f, 0);

	CBOnChange cb;
	cb.viewProj = camera->getView() * camera->getProj();
	cb.position = elm::vec4(camera->getEye(), 1.f);
	cb.world = elm::mat4();
	g_deviceContext->UpdateSubresource(g_buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

	/* ************************************************** 
						Terrain
	*  ************************************************** */
	g_deviceContext->OMSetDepthStencilState(g_depthStencilStateEnable, 0);
	g_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	g_deviceContext->IASetInputLayout(g_layout);
	
	g_deviceContext->PSSetSamplers(0, 1, &g_wrap);
	g_deviceContext->PSSetShaderResources(0, 1, &g_textures.at(0));
	g_deviceContext->VSSetConstantBuffers(0, 1, &g_buffers.at(cbOnChangeID));

	float blendFactor[4] = {0.f, 0.f, 0.f, 0.f};
	g_deviceContext->OMSetBlendState(g_blendDisable, blendFactor, 0xffffffff);

	// Set vertex buffer
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	g_deviceContext->IASetVertexBuffers(0, 1, &g_buffers.at(terrainVertexBufferID), &stride, &offset);
	g_deviceContext->IASetIndexBuffer(g_buffers.at(terrainIndexBufferID), DXGI_FORMAT_R32_UINT, offset);

	g_deviceContext->VSSetShader(g_terrainVS, NULL, 0);
	g_deviceContext->PSSetShader(g_terrainPS, NULL, 0);

	g_deviceContext->DrawIndexed(terrainIndexCount, 0, 0);

	//drawCulledTerrain(node);
	// draw mini terrain
	//Object3D* o = specComp->getProperty<Object3D>();

	//cb.world = elm::translationMatrix(o->getPosition());
	//elm::mat4 rotate;
	//elm::yawPitchRoll(rotate, o->getRotation());
	//elm::mat4 scale		= elm::scalingMatrix(o->getScale());
	//elm::mat4 translate	= elm::translationMatrix(o->getPosition());
	//cb.world = scale * rotate * translate;
	//g_deviceContext->UpdateSubresource(g_buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

	//g_deviceContext->DrawIndexed(terrainIndexCount, 0, 0);
	
	/************************************************************/
	//						DRAWING A MESH						//
	/************************************************************/

	int i = g_comps.size();
	g_deviceContext->VSSetShader(g_modelVS, NULL, 0);
	g_deviceContext->PSSetShader(g_modelPS, NULL, 0);
	g_deviceContext->IASetInputLayout(g_otherlayout);

	stride = sizeof(elm::vec3);
	for(unsigned int i = 0; i < g_comps.size(); i++)
	{
		if(g_comps[i].getName() == "terrain_mini")
			continue;

		Object3D* o = g_comps[i].getProperty<Object3D>();

		if(!o)
			continue;

		if(g_comps[i].isSelected())
		{
			cb.highlight = elm::vec4(1,0.75,0.75,1);
		}
		else
			cb.highlight = elm::vec4(1);
		
		cb.world = elm::translationMatrix(o->getPosition());
		elm::mat4 rotate;
		elm::yawPitchRoll(rotate, o->getRotation());
		elm::mat4 scale		= elm::scalingMatrix(o->getScale());
		elm::mat4 translate	= elm::translationMatrix(o->getPosition());
		cb.world = scale * rotate * translate;
		g_deviceContext->UpdateSubresource(g_buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

		g_deviceContext->IASetVertexBuffers(0, 1, &g_buffers.at(g_meshes[o->getMeshID()]->getVertexBufferID()), &stride, &offset);
		g_deviceContext->IASetVertexBuffers(1, 1, &g_buffers.at(g_meshes[o->getMeshID()]->getNormalBufferID()), &stride, &offset);
		g_deviceContext->IASetVertexBuffers(2, 1, &g_buffers.at(g_meshes[o->getMeshID()]->getTexCoordBufferID()), &stride, &offset);

		g_deviceContext->PSSetShaderResources(0, 1, &g_textures.at(g_meshes[o->getMeshID()]->getTexDiffuseID()));

		g_deviceContext->IASetIndexBuffer(g_buffers.at(g_meshes[o->getMeshID()]->getIndexBufferID()), DXGI_FORMAT_R32_UINT, 0);

		g_deviceContext->DrawIndexed(g_meshes[o->getMeshID()]->getNumIndices(), 0, 0);
	}

	/******************************
		DRAW TOOL BILLBOARD
	*******************************/
	if(m_currentRadial != nullptr)
		m_currentRadial->draw();
	////if(toolIsActive)
	//{
	//	g_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_POINTLIST);

	//	stride = sizeof(elm::vec2) * 2;

	//	g_deviceContext->VSSetShader(g_toolVS, NULL, 0);
	//	g_deviceContext->GSSetShader(g_toolGS, NULL, 0);
	//	g_deviceContext->PSSetShader(g_toolPS, NULL, 0);
	//	g_deviceContext->IASetInputLayout(g_billboardlayout);

	//	g_deviceContext->IASetVertexBuffers(0, 1, &g_buffers.at(toolBufferId), &stride, &offset);

	//	g_deviceContext->Draw(20, 0);

	//	g_deviceContext->GSSetShader(NULL, NULL, 0);
	//}
	g_swapChain->Present(0, 0);
}

// woudn't it be faster to draw the terrain chunks one by one instead of copying incides and update the index buffer every frame?
void RenderDX11::drawCulledTerrain(Quadnode *node)
{
	std::vector<int> ids;
	node->getIndexBufferValues(camera->getFrustum(), ids, 3);

	D3D11_MAPPED_SUBRESOURCE resource;
	HRESULT hr = g_deviceContext->Map(g_buffers.at(terrainIndexBufferID), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

	if(FAILED(hr))
		MessageBox(NULL, "Could not update index buffer", "ERROR", S_OK);

	std::vector<uint> indexBuffer(int((ids.at(1) - ids.at(0)) * ids.size() * 0.5));

	uint count = 0;
	for(uint i = 0; i < ids.size(); i += 2) // why memcpy and not insert?
	{
		memcpy((void**)&indexBuffer.at(count), (void**)&iBuffer->at(ids.at(i)), sizeof(uint)* (ids.at(i + 1) - ids.at(i)));
		count += (ids.at(i + 1) - ids.at(i));
	}
	memcpy(resource.pData, (void**)&indexBuffer.at(0), sizeof(uint) * count);

	g_deviceContext->Unmap(g_buffers.at(terrainIndexBufferID), 0);

	g_deviceContext->IASetIndexBuffer(g_buffers.at(terrainIndexBufferID), DXGI_FORMAT_R32_UINT, (UINT)0);

	g_deviceContext->DrawIndexed(count, 0, 0);
}

RenderDX11::~RenderDX11()
{
	SAFE_DELETE(camera);

	g_deviceContext->Flush();
    g_deviceContext->ClearState();
    SAFE_RELEASE(g_swapChain);
	SAFE_RELEASE(g_renderTargetView);
	SAFE_RELEASE(g_depthStencilView);
	SAFE_RELEASE(g_shaderView);

    SAFE_RELEASE(g_deviceContext);
    SAFE_RELEASE(g_device);

	SAFE_RELEASE(g_blendEnable);
	SAFE_RELEASE(g_blendDisable);

	SAFE_RELEASE(g_depthStencilStateDisable);
	SAFE_RELEASE(g_depthStencilStateEnable);

	SAFE_RELEASE(g_terrainPS);
	SAFE_RELEASE(g_terrainVS);
	SAFE_RELEASE(g_modelPS);
	SAFE_RELEASE(g_modelVS);
	SAFE_RELEASE(g_layout);
	SAFE_RELEASE(g_otherlayout);
	SAFE_RELEASE(g_blendAlpha);
	for(unsigned int i = 0; i < g_buffers.size(); i++)
	{
		SAFE_RELEASE(g_buffers[i]);
	}
	g_buffers.clear();

	SAFE_RELEASE(g_clamp);
	SAFE_RELEASE(g_rasterizerState);
	for(unsigned int i = 0; i < g_textures.size(); i++)
	{
		SAFE_RELEASE(g_textures[i]);
	}
	g_textures.clear();
	SAFE_RELEASE(g_wrap);
	for(unsigned int i = 0; i < g_meshes.size(); i++)
	{
		SAFE_DELETE(g_meshes[i]);
	}
	g_meshes.clear();
}

void RenderDX11::setMousePoint(POINT _mousePoint)
{
	mousePoint = _mousePoint;

	elm::vec2 quad[2] = 
	{
		elm::vec2((float)_mousePoint.x / (float)width * 2 - 1, -((float)_mousePoint.y / (float)height * 2 - 1)), elm::vec2(100.f / (float)width, 100.f / (float)height),
	};
	createMenu(8,100, 10);
	//D3D11_MAPPED_SUBRESOURCE resource;
	//HRESULT hr = g_deviceContext->Map(g_buffers.at(toolBufferId), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

	//if(FAILED(hr))
	//	MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

	//memcpy(resource.pData, (void**)&quad[0], sizeof(elm::vec2)* 2);

	//g_deviceContext->Unmap(g_buffers.at(toolBufferId), 0);

	
}

void RenderDX11::toggleTool(bool _arg)
{
	if(toolIsActive)
		toolIsActive = false;
	else 
		toolIsActive = true;
}

void RenderDX11::createMenu(unsigned int _numIcons, float _radius, elm::vec2 _iconDimension)
{
	float rad = 360.f / _numIcons * 0.0174532925f;

	std::vector<elm::vec4> quads;

	for(int i = 0; i < _numIcons; i++)
	{
		elm::vec2 p( (int)(_radius * std::sin(i * rad)), (int)(_radius * std::cos(i * rad)));
		
		quads.push_back( elm::vec4((p.x + (float)mousePoint.x) / (float)width * 2 - 1, -((p.y + (float)mousePoint.y) / (float)height * 2 - 1), _iconDimension.x / (float)width * 2, _iconDimension.y / (float)height * 2) );
	}
	if(toolBufferId == -1)
	{
		createBuffer((void**)&quads[0], quads.size(), sizeof(elm::vec4), toolBufferId, true);
	}
	else
	{
		D3D11_MAPPED_SUBRESOURCE resource;
		HRESULT hr = g_deviceContext->Map(g_buffers.at(toolBufferId), 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);

		if(FAILED(hr))
			MessageBox(NULL, "Could not update terrain buffer", "ERROR", S_OK);

		memcpy(resource.pData, (void**)&quads[0], sizeof(elm::vec4)* quads.size());

		g_deviceContext->Unmap(g_buffers.at(toolBufferId), 0);
	}
}