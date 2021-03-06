#pragma once
#include <D3D11.h>
#include "Terrain.h"
#include <string>

#define MaxTextures 20
#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }

class Blendmap
{
public:
	Blendmap();
	~Blendmap();
	void init(ID3D11Device *_g_device, ID3D11DeviceContext *_g_deviceContext, std::vector<ID3D11ShaderResourceView*> *_g_textures, HWND *_hWnd);
	void applayBrush(float _radius, float _intensity, elm::vec2 _origin, char* _texture, float _step);
	void CSexec();

private:

	void createTexture2DArray(int _width, int _height);
	int LoadTextureInToTextureArray(const char *pAddr, int Index);
	void createUAVTexture2D(int _width, int _height);
	void createUAVBlendTexture2D(int _width, int _height);
	void createUAVTextureView();
	void createUAVTextureViewArray();
	void createUAVTextureView3D();
	void createShaderResourceView();
	void createShaderResourceViewArray();
	void createComputeShader(std::string _CSshaderName);
	HRESULT compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob);
	void createTexture3D(unsigned int _width, unsigned int _height, unsigned int _depth);
	void createShaderResourceView3D();
	void CSexecupdate();
	int addTexture(const char *_texture);

	struct textureHandler
	{
		std::string texturePath;
		int textureIndex;
	};

	struct cbConfig
	{
		float radius;
		float intensity;
		elm::vec2 origin;
		elm::vec2 textureIndex;
		elm::vec2 pad;
	};

	cbConfig config;

	ID3D11Buffer *cbuffer;

	HWND *hWnd;

	ID3D11Device				*g_device;
	ID3D11DeviceContext			*g_deviceContext;

	std::vector<ID3D11ShaderResourceView*> *g_textures;
	std::vector<textureHandler> textureArrayHandler;
	ID3D11Texture2D* textureArray;
	ID3D11ShaderResourceView* srvArray;

	ID3D11Texture3D* blendmapsTextures;
	ID3D11Texture2D* blendmapsTexturesArray;
	ID3D11UnorderedAccessView* uavtd;
	ID3D11UnorderedAccessView* uavtdArray;
	ID3D11ShaderResourceView* blendmapsSRV;
	ID3D11ShaderResourceView* blendmapsSRVArray;
	//ID3D11ShaderResourceView* blendmapsReadSRV;

	ID3D11Texture2D *uavTexture;
	ID3D11UnorderedAccessView*  uav;
	ID3D11ShaderResourceView* uavSRV;
	ID3D11ComputeShader *computeShader;
	ID3D11ComputeShader *computeShaderUpdate;
	ID3D11ComputeShader *computeShaderInit;


	bool initBlendmap;
	int nrOfTextures;



};

