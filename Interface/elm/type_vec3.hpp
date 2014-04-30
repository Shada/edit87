/*
	*******************************
		  File: type_vec3.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	3 dimensional vector with all apropriate operators

*/

#ifndef _TYPES_VEC3_HPP_
#define _TYPES_VEC3_HPP_

// Not all paths returns a value, and nor should they
#pragma warning(disable : 4715)

namespace elm
{
	struct vec3
	{
		float x, y, z;
		vec3()							: x(0), y(0), z(0) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		vec3(vec2 v, float z)			: x(v.x), y(v.y), z(z) {}
		vec3(float xyz)					: x(xyz), y(xyz), z(xyz) {}
		float& operator[](int a)
        {
            switch(a)
            {
                case 0:		return x;
                case 1:		return y;
                case 2:		return z;
            }
		}
		const float& operator[](int a) const
        {
            switch(a)
            {
                case 0:		return x;
                case 1:		return y;
                case 2:		return z;
            }
		}
		friend vec3 operator+(const vec3 &v, const vec3 &u)
		{
			return vec3(v.x + u.x, v.y + u.y, v.z + u.z);
		}
		friend vec3 operator-(const vec3 &v, const vec3 &u)
		{
			return vec3(v.x - u.x, v.y - u.y, v.z - u.z);
		}
		friend vec3 operator*(const vec3 &v, const vec3 &u)
		{
			return vec3(v.x * u.x, v.y * u.y, v.z * u.z);
		}
		friend vec3 operator*(const vec3 &v, float a)
		{
			return vec3(v.x * a, v.y * a, v.z * a);
		}
		friend vec3 operator/(const vec3 &v, float a)
		{
			return v * (1.f / a);
		}
		friend vec3 operator-(const vec3 &v)
		{
			return vec3(-v.x, -v.y, -v.z);
		}
		friend bool operator==(const vec3 &v, const vec3 &u)
		{
			return v.x == u.x && v.y == u.y && v.z == u.z;
		}
		friend bool operator!=(const vec3 &v, const vec3 &u)
		{
			return v.x != u.x || v.y != u.y || v.z != u.z;
		}
		friend bool operator==(const vec3 &v, float a)
		{
			return v.x == a && v.y == a && v.z == a;
		}
		friend bool operator!=(const vec3 &v, float a)
		{
			return v.x != a || v.y != a || v.z != a;
		}

		friend void operator+=(vec3 &v, const vec3 &u)	{ v = v + u; }
		friend void operator-=(vec3 &v, const vec3 &u)	{ v = v - u; }
		friend void operator*=(vec3 &v, const vec3 &u)	{ v = v * u; }
		friend void operator*=(vec3 &v, float a)		{ v = v * a; }
		friend void operator/=(vec3 &v, float a)		{ v = v * (1.f / a); }

		int dimension()
		{
			return 3;
		}

		__declspec(property(get = _getxz, put = _setxz)) vec2 xz;

		vec2 _getxz()
		{
			return vec2(x, z);
		}
		void _setxz(const vec2 &v)
		{
			x = v.x;
			z = v.y;
		}
	};
}

// Re-enable warnings for the rest of the code
#pragma warning(default : 4715)
#endif