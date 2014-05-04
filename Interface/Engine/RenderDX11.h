#pragma once

#include <D3D11.h>
#include <map>
#include <vector>
#include <string>

#include "EngineInterface.h"
#include "Terrain.h"
#include "Camera.h"
#include "Mesh3D.h"
#include "Object3D.h"

#include "ModelDefinitions.h"

#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = nullptr; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = nullptr; }

using std::map;
using std::string;

struct CBOnce
{
	elm::mat4 crap;
};

struct CBOnChange
{
	elm::mat4 viewProj, world;
	elm::vec4 position;
};

class RenderDX11
{
friend class Engine;
private:
	int terrainVertexBufferID, terrainIndexBufferID, modelID, cbOnceID, cbOnChangeID, terrainIndexCount;

	elm::vec3 terrainPos;

	std::vector<uint> *iBuffer;
	
	RECT r;
	HWND hWnd;

	Camera *camera;

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

	ID3D11SamplerState			*g_wrap,
								*g_clamp;
								
	ID3D11DepthStencilState		*g_depthStencilStateEnable;
	ID3D11DepthStencilState		*g_depthStencilStateDisable;

	ID3D11InputLayout			*g_layout;
	ID3D11InputLayout			*g_otherlayout;

	ID3D11VertexShader			*g_terrainVS;
	ID3D11PixelShader			*g_terrainPS;

	ID3D11VertexShader			*g_modelVS;
	ID3D11PixelShader			*g_modelPS;

	std::vector<ID3D11Buffer*>	g_buffers;
	std::vector<ID3D11ShaderResourceView*> g_textures;

	std::vector<Mesh3D*>		g_meshes;

	std::vector<Object3D*>		g_objects;
	std::vector<Composition>	g_comps;

	HRESULT init();
	HRESULT createSampleStates();
	HRESULT compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob);

	HRESULT createBuffer(void* data, int numElements, int bytesPerElement, int &bufferID);
	HRESULT createIndexBuffer(void* data, int numElements, int &bufferID);

	HRESULT createSRV(unsigned int& _outId, string _fileName);
	/********************************** 
		Internal Data Representation
	***********************************/
	/* Shader Resources */
	map< unsigned int, ID3D11Buffer*>				m_buffers;
	map< unsigned int, ID3D11ShaderResourceView*>	m_SRVs;

public:
	RenderDX11(HWND hWnd);
	~RenderDX11();

	void renderScene();
	void setRect(RECT t);
	void setMouse(POINT pos);

	void setTerrainIndexCount(int count)	{ terrainIndexCount = count; }
	void setCamera(Camera *cam)				{ camera = cam; }

	void updateTerrainBuffer(std::vector<Vertex> *vBuffer, uint startID, uint amount);
	void createAndSetTerrainBuffers(std::vector<Vertex> *vBuffer, std::vector<uint> *iBuffer);
};