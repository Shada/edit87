#pragma once

#include <D3D11.h>

class RenderDX11
{
private:
	IDXGISwapChain* swapChain;

	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;
public:
	RenderDX11();
	~RenderDX11();
};