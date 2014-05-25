#pragma once

#include <D3D11.h>
#include <map>
#include <vector>
#include <string>
#include "EngineInterface.h"

#include "EngineInterface.h"
#include "Terrain.h"
#include "Camera.h"
#include "Mesh3D.h"
#include "Object3D.h"

#include "ModelDefinitions.h"

#include "Blendmap.h"

//#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = nullptr; }
//#define SAFE_DELETE(x) if( x ) { delete(x); (x) = nullptr; }

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

struct Handle
{
	HWND hwnd;
	std::string name;

	IDXGISwapChain				*swapChain;
	ID3D11Device				*device;
	ID3D11DeviceContext			*deviceContext;
	ID3D11RenderTargetView		*renderTargetView;
	ID3D11DepthStencilView		*depthStencilView;

	D3D_DRIVER_TYPE				driverType;
	D3D_FEATURE_LEVEL			featureLevel;
	ID3D11RasterizerState		*rasterizerState;						
								
	ID3D11BlendState			*blendEnable,
								*blendDisable,
								*blendAlpha;

	ID3D11SamplerState			*wrap,
								*clamp;
								
	ID3D11DepthStencilState		*depthStencilStateEnable;
	ID3D11DepthStencilState		*depthStencilStateDisable;

	ID3D11InputLayout			*layout;
	ID3D11InputLayout			*otherlayout;

	ID3D11VertexShader			*terrainVS,
								*modelVS;
	ID3D11PixelShader			*terrainPS,
								*modelPS;

	std::vector<ID3D11Buffer*>	buffers;

	std::vector<ID3D11ShaderResourceView*> textures;

	Camera *camera;
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

	//Handle *primaryHandle;

	Blendmap *blendmap;

	std::vector<Handle>			handles;

	std::vector<Mesh3D*>		g_meshes;

	std::vector<Object3D*>		g_objects;
	std::vector<Composition>	g_comps;

	void render(const Handle &h);

	HRESULT init(Handle &h, int width, int height);
	HRESULT createSampleStates(Handle &h);
	HRESULT compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob);

	HRESULT createBuffer(void* data, int numElements, int bytesPerElement, int &bufferID, Handle &h);
	HRESULT createIndexBuffer(void* data, int numElements, int &bufferID, Handle &h);

	HRESULT createSRV(unsigned int& _outId, string _fileName);
	/********************************** 
		Internal Data Representation
	***********************************/
	/* Shader Resources */
	map< unsigned int, ID3D11Buffer*>				m_buffers;
	map< unsigned int, ID3D11ShaderResourceView*>	m_SRVs;

public:
	RenderDX11();
	~RenderDX11();

	void renderScene();
	void renderScene(std::string name);

	void setTerrainIndexCount(int count)	{ terrainIndexCount = count; }
	void setCamera(Camera *cam, std::string name);

	void updateTerrainBuffer(std::vector<Vertex> *vBuffer);
	void createAndSetTerrainBuffers(std::vector<Vertex> *vBuffer, std::vector<uint> *iBuffer);

	void resizeSurface(int width, int height, std::string _name);
	void addHandle(HWND _hWnd, std::string _name, int width, int height);
	void updateHandle(HWND _hWnd, std::string _name, int width, int height);

	void blendmapBrush(float _radius, float _intensity, elm::vec2 _origin, char* _texture, float _step);
};