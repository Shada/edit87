#pragma once

#include "Model.h"
#include "../elm/elm.hpp"

/* Transformation (explicit) data */
struct Transform
{
	Transform(elm::vec3 _translate = elm::vec3(0), elm::vec3 _rotate = elm::vec3(0), elm::vec3 _scale = elm::vec3(1))
		: m_translate(_translate), m_rotate(_rotate), m_scale(_scale)
	{}

	elm::vec3 m_translate;
	elm::vec3 m_rotate;
	elm::vec3 m_scale;
};

/* Mesh references */
struct Mesh
{
	Mesh(unsigned int _vRef = 0, unsigned int _iRef = 0, unsigned int _iCount = 0, unsigned int _srvRef = 0)
		: m_vBufferRef(_vRef), m_iBufferRef(_iRef), m_SRVRef(_srvRef), m_iCount(_iCount)
	{}

	unsigned int m_vBufferRef;
	unsigned int m_iBufferRef;
	unsigned int m_iCount;
	unsigned int m_SRVRef;
};

/* Shader references */
struct Shader
{
	Shader(unsigned int _vRef = 0, unsigned int _gRef = 0, unsigned int _pRef = 0)
		: m_vRef(_vRef), m_gRef(_gRef), m_pRef(_pRef)
	{}

	unsigned int m_vRef;
	unsigned int m_gRef;
	unsigned int m_pRef;
};