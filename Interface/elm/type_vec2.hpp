/*
	*******************************
		  File: type_vec2.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	2 dimensional vector with all apropriate operators

*/

#ifndef _TYPES_VEC2_HPP_
#define _TYPES_VEC2_HPP_

// Not all paths returns a value, and nor should they
#pragma warning(disable : 4715)

namespace elm
{
	struct vec2
	{
		float x, y;
		vec2()					: x(0), y(0) {}
		vec2(float x, float y)	: x(x), y(y) {}
		vec2(float xy)			: x(xy), y(xy) {}
		float &operator[](int a)
		{
			switch(a)
			{
				case 0 :	return x;
				case 1 :	return y;
			}
		}
		const float &operator[](int a) const
		{
			switch(a)
			{
				case 0 :	return x;
				case 1 :	return y;
			}
		}
		friend vec2 operator+(const vec2 &v, const vec2 &u)
		{
			return vec2(v.x + u.x, v.y + u.y);
		}
		friend vec2 operator-(const vec2 &v, const vec2 &u)
		{
			return vec2(v.x - u.x, v.y - u.y);
		}
		friend vec2 operator*(const vec2 &v, const vec2 &u)
		{
			return vec2(v.x * u.x, v.y * u.y);
		}
		friend vec2 operator*(const vec2 &v, float a)
		{
			return vec2(v.x * a, v.y * a);
		}
		friend vec2 operator/(const vec2 &v, float a)
		{
			return v * (1.f / a);
		}
		friend vec2 operator-(const vec2 &v)
		{
			return vec2(-v.x, -v.y);
		}
		friend bool operator==(const vec2 &v, const vec2 &u)
		{
			return v.x == u.x && v.y == u.y;
		}
		friend bool operator!=(const vec2 &v, const vec2 &u)
		{
			return v.x != u.x || v.y != u.y;
		}
		friend bool operator==(const vec2 &v, float a)
		{
			return v.x == a && v.y == a;
		}
		friend bool operator!=(const vec2 &v, float a)
		{
			return v.x != a || v.y != a;
		}

		friend void operator+=(vec2 &v, const vec2 &u)	{ v = v + u; }
		friend void operator-=(vec2 &v, const vec2 &u)	{ v = v - u; }
		friend void operator*=(vec2 &v, const vec2 &u)	{ v = v * u; }
		friend void operator*=(vec2 &v, float a)		{ v = v * a; }
		friend void operator/=(vec2 &v, float a)		{ v = v * (1.f / a); }

		int dimension()
		{
			return 2;
		}
	};
}

// Re-enable warnings for the rest of the code
#pragma warning(default : 4715)
#endif