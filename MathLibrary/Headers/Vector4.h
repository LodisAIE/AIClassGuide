#pragma once

namespace MathLibrary
{
    struct Vector4
    {
        float x;
        float y;
        float z;
        float w;

        Vector4();

        Vector4(float x, float y, float z, float w);

        friend Vector4 operator *(float scalar, Vector4 lhs);

        Vector4 operator +(Vector4 rhs);

        Vector4 operator -(Vector4 rhs);

        Vector4 operator *(float scalar);

        Vector4 operator /(float scalar);

        bool operator == (Vector4 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector4 getNormalized();

        /// <summary>
        /// Returns the normalized version of the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector4 normalize(Vector4 vector);

        /// <summary>
        /// Changes this vector to have a magnitude of 1.
        /// </summary>
        Vector4 normalize();

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector4 lhs, Vector4 rhs);

        /// <summary>
       /// Returns the cross product of the two vectors given.
       /// </summary>
       /// <param name="lhs"></param>
       /// <param name="rhs"></param>
       /// <returns></returns>
        static Vector4 crossProduct(Vector4 lhs, Vector4 rhs);
    };
}


