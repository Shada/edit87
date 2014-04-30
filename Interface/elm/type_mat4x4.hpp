/*
	*******************************
		 File: type_mat4x4.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Matrix 4 by 4 with all apropriate operators

*/

#ifndef _TYPES_MAT4X4_HPP_
#define _TYPES_MAT4X4_HPP_

namespace elm
{
	struct mat4
	{
		vec4 r[4];
		mat4()
		{
			r[0] = vec4(1, 0, 0, 0);
			r[1] = vec4(0, 1, 0, 0);
			r[2] = vec4(0, 0, 1, 0);
			r[3] = vec4(0, 0, 0, 1);
		}
		mat4(vec4 r1, vec4 r2, vec4 r3, vec4 r4)
		{
			r[0] = r1;	r[1] = r2;	r[2] = r3;	r[3] = r4;
		}
		mat4(	float _11, float _12, float _13, float _14, float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34, float _41, float _42, float _43, float _44)
		{
			r[0] = vec4(_11, _12, _13, _14);
			r[1] = vec4(_21, _22, _23, _24);
			r[2] = vec4(_31, _32, _33, _34);
			r[3] = vec4(_41, _42, _43, _44);
		}
		vec4& operator[](int i)
		{
			return r[i];
		}
		const vec4& operator[](int i) const
		{
			return r[0];
		}
		friend mat4 operator+(const mat4 &m, const mat4 &n)
		{
			return mat4(m.r[0] + n.r[0], m.r[1] + n.r[1], m.r[2] + n.r[2], m.r[3] + n.r[3]);
		}
		friend mat4 operator-(const mat4 &m, const mat4 &n)
		{
			return mat4(m.r[0] - n.r[0], m.r[1] - n.r[1], m.r[2] - n.r[2], m.r[3] - n.r[3]);
		}
		friend mat4 operator*(const mat4 &m, const mat4 &n)
		{
			mat4 out;

			out.r[0].x = m.r[0].x * n.r[0].x + m.r[0].y * n.r[1].x + m.r[0].z * n.r[2].x + m.r[0].w * n.r[3].x;
			out.r[0].y = m.r[0].x * n.r[0].y + m.r[0].y * n.r[1].y + m.r[0].z * n.r[2].y + m.r[0].w * n.r[3].y;
			out.r[0].z = m.r[0].x * n.r[0].z + m.r[0].y * n.r[1].z + m.r[0].z * n.r[2].z + m.r[0].w * n.r[3].z;
			out.r[0].w = m.r[0].x * n.r[0].w + m.r[0].y * n.r[1].w + m.r[0].z * n.r[2].w + m.r[0].w * n.r[3].w;
			
			out.r[1].x = m.r[1].x * n.r[0].x + m.r[1].y * n.r[1].x + m.r[1].z * n.r[2].x + m.r[1].w * n.r[3].x;
			out.r[1].y = m.r[1].x * n.r[0].y + m.r[1].y * n.r[1].y + m.r[1].z * n.r[2].y + m.r[1].w * n.r[3].y;
			out.r[1].z = m.r[1].x * n.r[0].z + m.r[1].y * n.r[1].z + m.r[1].z * n.r[2].z + m.r[1].w * n.r[3].z;
			out.r[1].w = m.r[1].x * n.r[0].w + m.r[1].y * n.r[1].w + m.r[1].z * n.r[2].w + m.r[1].w * n.r[3].w;
			
			out.r[2].x = m.r[2].x * n.r[0].x + m.r[2].y * n.r[1].x + m.r[2].z * n.r[2].x + m.r[2].w * n.r[3].x;
			out.r[2].y = m.r[2].x * n.r[0].y + m.r[2].y * n.r[1].y + m.r[2].z * n.r[2].y + m.r[2].w * n.r[3].y;
			out.r[2].z = m.r[2].x * n.r[0].z + m.r[2].y * n.r[1].z + m.r[2].z * n.r[2].z + m.r[2].w * n.r[3].z;
			out.r[2].w = m.r[2].x * n.r[0].w + m.r[2].y * n.r[1].w + m.r[2].z * n.r[2].w + m.r[2].w * n.r[3].w;
			
			out.r[3].x = m.r[3].x * n.r[0].x + m.r[3].y * n.r[1].x + m.r[3].z * n.r[2].x + m.r[3].w * n.r[3].x;
			out.r[3].y = m.r[3].x * n.r[0].y + m.r[3].y * n.r[1].y + m.r[3].z * n.r[2].y + m.r[3].w * n.r[3].y;
			out.r[3].z = m.r[3].x * n.r[0].z + m.r[3].y * n.r[1].z + m.r[3].z * n.r[2].z + m.r[3].w * n.r[3].z;
			out.r[3].w = m.r[3].x * n.r[0].w + m.r[3].y * n.r[1].w + m.r[3].z * n.r[2].w + m.r[3].w * n.r[3].w;

			return out;
		}
		friend mat4 operator*(const mat4 &m, float a)
		{
			return mat4(m.r[0] * a, m.r[1] * a, m.r[2] * a, m.r[3] * a);
		}
		friend mat4 operator/(const mat4 &m, float a)
		{
			return m * (1.f / a);
		}
		friend mat4 operator-(const mat4 &m)
		{
			return mat4(-m.r[0], -m.r[1], -m.r[2], -m.r[3]);
		}
		friend bool operator==(const mat4 &m, const mat4 &n)
		{
			return m.r[0] == n.r[0] && m.r[1] == n.r[1] && m.r[2] == n.r[2] && m.r[3] == n.r[3];
		}
		friend bool operator!=(const mat4 &m, const mat4 &n)
		{
			return m.r[0] != n.r[0] || m.r[1] != n.r[1] || m.r[2] != n.r[2] || m.r[3] != n.r[3];
		}
		friend vec3 operator*(const mat4 &m, const vec3 &v)
		{
			vec3 out;

			out[0] = m.r[0].x * v.x + m.r[0].y * v.y + m.r[0].z * v.z;
			out[1] = m.r[1].x * v.x + m.r[1].y * v.y + m.r[1].z * v.z;
			out[2] = m.r[2].x * v.x + m.r[2].y * v.y + m.r[2].z * v.z;

			return out;
		}
		friend vec4 operator*(const mat4 &m, const vec4 &v)
		{
			vec4 out;

			out[0] = m.r[0].x * v.x + m.r[0].y * v.y + m.r[0].z * v.z + m.r[0].w * v.w;
			out[1] = m.r[1].x * v.x + m.r[1].y * v.y + m.r[1].z * v.z + m.r[1].w * v.w;
			out[2] = m.r[2].x * v.x + m.r[2].y * v.y + m.r[2].z * v.z + m.r[2].w * v.w;
			out[3] = m.r[3].x * v.x + m.r[3].y * v.y + m.r[3].z * v.z + m.r[3].w * v.w;

			return out;
		}

		friend void operator+=(mat4 &m, const mat4 &n)	{ m = m + n; }
		friend void operator-=(mat4 &m, const mat4 &n)	{ m = m - n; }
		friend void operator*=(mat4 &m, const mat4 &n)	{ m = m * n; }
		friend void operator*=(mat4 &m, float a)		{ m = m * a; }
		friend void operator/=(mat4 &m, float a)		{ m = m * (1.f / a); }
		
		int dimension()
		{
			return 4;
		}

		__declspec(property(get = _getM11, put = _setM11)) float _11;
		__declspec(property(get = _getM12, put = _setM12)) float _12;
		__declspec(property(get = _getM13, put = _setM13)) float _13;
		__declspec(property(get = _getM14, put = _setM14)) float _14;
		__declspec(property(get = _getM21, put = _setM21)) float _21;
		__declspec(property(get = _getM22, put = _setM22)) float _22;
		__declspec(property(get = _getM23, put = _setM23)) float _23;
		__declspec(property(get = _getM24, put = _setM24)) float _24;
		__declspec(property(get = _getM31, put = _setM31)) float _31;
		__declspec(property(get = _getM32, put = _setM32)) float _32;
		__declspec(property(get = _getM33, put = _setM33)) float _33;
		__declspec(property(get = _getM34, put = _setM34)) float _34;
		__declspec(property(get = _getM41, put = _setM41)) float _41;
		__declspec(property(get = _getM42, put = _setM42)) float _42;
		__declspec(property(get = _getM43, put = _setM43)) float _43;
		__declspec(property(get = _getM44, put = _setM44)) float _44;

		float _getM11()			{ return r[0].x; }	const float _getM11() const		{ return r[0].x; }
		float _getM12()			{ return r[0].y; }	const float _getM12() const		{ return r[0].y; }
		float _getM13()			{ return r[0].z; }	const float _getM13() const		{ return r[0].z; }
		float _getM14()			{ return r[0].w; }	const float _getM14() const		{ return r[0].w; }
		float _getM21()			{ return r[1].x; }	const float _getM21() const		{ return r[1].x; }
		float _getM22()			{ return r[1].y; }	const float _getM22() const		{ return r[1].y; }
		float _getM23()			{ return r[1].z; }	const float _getM23() const		{ return r[1].z; }
		float _getM24()			{ return r[1].w; }	const float _getM24() const		{ return r[1].w; }
		float _getM31()			{ return r[2].x; }	const float _getM31() const		{ return r[2].x; }
		float _getM32()			{ return r[2].y; }	const float _getM32() const		{ return r[2].y; }
		float _getM33()			{ return r[2].z; }	const float _getM33() const		{ return r[2].z; }
		float _getM34()			{ return r[2].w; }	const float _getM34() const		{ return r[2].w; }
		float _getM41()			{ return r[3].x; }	const float _getM41() const		{ return r[3].x; }
		float _getM42()			{ return r[3].y; }	const float _getM42() const		{ return r[3].y; }
		float _getM43()			{ return r[3].z; }	const float _getM43() const		{ return r[3].z; }
		float _getM44()			{ return r[3].w; }	const float _getM44() const		{ return r[3].w; }

		void _setM11(float a)	{ r[0].x = a;	 }
		void _setM12(float a)	{ r[0].y = a;	 }
		void _setM13(float a)	{ r[0].z = a;	 }
		void _setM14(float a)	{ r[0].w = a;	 }
		void _setM21(float a)	{ r[1].x = a;	 }
		void _setM22(float a)	{ r[1].y = a;	 }
		void _setM23(float a)	{ r[1].z = a;	 }
		void _setM24(float a)	{ r[1].w = a;	 }
		void _setM31(float a)	{ r[2].x = a;	 }
		void _setM32(float a)	{ r[2].y = a;	 }
		void _setM33(float a)	{ r[2].z = a;	 }
		void _setM34(float a)	{ r[2].w = a;	 }
		void _setM41(float a)	{ r[3].x = a;	 }
		void _setM42(float a)	{ r[3].y = a;	 }
		void _setM43(float a)	{ r[3].z = a;	 }
		void _setM44(float a)	{ r[3].w = a;	 }
	};
}

#endif