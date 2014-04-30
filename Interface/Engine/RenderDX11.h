#pragma once

#include <D3D11.h>
#include <vector>
#include "EngineInterface.h"
#include "Terrain.h"

#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }

class RenderDX11 : public EngineInterface
{
private:
	int terrainID;
	
	RECT r;
	HWND hWnd;

	Terrain *terrain;

	D3D_DRIVER_TYPE				g_driverType;
	D3D_FEATURE_LEVEL			g_featureLevel;
	ID3D11Device				*g_device;
	ID3D11DeviceContext			*g_deviceContext;
	IDXGISwapChain				*g_swapChain;
	ID3D11RenderTargetView		*g_renderTargetView;
	ID3D11ShaderResourceView	*g_shaderView;
	ID3D11RasterizerState		*g_rasterizerState;

	ID3D11Texture2D				*g_depthStencil,
								*g_renderTargetTexture;
	ID3D11DepthStencilView		*g_depthStencilView;
								
								
	ID3D11BlendState			*g_blendEnable,
								*g_blendDisable,
								*g_blendAlpha;
								
	ID3D11DepthStencilState		*g_depthStencilStateEnable;
	ID3D11DepthStencilState		*g_depthStencilStateDisable;

	std::vector<ID3D11Buffer*>	g_buffers;

	HRESULT compileShader(LPCWSTR filePath, LPCSTR shaderType);

public:
	RenderDX11(HWND hWnd);
	~RenderDX11();

	HRESULT init();

	void renderScene();
	void setRect(RECT t)		{ r = t; }

	HRESULT createTerrain(int width, int height, int pointStep, bool fromPerlinMap);
};