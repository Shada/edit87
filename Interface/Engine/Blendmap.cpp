#include "Blendmap.h"
#pragma comment(lib, "D3DX11.lib")
#include <D3DX11async.h>
#include <d3dcompiler.h>

Blendmap::Blendmap()
{
	nrOfTextures = 0;
}

Blendmap::~Blendmap()
{
}

void Blendmap::init(ID3D11Device *_g_device, ID3D11DeviceContext *_g_deviceContext, std::vector<ID3D11ShaderResourceView*> *_g_textures, HWND *_hWnd)
{
	HRESULT hr = S_OK;

	g_device = _g_device;
	g_deviceContext = _g_deviceContext;
	hWnd = _hWnd;

	g_textures = _g_textures;

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.ByteWidth = sizeof(cbConfig);
	hr = g_device->CreateBuffer(&bd, NULL, &cbuffer);

	createTexture2DArray(512,512);

}

void Blendmap::applayBrush(float _radius, float _intensity, elm::vec2 _origin, char* _texture, float _step)
{
	//--------------------------------------- set the constant buffer
	int temp = addTexture(_texture);
	
	config.textureIndex.x = (int)(temp / 4);
	config.textureIndex.y = temp % 4;

	config.intensity = _intensity;
	config.origin = _origin / _step;
	config.radius = _radius;
	config.pad = elm::vec2(0, 0);

	g_deviceContext->UpdateSubresource(cbuffer, 0, NULL, (const void*)&config, 0, 0);

	//--------------------------------------- uppdate the textures
	CSexecupdate();
	CSexec();
}

void Blendmap::createTexture2DArray(int _width, int _height)
{
	HRESULT result = S_OK;

	//-------------------------------------------------------------------------- texture
	
	D3D11_TEXTURE2D_DESC texDesc;
	ZeroMemory(&texDesc, sizeof(texDesc));
	texDesc.Width = _width;
	texDesc.Height = _height;
	texDesc.MipLevels = 1;
	texDesc.ArraySize = MaxTextures;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	texDesc.Usage = D3D11_USAGE_DEFAULT;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS;


	result = g_device->CreateTexture2D(&texDesc, NULL, &textureArray);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create texture for render target view.", "RenderDX11 Error", S_OK);
	}

	addTexture("..\\Textures\\ground.jpg");
	addTexture("..\\Textures\\grass.png");
	addTexture("..\\Textures\\lava.jpg");
	addTexture("..\\Textures\\sand.jpg");
	addTexture("..\\Textures\\lavag.jpg");
	//LoadTextureInToTextureArray("..\\Textures\\lava.jpg", 8);


	//---------------------------------------------------------------------------- creating compute shader resources
	createUAVTexture2D(256,256);
	createUAVTextureView();
	createShaderResourceView();

	ID3DBlob *blob;
	compileShader("..\\Shaders\\blendmapCS.hlsl", "cs_5_0", &blob);
	g_device->CreateComputeShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &computeShader);

	compileShader("..\\Shaders\\blendmapuppdateCS.hlsl", "cs_5_0", &blob);
	g_device->CreateComputeShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &computeShaderUpdate);


	//-------------------------------------------------------------------------- texture view

	D3D11_SHADER_RESOURCE_VIEW_DESC dsvDesc;
	ZeroMemory(&dsvDesc, sizeof(dsvDesc));

	dsvDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	dsvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2DARRAY;
	dsvDesc.Texture2DArray.FirstArraySlice = 0;
	dsvDesc.Texture2DArray.ArraySize = MaxTextures;
	dsvDesc.Texture2DArray.MipLevels = 1;
	dsvDesc.Texture2DArray.MostDetailedMip = 0;
	

	result = g_device->CreateShaderResourceView(textureArray, &dsvDesc, &srvArray);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create shader recource view", "RenderDX11 Error", S_OK);
	}

	//------------------------------------------------------------------------- create 3d textures

	//createTexture3D(256,256,5);
	createUAVBlendTexture2D(256,256);

	//createShaderResourceView3D();
	createShaderResourceViewArray();

	//createUAVTextureView3D();
	createUAVTextureViewArray();

	//------------------------------------------------------------------------- first compile



	CSexecupdate();

	CSexec();

	//g_textures->at(0) = uavSRV;

}

int Blendmap::LoadTextureInToTextureArray(const char *pAddr, int Index)
{
	HRESULT hr = S_OK;

	// pAddr should point to file loaded in memory

	// Index is a number between 0 and ArraySize

	D3D11_TEXTURE2D_DESC ArrayDesc;
	textureArray->GetDesc(&ArrayDesc);

	D3D11_TEXTURE2D_DESC desc;

	D3DX11_IMAGE_LOAD_INFO ImageloadInfo;
	ZeroMemory(&ImageloadInfo, sizeof(D3DX11_IMAGE_LOAD_INFO));
	ImageloadInfo.Width = ArrayDesc.Width;
	ImageloadInfo.Height = ArrayDesc.Height;
	ImageloadInfo.Depth = D3DX11_DEFAULT;
	ImageloadInfo.FirstMipLevel = 0;
	ImageloadInfo.MipLevels = ArrayDesc.MipLevels;
	ImageloadInfo.Usage = D3D11_USAGE_STAGING;
	ImageloadInfo.BindFlags = 0;
	ImageloadInfo.CpuAccessFlags = D3D11_CPU_ACCESS_READ;
	ImageloadInfo.MiscFlags = 0;
	ImageloadInfo.Format = ArrayDesc.Format;
	ImageloadInfo.Filter = D3DX11_FILTER_SRGB_IN | D3DX11_FILTER_NONE;  //<- SRGB flag should be used for gamma correct rendering
	ImageloadInfo.MipFilter = D3DX11_FILTER_NONE;
	ImageloadInfo.pSrcInfo = NULL;

	ID3D11Resource *pRes = NULL;

	//ID3D11ShaderResourceView *srv;
	//ID3D11Texture2D *tex;
	//hr = D3DX11CreateShaderResourceViewFromFile(g_device, pAddr, &ImageloadInfo, NULL, &srv, NULL);

	hr = D3DX11CreateTextureFromFile(g_device, pAddr, &ImageloadInfo, NULL, &pRes, NULL);

	if (FAILED(hr))
	{
		MessageBox(*hWnd, "Image load made fail, lol", "fail in Blendmap, yo", 0);
	}


	if (pRes)
	{
		ID3D11Texture2D* pTemp;
		pRes->QueryInterface(__uuidof(ID3D11Texture2D), (LPVOID*)&pTemp);
		pTemp->GetDesc(&desc);

		D3D11_MAPPED_SUBRESOURCE mappedTex2D;

		for (UINT i = 0; i < desc.MipLevels; i++)
		{
			HRESULT hr = g_deviceContext->Map(pRes, i, D3D11_MAP_READ, 0, &mappedTex2D);
			if (FAILED(hr))
			{
				MessageBox(*hWnd, "Something wrong in array placement", "fail in Blendmap, yo", 0);
			}

			//pTextureResource should point to a valid and already created 2D Texture Array
			if (mappedTex2D.pData)
			{
				g_deviceContext->UpdateSubresource(textureArray,
					D3D11CalcSubresource(i, Index, ArrayDesc.MipLevels),
					NULL,
					mappedTex2D.pData,
					mappedTex2D.RowPitch,
					0);

				g_deviceContext->Unmap(pRes, i);
			}
		}

		pTemp->Release();

		pRes->Release();

	}

	return 1;
}

void Blendmap::createUAVTexture2D(int _width, int _height)
{
	HRESULT result = S_OK;


	D3D11_TEXTURE2D_DESC texDesc;
	ZeroMemory(&texDesc, sizeof(texDesc));
	texDesc.Width = _width;
	texDesc.Height = _height;
	texDesc.MipLevels = 1;
	texDesc.ArraySize = 5;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	texDesc.Usage = D3D11_USAGE_DEFAULT;
	texDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_RENDER_TARGET;
	//texDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;

	//result = g_device->CreateTexture2D(&texDesc, NULL, &uavTexture);


	result = g_device->CreateTexture2D(&texDesc, NULL, &uavTexture);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create texture for UAV.", "RenderDX11 Error", S_OK);

	}

}

void Blendmap::createUAVBlendTexture2D(int _width, int _height)
{
	HRESULT result = S_OK;

	D3D11_TEXTURE2D_DESC texDesc;
	ZeroMemory(&texDesc, sizeof(texDesc));
	texDesc.Width = _width;
	texDesc.Height = _height;
	texDesc.MipLevels = 1;
	texDesc.ArraySize = 5;
	texDesc.SampleDesc.Count = 1;
	texDesc.SampleDesc.Quality = 0;
	texDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	texDesc.Usage = D3D11_USAGE_DEFAULT;
	texDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS;
	texDesc.MiscFlags = 0;



	result = g_device->CreateTexture2D(&texDesc, NULL, &blendmapsTexturesArray);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create texture for UAV.", "RenderDX11 Error", S_OK);

	}

}

void Blendmap::createUAVTextureView()
{
	HRESULT result = S_OK;

	result = g_device->CreateUnorderedAccessView(uavTexture, NULL, &uav);

	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create UAV texture for the UAV texture..", "RenderDX11 Error", S_OK);

	}

}

void Blendmap::createUAVTextureViewArray()
{
	HRESULT result = S_OK;

	result = g_device->CreateUnorderedAccessView(blendmapsTexturesArray, NULL, &uavtdArray);

	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create UAV texture for the UAV texture..", "RenderDX11 Error", S_OK);

	}

}

void Blendmap::createUAVTextureView3D()
{
	HRESULT result = S_OK;
	D3D11_UNORDERED_ACCESS_VIEW_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	desc.Texture3D.FirstWSlice = 0;
	desc.Texture3D.MipSlice = 0;
	desc.Texture3D.WSize = 5;
	desc.ViewDimension = D3D11_UAV_DIMENSION_TEXTURE3D;

	result = g_device->CreateUnorderedAccessView(blendmapsTextures, &desc, &uavtd);
	//result = g_device->CreateUnorderedAccessView(blendmapsTextures, NULL, &uavtd);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create UAV texture for the UAV texture..", "RenderDX11 Error", S_OK);

	}

}

void Blendmap::createShaderResourceView()
{
	HRESULT result = S_OK;

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;
	srvDesc.Texture2D.MostDetailedMip = 0;


	//ID3D11ShaderResourceView *srv = NULL;

	result = g_device->CreateShaderResourceView(uavTexture,
		&srvDesc,
		&uavSRV);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create shader resource view.", "RenderDX11 Error", S_OK);
	}

}

void Blendmap::createShaderResourceViewArray()
{
	HRESULT result = S_OK;

	D3D11_SHADER_RESOURCE_VIEW_DESC dsvDesc;
	ZeroMemory(&dsvDesc, sizeof(dsvDesc));

	dsvDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	dsvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2DARRAY;
	dsvDesc.Texture2DArray.FirstArraySlice = 0;
	dsvDesc.Texture2DArray.ArraySize = 5;
	dsvDesc.Texture2DArray.MipLevels = 1;
	dsvDesc.Texture2DArray.MostDetailedMip = 0;


	result = g_device->CreateShaderResourceView(blendmapsTexturesArray, &dsvDesc, &blendmapsSRVArray);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create shader recource view", "RenderDX11 Error", S_OK);
	}
}


HRESULT Blendmap::compileShader(LPCSTR filePath, LPCSTR shaderType, ID3DBlob **shaderBlob)
{
	UINT flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	flags |= D3DCOMPILE_DEBUG;
#else
	flags |= D3DCOMPILE_OPTIMIZATION_LEVEL3;
#endif

	ID3DBlob* errorBlob = nullptr;
	HRESULT hr = D3DX11CompileFromFile(filePath, NULL, NULL, "main", shaderType, flags, 0, NULL, shaderBlob, &errorBlob, NULL);
	if (FAILED(hr))
	{
		if (errorBlob != NULL)
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
		SAFE_RELEASE(errorBlob);
		return hr;
	}
	SAFE_RELEASE(errorBlob);

	return hr;
}

void Blendmap::createTexture3D(unsigned int _width, unsigned int _height, unsigned int _depth)
{
	HRESULT					result;
	D3D11_TEXTURE3D_DESC	desc;

	ZeroMemory(&desc, sizeof(desc));

	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS;
	desc.CPUAccessFlags = 0;
	desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	desc.MipLevels = 1;
	desc.MiscFlags = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;

	desc.Height = _height;
	desc.Depth = _depth;
	desc.Width = _width;

	result = g_device->CreateTexture3D(&desc, NULL, &blendmapsTextures);

	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create 3D texture.", "RenderDX11 Error", S_OK);
	}

	//blendmapsTexturesRead = blendmapsTextures;
}

void Blendmap::createShaderResourceView3D()
{
	HRESULT							result;
	D3D11_SHADER_RESOURCE_VIEW_DESC	desc;
	D3D11_TEXTURE3D_DESC			tDesc;


	blendmapsTextures->GetDesc(&tDesc);
	ZeroMemory(&desc, sizeof(desc));

	desc.Format = tDesc.Format;
	desc.Texture3D.MipLevels = tDesc.MipLevels;
	desc.Texture3D.MostDetailedMip = 0;
	desc.ViewDimension = D3D11_SRV_DIMENSION::D3D_SRV_DIMENSION_TEXTURE3D;

	result = g_device->CreateShaderResourceView(blendmapsTextures, &desc, &blendmapsSRV);

	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create 3D SRV.", "RenderDX11 Error", S_OK);
	}
	/*result = g_device->CreateShaderResourceView(blendmapsTexturesRead, &desc, &blendmapsReadSRV);
	if (FAILED(result))
	{
		MessageBox(NULL, "Failed to create 3D SRV.", "RenderDX11 Error", S_OK);
	}*/
}

void Blendmap::CSexec()
{
	g_deviceContext->PSSetShaderResources(0, 1, &srvArray); // korekt rör ej

	//g_deviceContext->PSSetShaderResources(1, 1, &blendmapsSRV); // 3d map
	g_deviceContext->PSSetShaderResources(1, 1, &blendmapsSRVArray); // 2d array

}

void Blendmap::CSexecupdate()
{
	ID3D11ShaderResourceView* nullARV[1] = { NULL };
	g_deviceContext->PSSetShaderResources(1, 1, nullARV); // 3d map

	// write
	//g_deviceContext->CSSetUnorderedAccessViews(0, 1, &uavtd, NULL); // 3d map
	g_deviceContext->CSSetUnorderedAccessViews(0, 1, &uavtdArray, NULL); // 2d array

	g_deviceContext->CSSetConstantBuffers(0, 1, &cbuffer);

	g_deviceContext->CSSetShader(computeShaderUpdate, NULL, 0);

	g_deviceContext->Dispatch(45, 45, 1);

	g_deviceContext->CSSetShader(NULL, NULL, 0);

	ID3D11UnorderedAccessView* nullUAV[1] = { NULL };
	g_deviceContext->CSSetUnorderedAccessViews(0, 1, nullUAV, NULL);

	//blendmapsTexturesRead = blendmapsTextures; // --------------------------------------------- kolla att detta funkar

}

int Blendmap::addTexture(const char *_texture)
{
	if (nrOfTextures <= 20)
	{
		for (int i = 0; i < nrOfTextures; i++)
		{
			if (strcmp(textureArrayHandler.at(i).texturePath.c_str(),_texture) == 0)
			{
				return i;
			}
		}

		LoadTextureInToTextureArray(_texture,nrOfTextures);
		textureHandler temp;
		temp.textureIndex = nrOfTextures;
		temp.texturePath = _texture;
		textureArrayHandler.push_back(temp);
		nrOfTextures++;
		return nrOfTextures-1;
	}
	else
	{
		MessageBox(NULL, "Using maximum amount of blendmap textures. Maybe you can replace one of the old?", "Blendmap Error", S_OK);
	}
}