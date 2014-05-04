/*
	*******************************
			File: macros.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Macros for properties and printing
*/

#ifndef _MACROS_
#define _MACROS_

#define ELM_PROPERTY(t, n) __declspec(property(put = _set##n, get = _get##n)) t n; \
	typedef t property_type_##n
#define ELM_PROPERTY_GET(n) property_type_##n _get##n()
#define ELM_PROPERTY_GETCONST(n) const property_type_##n _get##n() const
#define ELM_PROPERTY_SET(n) void _set##n(const property_type_##n& value)

#define PRINT_VEC2(v) std::cout << #v << ": x = " << v.x << ",\ty = " << v.y << std::endl
#define PRINT_VEC3(v) std::cout << #v << ": x = " << v.x << ",\ty = " << v.y << \
	",\tz = " << v.z << std::endl
#define PRINT_VEC4(v) std::cout << #v << ": x = " << v.x << ",\ty = " << v.y << \
	",\tz = " << v.z << ",\tw = " << v.w << std::endl

#define PRINT_MAT2(m) PRINT_VEC2(m.r[0]); PRINT_VEC2(m.r[1])
#define PRINT_MAT3(m) PRINT_VEC3(m.r[0]); PRINT_VEC3(m.r[1]); PRINT_VEC3(m.r[2])
#define PRINT_MAT4(m) PRINT_VEC4(m.r[0]); PRINT_VEC4(m.r[1]); PRINT_VEC4(m.r[2]); PRINT_VEC4(m.r[3])

#endif