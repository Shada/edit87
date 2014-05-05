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
		friend void operator/=(mat3 &m, float a)		{ m = m / a; }

		int dimension()
		{
			return 3;
		}

		/* Column vectors */
		__declspec(property(put = _setc, get = _getc)) vec3 c[3];

		const vec3 _getc(int i) const			{ return vec3(r[0][i], r[1][i], r[2][i]); }
		vec3 _getc(int i)						{ return vec3(r[0][i], r[1][i], r[2][i]); }
		const float _getc(int i, int j) const	{ return r[j][i]; }
		float _getc(int i, int j)				{ return r[j][i]; }

		void _setc(int i, const vec3 &v)		{ r[0][i] = v.x; r[1][i] = v.y; r[2][i] = v.z; }
		void _setc(int i, int j, float a)		{ r[j][i] = a; }

		/* Indivudual elements */
		ELM_PROPERTY(float, _11);
		ELM_PROPERTY(float, _12);
		ELM_PROPERTY(float, _13);
		ELM_PROPERTY(float, _21);
		ELM_PROPERTY(float, _22);
		ELM_PROPERTY(float, _23);
		ELM_PROPERTY(float, _31);
		ELM_PROPERTY(float, _32);
		ELM_PROPERTY(float, _33);

		ELM_PROPERTY_GET(_11) { return r[0].x; }		ELM_PROPERTY_GETCONST(_11) { return r[0].x; }
		ELM_PROPERTY_GET(_12) { return r[0].y; }		ELM_PROPERTY_GETCONST(_12) { return r[0].y; }
		ELM_PROPERTY_GET(_13) { return r[0].z; }		ELM_PROPERTY_GETCONST(_13) { return r[0].z; }
		ELM_PROPERTY_GET(_21) { return r[1].x; }		ELM_PROPERTY_GETCONST(_21) { return r[1].x; }
		ELM_PROPERTY_GET(_22) { return r[1].y; }		ELM_PROPERTY_GETCONST(_22) { return r[1].y; }
		ELM_PROPERTY_GET(_23) { return r[1].z; }		ELM_PROPERTY_GETCONST(_23) { return r[1].z; }
		ELM_PROPERTY_GET(_31) { return r[2].x; }		ELM_PROPERTY_GETCONST(_31) { return r[2].x; }
		ELM_PROPERTY_GET(_32) { return r[2].y; }		ELM_PROPERTY_GETCONST(_32) { return r[2].y; }
		ELM_PROPERTY_GET(_33) { return r[2].z; }		ELM_PROPERTY_GETCONST(_33) { return r[2].z; }

		ELM_PROPERTY_SET(_11) { r[0].x = value; }
		ELM_PROPERTY_SET(_12) { r[0].y = value; }
		ELM_PROPERTY_SET(_13) { r[0].z = value; }
		ELM_PROPERTY_SET(_21) { r[1].x = value; }
		ELM_PROPERTY_SET(_22) { r[1].y = value; }
		ELM_PROPERTY_SET(_23) { r[1].z = value; }
		ELM_PROPERTY_SET(_31) { r[2].x = value; }
		ELM_PROPERTY_SET(_32) { r[2].y = value; }
		ELM_PROPERTY_SET(_33) { r[2].z = value; }
	};
}

#endif