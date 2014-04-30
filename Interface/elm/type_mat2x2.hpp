/*
	*******************************
		 File: type_mat2x2.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Matrix 2 by 2 with all apropriate operators

*/

#ifndef _TYPES_MAT2X2_HPP_
#define _TYPES_MAT2X2_HPP_

namespace elm
{
	struct mat2
	{
		vec2 r[2];
		mat2()
		{
			r[0] = vec2(1, 0);
			r[1] = vec2(0, 1);
		}
		mat2(vec2 r1, vec2 r2)
		{
			r[0] = r1;	r[1] = r2;
		}
		mat2(float _11, float _12, float _21, float _22)
		{
			r[0] = vec2(_11, _12);
			r[1] = vec2(_21, _22);
		}
		vec2& operator[](int i)
		{
			return r[i];
		}
		const vec2& operator[](int i) const
		{
			return r[i];
		}
		friend mat2 operator+(const mat2 &m, const mat2 &n)
		{
			return mat2(m.r[0] + n.r[0], m.r[1] + n.r[1]);
		}
		friend mat2 operator-(const mat2 &m, const mat2 &n)
		{
			return mat2(m.r[0] - n.r[0], m.r[1] - n.r[1]);
		}
		friend mat2 operator*(const mat2 &m, const mat2 &n)
		{
			mat2 out;

			out.r[0].x = m.r[0].x * n.r[0].x + m.r[0].y * n.r[1].x;
			out.r[0].y = m.r[0].x * n.r[0].y + m.r[0].y * n.r[1].y;
			
			out.r[1].x = m.r[1].x * n.r[0].x + m.r[1].y * n.r[1].x;
			out.r[1].y = m.r[1].x * n.r[0].y + m.r[1].y * n.r[1].y;

			return out;
		}
		friend mat2 operator*(const mat2 &m, float a)
		{
			return mat2(m.r[0] * a, m.r[1] * a);
		}
		friend mat2 operator/(const mat2 &m, float a)
		{
			return m * (1.f / a);
		}
		friend mat2 operator-(const mat2 &m)
		{
			return mat2(-m.r[0], -m.r[1]);
		}
		friend bool operator==(const mat2 &m, const mat2 &n)
		{
			return m.r[0] == n.r[0] && m.r[1] == n.r[1];
		}
		friend bool operator!=(const mat2 &m, const mat2 &n)
		{
			return m.r[0] != n.r[0] || m.r[1] != n.r[1];
		}

		friend void operator+=(mat2 &m, const mat2 &n)	{ m = m + n; }
		friend void operator-=(mat2 &m, const mat2 &n)	{ m = m - n; }
		friend void operator*=(mat2 &m, const mat2 &n)	{ m = m * n; }
		friend void operator*=(mat2 &m, float a)		{ m = m * a; }
		friend void operator/=(mat2 &m, float a)		{ m = m * (1.f / a); }

		int dimension()
		{
			return 2;
		}

		__declspec(property(get = _getM11, put = _setM11)) float _11;
		__declspec(property(get = _getM12, put = _setM12)) float _12;
		__declspec(property(get = _getM21, put = _setM21)) float _21;
		__declspec(property(get = _getM22, put = _setM22)) float _22;

		float _getM11()			{ return r[0].x; }	const float _getM11() const		{ return r[0].x; }
		float _getM12()			{ return r[0].y; }	const float _getM12() const		{ return r[0].y; }
		float _getM21()			{ return r[1].x; }	const float _getM21() const		{ return r[1].x; }
		float _getM22()			{ return r[1].y; }	const float _getM22() const		{ return r[1].y; }

		void _setM11(float a)	{ r[0].x = a;	 }
		void _setM12(float a)	{ r[0].y = a;	 }
		void _setM21(float a)	{ r[1].x = a;	 }
		void _setM22(float a)	{ r[1].y = a;	 }
	};
}

#endif