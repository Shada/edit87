/*
	*******************************
		  File: type_vec4.hpp
	*******************************

	Copyright � Emil Bertilsson 2014. All rights reserved.

	4 dimensional vector with all apropriate operators

*/

#ifndef _TYPES_VEC4_HPP_
#define _TYPES_VEC4_HPP_

// Not all paths returns a value, and nor should they
#pragma warning(disable : 4715)

namespace elm
{
	struct vec4
	{
		float x, y, z, w;
		vec4()										: x(0), y(0), z(0), w(0) {}
		vec4(float x, float y, float z, float w)	: x(x), y(y), z(z), w(w) {}
		vec4(vec3 v, float w)						: x(v.x), y(v.y), z(v.z), w(w) {}
		vec4(float xyzw)							: x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
        float& operator[](int a)
        {
            switch(a)
            {
                case 0:		return x;
                case 1:		return y;
                case 2:		return z;
                case 3:		return w;
            }
        }
		const float& operator[](int a) const
        {
            switch(a)
            {
                case 0:		return x;
                case 1:		return y;
                case 2:		return z;
                case 3:		return w;
            }
        }
		friend vec4 operator+(const vec4 &v, const vec4 &u)
		{
			return vec4(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
		}
		friend vec4 operator-(const vec4 &v, const vec4 &u)
		{
			return vec4(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);
		}
		friend vec4 operator*(const vec4 &v, const vec4 &u)
		{
			return vec4(v.x * u.x, v.y * u.y, v.z * u.z, v.w * u.w);
		}
		friend vec4 operator*(const vec4 &v, float a)
		{
			return vec4(v.x * a, v.y * a, v.z * a, v.w * a);
		}
		friend vec4 operator/(const vec4 &v, float a)
		{
			return v * (1.f / a);
		}
		friend vec4 operator/(float a, const vec4 &v)
		{
			return vec4(a / v.x, a / v.y, a / v.z, a / v.w);
		}
		friend vec4 operator-(const vec4 &v)
		{
			return vec4(-v.x, -v.y, -v.z, -v.w);
		}
		friend bool operator==(const vec4 &v, const vec4 &u)
		{
			return v.x == u.x && v.y == u.y && v.z == u.z && v.w == u.w;
		}
		friend bool operator!=(const vec4 &v, const vec4 &u)
		{
			return v.x != u.x || v.y != u.y || v.z != u.z || v.w != u.w;
		}
		friend bool operator==(const vec4 &v, float a)
		{
			return v.x == a && v.y == a && v.z == a && v.w == a;
		}
		friend bool operator!=(const vec4 &v, float a)
		{
			return v.x != a || v.y != a || v.z != a || v.w != a;
		}

		friend void operator+=(vec4 &v, const vec4 &u)	{ v = v + u; }
		friend void operator-=(vec4 &v, const vec4 &u)	{ v = v - u; }
		friend void operator*=(vec4 &v, const vec4 &u)	{ v = v * u; }
		friend void operator*=(vec4 &v, float a)		{ v = v * a; }
		friend void operator/=(vec4 &v, float a)		{ v = v / a; }

		int dimension()
		{
			return 4;
		}

		ELM_PROPERTY(vec2, xz);
		ELM_PROPERTY(vec3, xyz);

		ELM_PROPERTY_GET(xz)  { return vec2(x, z); }		ELM_PROPERTY_GETCONST(xz)  { return vec2(x, z); }
		ELM_PROPERTY_GET(xyz) { return vec3(x, y, z); }		ELM_PROPERTY_GETCONST(xyz) { return vec3(x, y, z); }

		ELM_PROPERTY_SET(xz)
		{
			x = value.x;
			z = value.y;
		}
		ELM_PROPERTY_SET(xyz)
		{
			x = value.x;
			y = value.y;
			z = value.z;
		}
	};
}

// Re-enable warnings for the rest of the code
#pragma warning(default : 4715)
#endif