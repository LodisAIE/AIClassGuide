#pragma once

namespace MathLibrary
{
    struct Vector3
    {
        float x;
        float y;
        float z;

        Vector3();
        Vector3(float x, float y, float z);

        Vector3 operator +(Vector3 rhs);

        Vector3 operator -(Vector3 rhs);

        Vector3 operator *(float scalar);

        friend Vector3 operator *(float scalar, Vector3 lhs);

        Vector3 operator /(float scalar);

        bool operator ==(Vector3 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector3 getNormalized();

        /// <summary>
        /// Returns the normalized version of a the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector3 normalize(Vector3 vector);

        /// <summary>
        /// Changes this vector to have a magnitude of 1.
        /// </summary>
        Vector3 normalize();

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector3 lhs, Vector3 rhs);

        /// <summary>
        /// Returns the cross product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static Vector3 crossProduct(Vector3 lhs, Vector3 rhs);

    };
}


