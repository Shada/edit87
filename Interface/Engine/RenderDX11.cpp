#include "RenderDX11.h"
#pragma comment(lib, "D3DX11.lib")
#include <D3DX11async.h>
#include <d3dcompiler.h>

RenderDX11::RenderDX11(HWND hWnd) : EngineInterface()
{
	this->hWnd = hWnd;
	terrain = new Terrain();
	terrainPos = terrain->getPosition();

	camera = nullptr;
	g_swapChain = nullptr;
}

void RenderDX11::setMouse(POINT pos)
{

}

void RenderDX11::setRect(RECT t)
{
	r = t;

	if(!g_swapChain)
		init();
}

HRESULT RenderDX11::init()
{
	HRESULT hr = S_OK;
	
    UINT width = r.right - r.left;
    UINT height = r.bottom - r.top;

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
	rasterDesc.CullMode = D3D11_CULL_BACK;
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

	D3D11_INPUT_ELEMENT_DESC standardLayout[] =
	{
		{ "POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",		0, DXGI_FORMAT_R32G32B32_FLOAT, 0, sizeof(float) * 3, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "TEXCOORD",	0, DXGI_FORMAT_R32G32_FLOAT,	0, sizeof(float) * 6, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	/* Create shaders */
	ID3DBlob *terrainBlob;
	compileShader("..\\Shaders\\defaultVS.hlsl", "vs_4_0", &terrainBlob);
	g_device->CreateVertexShader(terrainBlob->GetBufferPointer(), terrainBlob->GetBufferSize(), NULL, &g_terrainVS);
	g_device->CreateInputLayout(standardLayout, ARRAYSIZE(standardLayout), terrainBlob->GetBufferPointer(), terrainBlob->GetBufferSize(), &g_layout);
	terrainBlob->Release();

	compileShader("..\\Shaders\\defaultPS.hlsl", "ps_4_0", &terrainBlob);
	g_device->CreatePixelShader(terrainBlob->GetBufferPointer(), terrainBlob->GetBufferSize(), NULL, &g_terrainPS);

	terrainBlob->Release();

	ID3D11ShaderResourceView *tex;
	hr = D3DX11CreateShaderResourceViewFromFile(g_device, "..\\Textures\\grass.png", NULL, NULL, &tex, NULL);
	if(FAILED(hr))
	{
		MessageBox(this->hWnd, "Image load made fail, lol", "fail, yo", 0);
		return hr;
	}
	g_textures.push_back(tex);
	createSampleStates();
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

HRESULT RenderDX11::createTerrain(int width, int height, float pointStep, bool fromPerlinMap)
{
	std::vector<unsigned int> indexBuffer;
	std::vector<Vertex> vertexBuffer;
	terrain->createTerrain(width, height, pointStep, fromPerlinMap, vertexBuffer, indexBuffer);

	int w = abs(r.right - r.left);
	int h = abs(r.bottom - r.top);
	if(!camera)
		camera = new Camera(w, h, terrain);
	else
		camera->resizeWindow(w, h);

	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = &vertexBuffer.at(0);
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = sizeof(Vertex) * vertexBuffer.size();
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bd.MiscFlags      = 0;

	ID3D11Buffer *buffer = nullptr;
	HRESULT hr = g_device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create terrain vertexbuffer", "ERROR", S_OK);
		return hr;
	}

	terrainVertexBufferID = g_buffers.size();
	g_buffers.push_back(buffer);

	initData.pSysMem = &indexBuffer.at(0);

	bd.Usage = D3D11_USAGE_IMMUTABLE;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.ByteWidth = sizeof(unsigned int) * indexBuffer.size();
	bd.CPUAccessFlags = 0;

	buffer = nullptr;
	hr = g_device->CreateBuffer(&bd, &initData, &buffer);
	if (FAILED(hr))
	{
		MessageBox(NULL,"could not create terrain indexbuffer", "ERROR", S_OK);
		return hr;
	}

	terrainIndexBufferID = g_buffers.size();
	g_buffers.push_back(buffer);

	return S_OK;
}

const float color[4] = {0.f, 1.f, 1.f, 1.f};
void RenderDX11::renderScene()
{
	g_deviceContext->ClearRenderTargetView(g_renderTargetView, color);
	g_deviceContext->ClearDepthStencilView(g_depthStencilView, D3D11_CLEAR_DEPTH, 1.f, 0);

	CBOnChange cb;
	cb.viewProj = camera->getView() * camera->getProj();
	cb.position = elm::vec4(camera->getEye(), 1.f);
	cb.world = elm::mat4();
	g_deviceContext->UpdateSubresource(g_buffers.at(cbOnChangeID), 0, NULL, &cb, 0, 0);

	// Terrain
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

	g_deviceContext->DrawIndexed(terrain->getIndexCount(), 0, 0);
	
	g_swapChain->Present(0, 0);
}

RenderDX11::~RenderDX11()
{
	SAFE_DELETE(terrain);
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
}