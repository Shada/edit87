/*
	*******************************
		 File: type_mat3x3.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Matrix 3 by 3 with all apropriate operators

*/

#ifndef _TYPES_MAT3X3_HPP_
#define _TYPES_MAT3X3_HPP_

namespace elm
{
	struct mat3
	{
		vec3 r[3];
		mat3()
		{
			r[0] = vec3(1, 0, 0);
			r[1] = vec3(0, 1, 0);
			r[2] = vec3(0, 0, 1);
		}
		mat3(vec3 r1, vec3 r2, vec3 r3)
		{
			r[0] = r1;	r[1] = r2;	r[2] = r3;
		}
		mat3(float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33)
		{
			r[0] = vec3(_11, _12, _13);
			r[1] = vec3(_21, _22, _23);
			r[2] = vec3(_31, _32, _33);
		}
		vec3& operator[](int i)
		{
			return r[i];
		}
		const vec3& operator[](int i) const
		{
			return r[i];
		}
		friend mat3 operator+(const mat3 &m, const mat3 &n)
		{
			return mat3(m.r[0] + n.r[0], m.r[1] + n.r[1], m.r[2] + n.r[2]);
		}
		friend mat3 operator-(const mat3 &m, const mat3 &n)
		{
			return mat3(m.r[0] - n.r[0], m.r[1] - n.r[1], m.r[2] - n.r[2]);
		}
		friend mat3 operator*(const mat3 &m, const mat3 &n)
		{
			mat3 out;

			out.r[0].x = m.r[0].x * n.r[0].x + m.r[0].y * n.r[1].x + m.r[0].z * n.r[2].x;
			out.r[0].y = m.r[0].x * n.r[0].y + m.r[0].y * n.r[1].y + m.r[0].z * n.r[2].y;
			out.r[0].z = m.r[0].x * n.r[0].z + m.r[0].y * n.r[1].z + m.r[0].z * n.r[2].z;
			
			out.r[1].x = m.r[1].x * n.r[0].x + m.r[1].y * n.r[1].x + m.r[1].z * n.r[2].x;
			out.r[1].y = m.r[1].x * n.r[0].y + m.r[1].y * n.r[1].y + m.r[1].z * n.r[2].y;
			out.r[1].z = m.r[1].x * n.r[0].z + m.r[1].y * n.r[1].z + m.r[1].z * n.r[2].z;
			
			out.r[2].x = m.r[2].x * n.r[0].x + m.r[2].y * n.r[1].x + m.r[2].z * n.r[2].x;
			out.r[2].y = m.r[2].x * n.r[0].y + m.r[2].y * n.r[1].y + m.r[2].z * n.r[2].y;
			out.r[2].z = m.r[2].x * n.r[0].z + m.r[2].y * n.r[1].z + m.r[2].z * n.r[2].z;

			return out;
		}
		friend mat3 operator*(const mat3 &m, float a)
		{
			return mat3(m.r[0] * a, m.r[1] * a, m.r[2] * a);
		}
		friend mat3 operator/(const mat3 &m, float a)
		{
			return m * (1.f / a);
		}
		friend mat3 operator-(const mat3 &m)
		{
			return mat3(-m.r[0], -m.r[1], -m.r[2]);
		}
		friend bool operator==(const mat3 &m, const mat3 &n)
		{
			return m.r[0] == n.r[0] && m.r[1] == n.r[1] && m.r[2] == n.r[2];
		}
		friend bool operator!=(const mat3 &m, const mat3 &n)
		{
			return m.r[0] != n.r[0] || m.r[1] != n.r[1] || m.r[2] != n.r[2];
		}
		friend vec3 operator*(const mat3 &m, const vec3 &v)
		{
			vec3 out;
		
			out[0] = m.r[0].x * v.x + m.r[0].y * v.y + m.r[0].z * v.z;
			out[1] = m.r[1].x * v.x + m.r[1].y * v.y + m.r[1].z * v.z;
			out[2] = m.r[2].x * v.x + m.r[2].y * v.y + m.r[2].z * v.z;
		
			return out;
		}

		friend void operator+=(mat3 &m, const mat3 &n)	{ m = m + n; }
		friend void operator-=(mat3 &m, const mat3 &n)	{ m = m - n; }
		friend void operator*=(mat3 &m, const mat3 &n)	{ m = m * n; }
		friend void operator*=(mat3 &m, float a)		{ m = m * a; }
		friend void operator/=(mat3 &m, float a)		{ m = m * (1.f / a); }

		int dimension()
		{
			return 3;
		}

		__declspec(property(get = _getM11, put = _setM11)) float _11;
		__declspec(property(get = _getM12, put = _setM12)) float _12;
		__declspec(property(get = _getM13, put = _setM13)) float _13;
		__declspec(property(get = _getM21, put = _setM21)) float _21;
		__declspec(property(get = _getM22, put = _setM22)) float _22;
		__declspec(property(get = _getM23, put = _setM23)) float _23;
		__declspec(property(get = _getM31, put = _setM31)) float _31;
		__declspec(property(get = _getM32, put = _setM32)) float _32;
		__declspec(property(get = _getM33, put = _setM33)) float _33;

		float _getM11()			{ return r[0].x; }	const float _getM11() const		{ return r[0].x; }
		float _getM12()			{ return r[0].y; }	const float _getM12() const		{ return r[0].y; }
		float _getM13()			{ return r[0].z; }	const float _getM13() const		{ return r[0].z; }
		float _getM21()			{ return r[1].x; }	const float _getM21() const		{ return r[1].x; }
		float _getM22()			{ return r[1].y; }	const float _getM22() const		{ return r[1].y; }
		float _getM23()			{ return r[1].z; }	const float _getM23() const		{ return r[1].z; }
		float _getM31()			{ return r[2].x; }	const float _getM31() const		{ return r[2].x; }
		float _getM32()			{ return r[2].y; }	const float _getM32() const		{ return r[2].y; }
		float _getM33()			{ return r[2].z; }	const float _getM33() const		{ return r[2].z; }

		void _setM11(float a)	{ r[0].x = a;	 }
		void _setM12(float a)	{ r[0].y = a;	 }
		void _setM13(float a)	{ r[0].z = a;	 }
		void _setM21(float a)	{ r[1].x = a;	 }
		void _setM22(float a)	{ r[1].y = a;	 }
		void _setM23(float a)	{ r[1].z = a;	 }
		void _setM31(float a)	{ r[2].x = a;	 }
		void _setM32(float a)	{ r[2].y = a;	 }
		void _setM33(float a)	{ r[2].z = a;	 }
	};
}

#endif