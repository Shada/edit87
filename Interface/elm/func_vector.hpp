/*
	*******************************
	    File: func_vector.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Vector operations; length, dot, normalize and such
*/

#include <vector>

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_mat2x2.hpp"
#include "type_mat3x3.hpp"
#include "type_mat4x4.hpp"

#define _min(a, b) (a < b ? a : b)
#define _max(a, b) (a > b ? a : b)

namespace elm
{
	/* Returns the lengtch of a vector (Euclidian norm) */
	inline float vecLength(const vec2 &v)
	{
		return sqrtf(v.x * v.x + v.y * v.y);
	}

	/* Returns the lengtch of a vector (Euclidian norm) */
	inline float vecLength(const vec3 &v)
	{
		return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	/* Returns the lengtch of a vector (Euclidian norm) */
	inline float vecLength(const vec4 &v)
	{
		return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	/* Returns the Euclidean scalar product from 2 vectors */
	inline float dot(const vec2 &v, const vec2 &u)
	{
		return v.x * u.x + v.y * u.y;
	}

	/* Returns the Euclidean scalar product from 2 vectors */
	inline float dot(const vec3 &v, const vec3 &u)
	{
		return v.x * u.x + v.y * u.y + v.z * u.z;
	}

	/* Returns the Euclidean scalar product from 2 vectors */
	inline float dot(const vec4 &v, const vec4 &u)
	{
		return v.x * u.x + v.y * u.y + v.z * u.z * v.w * u.w;
	}

	/* True if the vectors are perpendicular, i.e if the result of the scalar product is 0 */
	template<typename T>
	inline bool vectorsAreOrthogonal(const T &v, const T &u)
	{
		float res = dot(v, u);
		return res > -0.0001f && res < 0.0001f;
	}

	/* Returns a new vector facing the same direction with the length of 1 */
	template<typename T>
	inline T normalize(const T &v)
	{
		return v * (1.f / vecLength(v));
	}

	/* Returns the resulting angle of a wall collission */
	template<typename T>
	inline T planeReflection(const T &v, const T &n)
	{
		return v - n * dot(v, n) * 2;
	}

	/* Uses floor on all values on the vector */
	inline vec2 vecFloor(const vec2 &v)
	{
		return vec2(floor(v.x), floor(v.y));
	}

	/* Uses floor on all values on the vector */
	inline vec3 vecFloor(const vec3 &v)
	{	
		return vec3(floor(v.x), floor(v.y), floor(v.z));
	}

	/* Uses floor on all values on the vector */
	inline vec4 vecFloor(const vec4 &v)
	{
		return vec4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
	}

	/* Uses ceil on all values on the vector */
	inline vec2 vecCeil(const vec2 &v)
	{
		return vec2(ceil(v.x), ceil(v.y));
	}

	/* Uses ceil on all values on the vector */
	inline vec3 vecCeil(const vec3 &v)
	{	
		return vec3(ceil(v.x), ceil(v.y), ceil(v.z));
	}

	/* Uses ceil on all values on the vector */
	inline vec4 vecCeil(const vec4 &v)
	{
		return vec4(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w));
	}

	/* Takes the smallest of the corresponding values */
	inline vec2 vecMinimize(const vec2 &v, const vec2 &u)
	{
		return vec2(_min(v.x, u.x), _min(v.y, u.y));
	}

	/* Takes the smallest of the corresponding values */
	inline vec3 vecMinimize(const vec3 &v, const vec3 &u)
	{
		return vec3(_min(v.x, u.x), _min(v.y, u.y), _min(v.z, u.z));
	}

	/* Takes the smallest of the corresponding values */
	inline vec4 vecMinimize(const vec4 &v, const vec4 &u)
	{
		return vec4(_min(v.x, u.x), _min(v.y, u.y), _min(v.z, u.z), _min(v.w, u.w));
	}

	/* Takes the smallest of the corresponding values */
	inline vec2 vecMaximize(const vec2 &v, const vec2 &u)
	{
		return vec2(_max(v.x, u.x), _max(v.y, u.y));
	}

	/* Takes the smallest of the corresponding values */
	inline vec3 vecMaximize(const vec3 &v, const vec3 &u)
	{
		return vec3(_max(v.x, u.x), _max(v.y, u.y), _max(v.z, u.z));
	}

	/* Takes the smallest of the corresponding values */
	inline vec4 vecMaximize(const vec4 &v, const vec4 &u)
	{
		return vec4(_max(v.x, u.x), _max(v.y, u.y), _max(v.z, u.z), _max(v.w, u.w));
	}
	
	/* Returns a vector perpendicular to those sent in. Cross product is only defined in 3 dimensions */
	inline vec3 cross(const vec3 &v, const vec3 &u)
	{
		return vec3(v.y * u.z - u.y * v.z, u.x * v.z - v.x * u.z, v.x * u.y - u.x * v.y);
	}

	/* Builds a view frustrum around the camera */
	inline std::vector<vec4> buildViewFrustum(const mat4 &view, const mat4 &proj)
	{
		mat4 viewProj = view * proj;
		std::vector<vec4> frustum(6);

		frustum[0].x = viewProj.r[0].w + viewProj.r[0].x;
		frustum[0].y = viewProj.r[1].w + viewProj.r[1].x;
		frustum[0].z = viewProj.r[2].w + viewProj.r[2].x;
		frustum[0].w = viewProj.r[3].w + viewProj.r[3].x;
		
		frustum[1].x = viewProj.r[0].w - viewProj.r[0].x;
		frustum[1].y = viewProj.r[1].w - viewProj.r[1].x;
		frustum[1].z = viewProj.r[2].w - viewProj.r[2].x;
		frustum[1].w = viewProj.r[3].w - viewProj.r[3].x;
		
		frustum[2].x = viewProj.r[0].w - viewProj.r[0].y;
		frustum[2].y = viewProj.r[1].w - viewProj.r[1].y;
		frustum[2].z = viewProj.r[2].w - viewProj.r[2].y;
		frustum[2].w = viewProj.r[3].w - viewProj.r[3].y;
		
		frustum[3].x = viewProj.r[0].w + viewProj.r[0].y;
		frustum[3].y = viewProj.r[1].w + viewProj.r[1].y;
		frustum[3].z = viewProj.r[2].w + viewProj.r[2].y;
		frustum[3].w = viewProj.r[3].w + viewProj.r[3].y;
		
		frustum[4].x = viewProj.r[0].z;
		frustum[4].y = viewProj.r[1].z;
		frustum[4].z = viewProj.r[2].z;
		frustum[4].w = viewProj.r[3].z;
		
		frustum[5].x = viewProj.r[0].w - viewProj.r[0].z;
		frustum[5].y = viewProj.r[1].w - viewProj.r[1].z;
		frustum[5].z = viewProj.r[2].w - viewProj.r[2].z;
		frustum[5].w = viewProj.r[3].w - viewProj.r[3].z;

		for(unsigned int i = 0; i < 6; i++)
			normalize(frustum[i]);

		return frustum;
	}
}