/*
	*******************************
			File: elm.hpp
	*******************************

	Copyright © Emil Bertilsson 2014. All rights reserved.

	Matrix operations; transpose, inverse, perspective and such
*/

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_mat2x2.hpp"
#include "type_mat3x3.hpp"
#include "type_mat4x4.hpp"

namespace elm
{
	/* Resets values from rows as values in columns and vice versa */
	inline mat2 transpose(const mat2 &m)
	{
		mat2 out;

		out.r[0].x = m.r[0].x;	out.r[1].x = m.r[0].y;
		out.r[0].y = m.r[1].x;	out.r[1].y = m.r[1].y;

		return out;
	}

	/* Resets values from rows as values in columns and vice versa */
	inline mat3 transpose(const mat3 &m)
	{
		mat3 out;

		out.r[0].x = m.r[0].x;	out.r[1].x = m.r[0].y;	out.r[2].x = m.r[0].z;
		out.r[0].y = m.r[1].x;	out.r[1].y = m.r[1].y;	out.r[2].y = m.r[1].z;
		out.r[0].z = m.r[2].x;	out.r[1].z = m.r[2].y;	out.r[2].z = m.r[2].z;
				
		return out;
	}

	/* Resets values from rows as values in columns and vice versa */
	inline mat4 transpose(const mat4 &m)
	{
		mat4 out;

		out.r[0].x = m.r[0].x;	out.r[1].x = m.r[0].y;	out.r[2].x = m.r[0].z;	out.r[3].x = m.r[0].w;
		out.r[0].y = m.r[1].x;	out.r[1].y = m.r[1].y;	out.r[2].y = m.r[1].z;	out.r[3].y = m.r[1].w;
		out.r[0].z = m.r[2].x;	out.r[1].z = m.r[2].y;	out.r[2].z = m.r[2].z;	out.r[3].z = m.r[2].w;
		out.r[0].w = m.r[3].x;	out.r[1].w = m.r[3].y;	out.r[2].w = m.r[3].z;	out.r[3].w = m.r[3].w;

		return out;
	}

	/* Creates rotation matrix for rotation around a given axis */
	template<typename T>
	inline void rotationAxis(T &mOut, const vec3 &axis, float angle)
	{
		mOut = T();

		float cosa = cos(angle);
		float sina = sin(angle);

		mOut.r[0].x = axis.x * axis.x * (1 - cosa) + cosa;
		mOut.r[0].y = axis.x * axis.y * (1 - cosa) + axis.z * sina;
		mOut.r[0].z = axis.x * axis.z * (1 - cosa) - axis.y * sina;
		
		mOut.r[1].x = axis.x * axis.y * (1 - cosa) - axis.z * sina;
		mOut.r[1].y = axis.y * axis.y * (1 - cosa) + cosa;
		mOut.r[1].z = axis.y * axis.z * (1 - cosa) + axis.x * sina;
		
		mOut.r[2].x = axis.x * axis.z * (1 - cosa) + axis.y * sina;
		mOut.r[2].y = axis.y * axis.z * (1 - cosa) - axis.x * sina;
		mOut.r[2].z = axis.z * axis.z * (1 - cosa) + cosa;
	}

	/* Returns a rotation matrix along all axis */
	template<typename T>
	inline void yawPitchRoll(T &mOut, const vec3 &rotationAxis)
	{
		float sinx = sin(rotationAxis.x), siny = sin(rotationAxis.y), sinz = sin(rotationAxis.z);
		float cosx = cos(rotationAxis.x), cosy = cos(rotationAxis.y), cosz = cos(rotationAxis.z);

		mOut.r[0].x = cosz * cosy + sinz * sinx * siny;
		mOut.r[0].y = sinz * cosx;
		mOut.r[0].z = cosz * -siny + sinz * sinx * cosy;
		
		mOut.r[1].x = -sinz * cosy + cosz * sinx * siny;
		mOut.r[1].y = cosz * cosx;
		mOut.r[1].z = sinz * siny + cosz * sinx * cosy;
		
		mOut.r[2].x = cosx * siny;
		mOut.r[2].y = -sinx;
		mOut.r[2].z = cosx * cosy;
	}

	/* Returns true if all vectors in the matrix are perpendicular to each other */
	inline bool isOrthogonal(const mat2 &m)
	{
		return	vectorsAreOrthogonal(m.r[0], m.r[1]);
	}

	/* Returns true if all vectors in the matrix are perpendicular to each other */
	inline bool isOrthogonal(const mat3 &m)
	{
		return	vectorsAreOrthogonal(m.r[0], m.r[1]) && vectorsAreOrthogonal(m.r[0], m.r[2]) &&
				vectorsAreOrthogonal(m.r[1], m.r[2]);
	}

	/* Returns true if all vectors in the matrix are perpendicular to each other */
	inline bool isOrthogonal(const mat4 &m)
	{
		return	vectorsAreOrthogonal(m.r[0], m.r[1]) && vectorsAreOrthogonal(m.r[0], m.r[2]) &&
				vectorsAreOrthogonal(m.r[0], m.r[3]) && vectorsAreOrthogonal(m.r[1], m.r[2]) &&
				vectorsAreOrthogonal(m.r[1], m.r[3]) && vectorsAreOrthogonal(m.r[2], m.r[3]);
	}

	/* Creates a translation matrix */
    inline void translate(mat4 &mOut, float x, float y, float z)
    {
        mOut = mat4();
        mOut.r[3].x = x;	mOut.r[3].y = y;	mOut.r[3].z = z;
    }

	/* Creates a translation matrix */
	inline void translate(mat4 &mOut, const vec3 &v)
    {
        mOut = mat4();
        mOut.r[3].x = v.x;	mOut.r[3].y = v.y;	mOut.r[3].z = v.z;
    }

	/* Creates and reaturns a scaing matrix */
	inline mat4 scalingMatrix(float x, float y, float z)
	{
		mat4 out;
		out.r[0].x = x;
		out.r[1].y = y;
		out.r[2].z = z;
		return out;
	}

	/* Creates and reaturns a scaing matrix */
	inline mat4 scalingMatrix(const vec3 &scale)
	{
		mat4 out;
		out.r[0].x = scale.x;
		out.r[1].y = scale.y;
		out.r[2].z = scale.z;
		return out;
	}

	/* Creates and returns a translation matrix */
	inline mat4 translationMatrix(float x, float y, float z)
	{
		mat4 out;
		out.r[3].x = x;
		out.r[3].y = y;
		out.r[3].z = z;
		return out;
	}

	/* Creates and returns a translation matrix */
	inline mat4 translationMatrix(const vec3 &v)
	{
		mat4 out;
		out.r[3].x = v.x;
		out.r[3].y = v.y;
		out.r[3].z = v.z;
		return out;
	}

	/* Determinant for a 2 by 2 matrix */
	inline float determinant(const mat2 &m)
	{
		return	m.r[0].x * m.r[1].y - m.r[0].y * m.r[1].x;
	}

	/* Determinant for a 3 by 3 matrix */
	inline float determinant(const mat3 &m)
	{
		// Factorization of the definition of determinant
		return	m.r[0].x * (m.r[1].y * m.r[2].z - m.r[2].y * m.r[1].z) +
				m.r[1].x * (m.r[2].y * m.r[0].z - m.r[0].y * m.r[2].z) +
				m.r[2].x * (m.r[0].y * m.r[1].z - m.r[1].y * m.r[0].z);
	}

	/* Determinant for a 4 by 4 matrix */
	inline float determinant(const mat4 &m)
	{
		// Factorization of the definition of determinant with duplicated data saved.
		// Goes from 72 multiplications to 28
		float m20m31 = m.r[2].x * m.r[3].y, m20m32 = m.r[2].x * m.r[3].z, m20m33 = m.r[2].x * m.r[3].w;
		float m21m30 = m.r[2].y * m.r[3].x, m21m32 = m.r[2].y * m.r[3].z, m21m33 = m.r[2].y * m.r[3].w;
		float m22m30 = m.r[2].z * m.r[3].x, m22m31 = m.r[2].z * m.r[3].y, m22m33 = m.r[2].z * m.r[3].w;
		float m23m30 = m.r[2].w * m.r[3].x, m23m31 = m.r[2].w * m.r[3].y, m23m32 = m.r[2].w * m.r[3].z;

		return	m.r[0].x * (m.r[1].y * (m22m33 - m23m32) + m.r[1].z * (m23m31 - m21m33) + m.r[1].w * (m21m32 - m22m31)) +
				m.r[0].y * (m.r[1].x * (m23m32 - m22m33) + m.r[1].z * (m20m33 - m23m30) + m.r[1].w * (m22m30 - m20m32)) +
				m.r[0].z * (m.r[1].x * (m21m33 - m23m31) + m.r[1].y * (m23m30 - m20m33) + m.r[1].w * (m20m31 - m21m30)) +
				m.r[0].w * (m.r[1].x * (m22m31 - m21m32) + m.r[1].y * (m20m32 - m22m30) + m.r[1].z * (m21m30 - m20m31));
	}

	/* Creates the inverse matatrix for a 2 by 2 matrix */
	inline mat2 inverse(const mat2 &m)
	{
		mat2 out;
		out.r[0].x =  m.r[1].y;
		out.r[0].y = -m.r[0].y;
		out.r[1].x = -m.r[1].x;
		out.r[1].y =  m.r[0].x;
	}

	/* Creates the inverse matrix for a 3 by 3 matrix */
	inline mat3 inverse(const mat3 &m)
	{
		mat3 out;
		out.r[0].x =  determinant(mat2(m.r[1].y, m.r[1].z, m.r[2].y, m.r[2].z));
		out.r[1].x = -determinant(mat2(m.r[1].x, m.r[1].z, m.r[2].x, m.r[2].z));
		out.r[2].x =  determinant(mat2(m.r[1].x, m.r[1].y, m.r[2].x, m.r[2].y));
		
		out.r[0].y = -determinant(mat2(m.r[0].y, m.r[0].z, m.r[2].y, m.r[2].z));
		out.r[1].y =  determinant(mat2(m.r[0].x, m.r[0].z, m.r[2].x, m.r[2].z));
		out.r[2].y = -determinant(mat2(m.r[0].x, m.r[0].y, m.r[2].x, m.r[2].y));
		
		out.r[0].z =  determinant(mat2(m.r[0].y, m.r[0].z, m.r[1].y, m.r[1].z));
		out.r[1].z = -determinant(mat2(m.r[0].x, m.r[0].z, m.r[1].x, m.r[1].z));
		out.r[2].z =  determinant(mat2(m.r[0].x, m.r[0].y, m.r[1].x, m.r[1].y));

		// Allow it to crash if matrix is not invertable (i.e if determinant is 0)
		out *= 1 / determinant(m);

		return out;
	}

	/* Creates the inverse matrix for the basic matrix type (4 by 4) */
	inline mat4 inverse(const mat4 &m)
	{
		mat4 out;
		out.r[0].x =  determinant(mat3(m.r[1].y, m.r[1].z, m.r[1].w, m.r[2].y, m.r[2].z, m.r[2].w, m.r[3].y, m.r[3].z, m.r[3].w));
		out.r[1].x = -determinant(mat3(m.r[1].x, m.r[1].z, m.r[1].w, m.r[2].x, m.r[2].z, m.r[2].w, m.r[3].x, m.r[3].z, m.r[3].w));
		out.r[2].x =  determinant(mat3(m.r[1].x, m.r[1].y, m.r[1].w, m.r[2].x, m.r[2].y, m.r[2].w, m.r[3].x, m.r[3].y, m.r[3].w));
		out.r[3].x = -determinant(mat3(m.r[1].x, m.r[1].y, m.r[1].z, m.r[2].x, m.r[2].y, m.r[2].z, m.r[3].x, m.r[3].y, m.r[3].z));
		
		out.r[0].y = -determinant(mat3(m.r[0].y, m.r[0].z, m.r[0].w, m.r[2].y, m.r[2].z, m.r[2].w, m.r[3].y, m.r[3].z, m.r[3].w));
		out.r[1].y =  determinant(mat3(m.r[0].x, m.r[0].z, m.r[0].w, m.r[2].x, m.r[2].z, m.r[2].w, m.r[3].x, m.r[3].z, m.r[3].w));
		out.r[2].y = -determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].w, m.r[2].x, m.r[2].y, m.r[2].w, m.r[3].x, m.r[3].y, m.r[3].w));
		out.r[3].y =  determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].z, m.r[2].x, m.r[2].y, m.r[2].z, m.r[3].x, m.r[3].y, m.r[3].z));
		
		out.r[0].z =  determinant(mat3(m.r[0].y, m.r[0].z, m.r[0].w, m.r[1].y, m.r[1].z, m.r[1].w, m.r[3].y, m.r[3].z, m.r[3].w));
		out.r[1].z = -determinant(mat3(m.r[0].x, m.r[0].z, m.r[0].w, m.r[1].x, m.r[1].z, m.r[1].w, m.r[3].x, m.r[3].z, m.r[3].w));
		out.r[2].z =  determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].w, m.r[1].x, m.r[1].y, m.r[1].w, m.r[3].x, m.r[3].y, m.r[3].w));
		out.r[3].z = -determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].z, m.r[1].x, m.r[1].y, m.r[1].z, m.r[3].x, m.r[3].y, m.r[3].z));
		
		out.r[0].w = -determinant(mat3(m.r[0].y, m.r[0].z, m.r[0].w, m.r[1].y, m.r[1].z, m.r[1].w, m.r[2].y, m.r[2].z, m.r[2].w));
		out.r[1].w =  determinant(mat3(m.r[0].x, m.r[0].z, m.r[0].w, m.r[1].x, m.r[1].z, m.r[1].w, m.r[2].x, m.r[2].z, m.r[2].w));
		out.r[2].w = -determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].w, m.r[1].x, m.r[1].y, m.r[1].w, m.r[2].x, m.r[2].y, m.r[2].w));
		out.r[3].w =  determinant(mat3(m.r[0].x, m.r[0].y, m.r[0].z, m.r[1].x, m.r[1].y, m.r[1].z, m.r[2].x, m.r[2].y, m.r[2].z));

		// Allow it to crash if matrix is not invertable (i.e if determinant is 0)
		out *= 1 / determinant(m);

		return out;
	}

	/* Creates a projection matrix for left hand coordinate systems */
	inline void perspectiveFovLH(mat4 &mOut, float fov, float aspectRatio, float zNear, float zFar)
	{
		float yscale = cos(fov * .5f) / sin(fov * .5f);

		mOut = mat4();
		mOut.r[3].w = 0;

		mOut.r[0].x = yscale / aspectRatio;
		mOut.r[1].y = yscale;
		mOut.r[2].z = zFar / (zFar - zNear);					mOut.r[2].w = 1;
		mOut.r[3].z = -(zNear * zFar) / (zFar - zNear);
	}

	/* Creates a projection matrix for right hand coordinate systems */
	inline void perspectiveFovRH(mat4 &mOut, float fov, float aspectRatio, float zNear, float zFar)
	{
		float yscale = cos(fov * .5f) / sin(fov * .5f);

		mOut = mat4();
		mOut.r[3].w = 0;

		mOut.r[0].x = yscale / aspectRatio;
		mOut.r[1].y = yscale;
		mOut.r[2].z = (zFar + zNear) / (zFar - zNear);			mOut.r[2].w = -1;
		mOut.r[3].z = (2 * zNear * zFar) / (zNear - zFar);
	}

	/* Creates a view matrix for left hand coordinate systems */
	inline void lookAtLH(mat4 &mOut, const vec3 &look, const vec3 &up, const vec3 &eye)
	{
		vec3 right = cross(up, look);

		mOut.r[0].x = right.x;	        mOut.r[0].y = up.x;				mOut.r[0].z = look.x;	        mOut.r[0].w = 0;
		mOut.r[1].x = right.y;	        mOut.r[1].y = up.y;				mOut.r[1].z = look.y;	        mOut.r[1].w = 0;
		mOut.r[2].x = right.z;	        mOut.r[2].y = up.z;				mOut.r[2].z = look.z;	        mOut.r[2].w = 0;
        mOut.r[3].x = dot(right, -eye);	mOut.r[3].y = dot(up, -eye);	mOut.r[3].z = dot(look, -eye);  mOut.r[3].w = 1;
	}

	/* Creates a view matrix for left hand coordinate systems */
	inline void lookAtLHP(mat4 &mOut, const vec3 &lookatTarget, const vec3 &up, const vec3 &eye)
	{
		vec3 look = normalize(lookatTarget - eye);
		vec3 right = normalize(cross(up, look));

		mOut.r[0].x = right.x;	        mOut.r[0].y = up.x;				mOut.r[0].z = look.x;	        mOut.r[0].w = 0;
		mOut.r[1].x = right.y;	        mOut.r[1].y = up.y;				mOut.r[1].z = look.y;	        mOut.r[1].w = 0;
		mOut.r[2].x = right.z;	        mOut.r[2].y = up.z;				mOut.r[2].z = look.z;	        mOut.r[2].w = 0;
        mOut.r[3].x = dot(-right, eye);	mOut.r[3].y = dot(-up, eye);	mOut.r[3].z = dot(-look, eye);  mOut.r[3].w = 1;
	}

	/* Creates a view matrix for right hand coordinate systems */
    inline void lookAtRH(mat4 &mOut, const vec3 &look, const vec3 &up, const vec3 &eye)
    {
        vec3 left = cross(look, up);

        mOut.r[0].x = left.x;	mOut.r[0].y = up.x;		mOut.r[0].z = -look.x;	mOut.r[0].w = 0;
		mOut.r[1].x = left.y;	mOut.r[1].y = up.y;		mOut.r[1].z = -look.y;	mOut.r[1].w = 0;
		mOut.r[2].x = left.z;	mOut.r[2].y = -up.z;	mOut.r[2].z = -look.z;	mOut.r[2].w = 0;
		mOut.r[3].x = -eye.x;	mOut.r[3].y = -eye.y;	mOut.r[3].z = eye.z;	mOut.r[3].w = 1;
    }
}