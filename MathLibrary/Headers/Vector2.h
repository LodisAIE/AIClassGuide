#pragma once
namespace MathLibrary
{
    struct Vector2
    {
        float x;
        float y;

        Vector2();
        Vector2(float x, float y);

        Vector2 operator +(Vector2 rhs);

        Vector2 operator -(Vector2 rhs);

        Vector2 operator *(float scalar);

        friend Vector2 operator *(float scalar, Vector2 lhs);

        Vector2 operator /(float scalar);

        bool operator ==(Vector2 rhs);

        /// <summary>
        /// Returns the length of the vector.
        /// </summary>
        /// <returns></returns>
        float getMagnitude();

        /// <summary>
        /// Returns a copy of this vector normalized.
        /// </summary>
        /// <returns></returns>
        Vector2 getNormalized();

        /// <summary>
        /// Returns the normalized version of the vector passed in.
        /// </summary>
        /// <param name="vector">The vector that will be normalized</param>
        /// <returns></returns>
        static Vector2 normalize(Vector2 vector);

        /// <summary>
        /// Changes this vector to have a magnitude of 1.
        /// </summary>
        Vector2 normalize();

        /// <summary>
        /// Returns the dot product of the two vectors given.
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float dotProduct(Vector2 lhs, Vector2 rhs);

        /// <summary>
        /// Finds the angle in radians between the two vectors given. 
        /// </summary>
        /// <param name="lhs"></param>
        /// <param name="rhs"></param>
        /// <returns></returns>
        static float findAngle(Vector2 lhs, Vector2 rhs);

    };
}


