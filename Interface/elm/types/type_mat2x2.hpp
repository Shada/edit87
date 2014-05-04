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
		friend void operator/=(mat2 &m, float a)		{ m = m / a; }

		int dimension()
		{
			return 2;
		}

		/* Column vectors */
		__declspec(property(put = _setc, get = _getc)) vec2 c[2];

		const vec2 _getc(int i) const			{ return vec2(r[0][i], r[1][i]); }
		vec2 _getc(int i)						{ return vec2(r[0][i], r[1][i]); }
		const float _getc(int i, int j) const	{ return r[j][i]; }
		float _getc(int i, int j)				{ return r[j][i]; }

		void _setc(int i, const vec2 &v)		{ r[0][i] = v.x; r[1][i] = v.y; }
		void _setc(int i, int j, float a)		{ r[j][i] = a; }

		/* Indivudual elements */
		ELM_PROPERTY(float, _11);
		ELM_PROPERTY(float, _12);
		ELM_PROPERTY(float, _21);
		ELM_PROPERTY(float, _22);

		ELM_PROPERTY_GET(_11) { return r[0].x; }		ELM_PROPERTY_GETCONST(_11) { return r[0].x; }
		ELM_PROPERTY_GET(_12) { return r[0].y; }		ELM_PROPERTY_GETCONST(_12) { return r[0].y; }
		ELM_PROPERTY_GET(_21) { return r[1].x; }		ELM_PROPERTY_GETCONST(_21) { return r[1].x; }
		ELM_PROPERTY_GET(_22) { return r[1].y; }		ELM_PROPERTY_GETCONST(_22) { return r[1].y; }

		ELM_PROPERTY_SET(_11) { r[0].x = value; }
		ELM_PROPERTY_SET(_12) { r[0].y = value; }
		ELM_PROPERTY_SET(_21) { r[1].x = value; }
		ELM_PROPERTY_SET(_22) { r[1].y = value; }
	};
}

#endif