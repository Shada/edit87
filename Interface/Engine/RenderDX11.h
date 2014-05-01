#pragma once

#include <D3D11.h>
#include <vector>
#include "EngineInterface.h"
#include "Terrain.h"
#include "Camera.h"

#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }

struct CBOnce
{
	elm::mat4 projection;
};

struct CBOnChange
{
	elm::mat4 view, world;
	elm::vec4 position;
};

struct Vertex
{
	elm::vec3 position, normal;
	elm::vec2 texCoord;
};

class RenderDX11 : public EngineInterface
{
private:
	int terrainID, modelID, cbOnceID, cbOnChangeID;

	elm::vec3 terrainPos;
	
	RECT r;
	HWND hWnd;

	Camera *camera;
	Terrain *terrain;

	D3D_DRIVER_TYPE				g_driverType;
	D3D_FEATURE_LEVEL			g_featureLevel;
	ID3D11Device				*g_device;
	ID3D11DeviceContext			*g_deviceContext;
	IDXGISwapChain				*g_swapChain;
	ID3D11RenderTargetView		*g_renderTargetView;
	ID3D11ShaderResourceView	*g_shaderView;
	ID3D11RasterizerState		*g_rasterizerState;

	ID3D11DepthStencilView		*g_depthStencilView;								
								
	ID3D11BlendState			*g_blendEnable,
								*g_blendDisable,
								*g_blendAlpha;
								
	ID3D11DepthStencilState		*g_depthStencilStateEnable;
	ID3D11DepthStencilState		*g_depthStencilStateDisable;

	ID3D11InputLayout			*g_layout;

	ID3D11VertexShader			*g_terrainVS;
	ID3D11PixelShader			*g_terrainPS;

	std::vector<ID3D11Buffer*>	g_buffers;

	HRESULT init();
	HRESULT compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob);

public:
	RenderDX11(HWND hWnd);
	~RenderDX11();

	void renderScene();
	void setRect(RECT t);

	HRESULT createTerrain(int width, int height, float pointStep, bool fromPerlinMap);
};