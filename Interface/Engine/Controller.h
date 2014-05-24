#pragma once
#include "ModelDefinitions.h"
#include "../Engine/RenderDX11.h"

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Controller
{
public:
	Controller(void);
	~Controller(void);

	virtual bool init(RenderDX11* _renderer, string _workingDirectory);

#pragma region Create<T>Functions
	/* States */
	HRESULT createBlendState(unsigned int& _outId, D3D11_BLEND _srcBlend, D3D11_BLEND _destBlend, D3D11_BLEND _srvBlendAlpha, bool _enable = TRUE);

	HRESULT createSamplerState(unsigned int& _outId, D3D11_SAMPLER_DESC _desc);

	/* Shader Resources */
	template<typename T>
	HRESULT createBuffer(unsigned int& _outId, std::vector<T>& _data, 
							D3D11_BIND_FLAG _bindFlag, D3D11_USAGE _usage = D3D11_USAGE_DEFAULT,  
							D3D11_CPU_ACCESS_FLAG _accessFlag = (D3D11_CPU_ACCESS_FLAG)0);

	HRESULT createCBuffer(unsigned int& _outId, unsigned int _sizeOf);

	HRESULT createSRV(unsigned int& _outId, string _fileName);

	/* Shaders */
	HRESULT createShader(unsigned int& _outIds, const D3D11_INPUT_ELEMENT_DESC _layout[],
						string _shaderNameVertex = "", string _shaderNameGeometry = "", string _shaderNamePixel = "", 
						string _shaderModel = "4_0");

	template<typename T>
	HRESULT createShader(unsigned int& _outId, const D3D11_INPUT_ELEMENT_DESC _layout[],
							string _shaderName, string _shaderModel);

	/* slask */
	HRESULT createCube(unsigned int& _vId, unsigned int& _iId);

#pragma endregion

	bool addComposition(Composition* _composition);
	bool addProperty(IModel* _model);

	

	virtual void draw();

	virtual bool createTerrain(int width, int height, float pointStep, bool fromPerlinMap);

private:
	/* Project data information */
	string	m_pWorkingDirectory;

	/* Member systems */
	RenderDX11*			m_renderer;
	Terrain*			m_terrain;

	/********************************** 
		Internal Data Representation
	***********************************/
	/* States */
	map< unsigned int, ID3D11BlendState* >			m_blendStates;
	map< unsigned int, ID3D11SamplerState* >		m_samplerStates;
	map< unsigned int, ID3D11InputLayout* >			m_layouts;

	/* Shader Resources */
	map< unsigned int, ID3D11Buffer*>				m_buffers;
	map< unsigned int, ID3D11ShaderResourceView*>	m_SRVs;
	//map< unsigned int, ID3D11Texture2D* >			m_textures;

	/* Shaders */
	map< unsigned int, ID3D11VertexShader* >		m_vertexShaders;
	map< unsigned int, ID3D11GeometryShader* >		m_geometryShaders;
	map< unsigned int, ID3D11PixelShader* >			m_pixelShaders;

	/**********************************
		External Data Representation
	***********************************/
	/* Raw data linkers */
	map< unsigned int, IModel* >		m_properties;

	/* Generic objects */
	map< unsigned int, Composition* >	m_compositions;
};

