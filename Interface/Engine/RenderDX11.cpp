#include "RenderDX11.h"
#include <d3dcompiler.h>

RenderDX11::RenderDX11(HWND hWnd) : EngineInterface()
{
	this->hWnd = hWnd;
	terrain = new Terrain();
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
    UINT numDriverTypes = ARRAYSIZE( driverTypes );

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
    ID3D11Texture2D *pBackBuffer = NULL, *pEditorBuffer = NULL;
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

    hr = g_device->CreateTexture2D(&descDepth, NULL, &g_depthStencil);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "depthstencil made fail, lol", "fail, yo", 0);
        return hr;
	}

	// Create render target for texture (used by the editor)
	D3D11_TEXTURE2D_DESC textureDesc;
	ZeroMemory(&textureDesc, sizeof(textureDesc));
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;

	hr = g_device->CreateTexture2D(&textureDesc, NULL, &g_renderTargetTexture);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "rendertargettexture made fail, lol", "fail, yo", 0);
        return hr;
	}

	// Setup the description of the render target view
	D3D11_RENDER_TARGET_VIEW_DESC rtDesc;
	rtDesc.Format = textureDesc.Format;
	rtDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	rtDesc.Texture2D.MipSlice = 0;

	// Create the render target view.
	hr = g_device->CreateRenderTargetView(g_renderTargetTexture, &rtDesc, &g_renderTargetView);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "rendertargetview made fail, lol", "fail, yo", 0);
        return hr;
	}

	// Setup the description of the shader resource view
	D3D11_SHADER_RESOURCE_VIEW_DESC srDesc;
	srDesc.Format = textureDesc.Format;	
	srDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srDesc.Texture2D.MostDetailedMip = 0;
	srDesc.Texture2D.MipLevels = 1;

	// Create the shader resource view.
	hr = g_device->CreateShaderResourceView(g_renderTargetTexture, &srDesc, &g_shaderView);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "shaderview made fail, lol", "fail, yo", 0);
        return hr;
	}

    // Create the depth stencil view
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory( &descDSV, sizeof(descDSV) );
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    hr = g_device->CreateDepthStencilView(g_depthStencil, &descDSV, &g_depthStencilView);
    if(FAILED(hr))
	{
		MessageBox(this->hWnd, "depthstencilview made fail, lol", "fail, yo", 0);
        return hr;
	}

    g_deviceContext->OMSetRenderTargets(1, &g_renderTargetView, g_depthStencilView);

	D3D11_RASTERIZER_DESC rasterDesc;

	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;
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


    return S_OK;
}
HRESULT RenderDX11::compileShader(LPCWSTR filePath, LPCSTR shaderType)
{
	UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    flags |= D3DCOMPILE_DEBUG;
#else
	flags |= D3DCOMPILE_OPTIMIZATION_LEVEL3;
#endif

    ID3DBlob* shaderBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;
	ID3DBlob *blob = NULL;
	//D3DReadFileToBlob(filePath,&blob);
    //HRESULT hr = D3DCompileFromFile( filePath, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE,
    //                                 "main", shaderType,
    //                                 flags, 0, &shaderBlob, &errorBlob );
	return S_OK;
}

HRESULT RenderDX11::createTerrain(int width, int height, int pointStep, bool fromPerlinMap)
{
	std::vector<elm::vec3> points = *terrain->createTerrain(width, height, pointStep, fromPerlinMap);

	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = &points.at(0);
	initData.SysMemPitch = 0;
	initData.SysMemSlicePitch = 0;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = sizeof(elm::vec3) * points.size();
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	bd.MiscFlags      = 0;

	ID3D11Buffer *buffer;
	HRESULT hr = g_device->CreateBuffer(&bd, &initData, &buffer);
    if(FAILED(hr))
	{
        MessageBox(NULL,"could not create terrain vertexbuffer", "ERROR", S_OK);
		return hr;
	}

	g_buffers.push_back(buffer);
	terrainID = g_buffers.size() - 1;

	return S_OK;
}

const float color[4] = {1.f, 1.f, 1.f, 0.f};
void RenderDX11::renderScene()
{
	// Terrain
	g_deviceContext->OMSetDepthStencilState(g_depthStencilStateEnable, 0);
	g_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//g_deviceContext->IASetInputLayout(techs.at(shaderID).layout);
	
	float blendFactor[4] = {0.f, 0.f, 0.f, 0.f};
	g_deviceContext->OMSetBlendState(g_blendDisable, blendFactor, 0xffffffff);

	// Set vertex buffer
	UINT stride = sizeof(elm::vec3);
	UINT offset = 0;
	g_deviceContext->IASetVertexBuffers(0, 1, &g_buffers.at(terrainID), &stride, &offset);

	//g_deviceContext->VSSetShader(techs.at(shaderID).vertex, NULL, 0);
	//g_deviceContext->PSSetShader(techs.at(shaderID).pixel, NULL, 0);
	
	//g_deviceContext->PSSetSamplers(0, 1, &techs.at(shaderID).sampler);

	g_deviceContext->Draw(terrain->getSize(), 0);
	
	g_swapChain->Present(0, 0);
	g_deviceContext->ClearRenderTargetView(g_renderTargetView, color);
	g_deviceContext->ClearDepthStencilView(g_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);

	SetWindowTextA(hWnd, "This is now a draw application");
}

RenderDX11::~RenderDX11()
{
	SAFE_DELETE(terrain);

	g_deviceContext->Flush();
    g_deviceContext->ClearState();
    SAFE_RELEASE(g_swapChain);
	SAFE_RELEASE(g_renderTargetView);
	SAFE_RELEASE(g_depthStencil);
	SAFE_RELEASE(g_renderTargetTexture);
	SAFE_RELEASE(g_depthStencilView);
	SAFE_RELEASE(g_shaderView);

    SAFE_RELEASE(g_deviceContext);
    SAFE_RELEASE(g_device);

	SAFE_RELEASE(g_blendEnable);
	SAFE_RELEASE(g_blendDisable);

	SAFE_RELEASE(g_depthStencilStateDisable);
	SAFE_RELEASE(g_depthStencilStateEnable);
}