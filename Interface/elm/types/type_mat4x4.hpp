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
			return r[i];
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
		friend void operator/=(mat4 &m, float a)		{ m = m / a; }
		
		int dimension()
		{
			return 4;
		}

		/* Column vectors */
		__declspec(property(put = _setc, get = _getc)) vec4 c[4];

		const vec4 _getc(int i) const			{ return vec4(r[0][i], r[1][i], r[2][i], r[3][i]); }
		vec4 _getc(int i)						{ return vec4(r[0][i], r[1][i], r[2][i], r[3][i]); }
		const float _getc(int i, int j) const	{ return r[j][i]; }
		float _getc(int i, int j)				{ return r[j][i]; }

		void _setc(int i, const vec4 &v)		{ r[0][i] = v.x; r[1][i] = v.y; r[2][i] = v.z; r[3][i] = v.w; }
		void _setc(int i, int j, float a)		{ r[j][i] = a; }

		/* Indivudual elements */
		ELM_PROPERTY(float, _11);
		ELM_PROPERTY(float, _12);
		ELM_PROPERTY(float, _13);
		ELM_PROPERTY(float, _14);
		ELM_PROPERTY(float, _21);
		ELM_PROPERTY(float, _22);
		ELM_PROPERTY(float, _23);
		ELM_PROPERTY(float, _24);
		ELM_PROPERTY(float, _31);
		ELM_PROPERTY(float, _32);
		ELM_PROPERTY(float, _33);
		ELM_PROPERTY(float, _34);
		ELM_PROPERTY(float, _41);
		ELM_PROPERTY(float, _42);
		ELM_PROPERTY(float, _43);
		ELM_PROPERTY(float, _44);

		ELM_PROPERTY_GET(_11) { return r[0].x; }		ELM_PROPERTY_GETCONST(_11) { return r[0].x; }
		ELM_PROPERTY_GET(_12) { return r[0].y; }		ELM_PROPERTY_GETCONST(_12) { return r[0].y; }
		ELM_PROPERTY_GET(_13) { return r[0].z; }		ELM_PROPERTY_GETCONST(_13) { return r[0].z; }
		ELM_PROPERTY_GET(_14) { return r[0].w; }		ELM_PROPERTY_GETCONST(_14) { return r[0].w; }
		ELM_PROPERTY_GET(_21) { return r[1].x; }		ELM_PROPERTY_GETCONST(_21) { return r[1].x; }
		ELM_PROPERTY_GET(_22) { return r[1].y; }		ELM_PROPERTY_GETCONST(_22) { return r[1].y; }
		ELM_PROPERTY_GET(_23) { return r[1].z; }		ELM_PROPERTY_GETCONST(_23) { return r[1].z; }
		ELM_PROPERTY_GET(_24) { return r[1].w; }		ELM_PROPERTY_GETCONST(_24) { return r[1].w; }
		ELM_PROPERTY_GET(_31) { return r[2].x; }		ELM_PROPERTY_GETCONST(_31) { return r[2].x; }
		ELM_PROPERTY_GET(_32) { return r[2].y; }		ELM_PROPERTY_GETCONST(_32) { return r[2].y; }
		ELM_PROPERTY_GET(_33) { return r[2].z; }		ELM_PROPERTY_GETCONST(_33) { return r[2].z; }
		ELM_PROPERTY_GET(_34) { return r[2].w; }		ELM_PROPERTY_GETCONST(_34) { return r[2].w; }
		ELM_PROPERTY_GET(_41) { return r[3].x; }		ELM_PROPERTY_GETCONST(_41) { return r[3].x; }
		ELM_PROPERTY_GET(_42) { return r[3].y; }		ELM_PROPERTY_GETCONST(_42) { return r[3].y; }
		ELM_PROPERTY_GET(_43) { return r[3].z; }		ELM_PROPERTY_GETCONST(_43) { return r[3].z; }
		ELM_PROPERTY_GET(_44) { return r[3].w; }		ELM_PROPERTY_GETCONST(_44) { return r[3].w; }

		ELM_PROPERTY_SET(_11) { r[0].x = value; }
		ELM_PROPERTY_SET(_12) { r[0].y = value; }
		ELM_PROPERTY_SET(_13) { r[0].z = value; }
		ELM_PROPERTY_SET(_14) { r[0].w = value; }
		ELM_PROPERTY_SET(_21) { r[1].x = value; }
		ELM_PROPERTY_SET(_22) { r[1].y = value; }
		ELM_PROPERTY_SET(_23) { r[1].z = value; }
		ELM_PROPERTY_SET(_24) { r[1].w = value; }
		ELM_PROPERTY_SET(_31) { r[2].x = value; }
		ELM_PROPERTY_SET(_32) { r[2].y = value; }
		ELM_PROPERTY_SET(_33) { r[2].z = value; }
		ELM_PROPERTY_SET(_34) { r[2].w = value; }
		ELM_PROPERTY_SET(_41) { r[3].x = value; }
		ELM_PROPERTY_SET(_42) { r[3].y = value; }
		ELM_PROPERTY_SET(_43) { r[3].z = value; }
		ELM_PROPERTY_SET(_44) { r[3].w = value; }
	};
}

#endif