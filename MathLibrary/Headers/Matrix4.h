#pragma once

struct Vector4;
struct Vector3;
namespace MathLibrary
{
    struct Matrix4
    {
        

        float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;

        Matrix4();

        Matrix4(float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44);

        Matrix4 operator +(Matrix4 rhs);

        Matrix4 operator -(Matrix4 rhs);

        Matrix4 operator *(Matrix4 rhs);

        Vector4 operator *(Vector4 rhs);

        bool operator ==(Matrix4 rhs);

        /// <summary>
        /// Creates a matrix thats been rotated by the given amount of radians
        ///on the z axis.
        /// </summary>
        /// <returns></returns>
        static Matrix4 createRotationZ(float radians);

        /// <summary>
        /// Creates a matrix thats been rotated by the given amount of radians
        ///on the y axis.
        /// </summary>
        /// <returns></returns>
        static Matrix4 createRotationY(float radians);

        /// <summary>
        /// Creates a matrix thats been rotated by the given amount of radians
        ///on the x axis.
        /// </summary>
        /// <returns></returns>
        static Matrix4 createRotationX(float radians);

        /// <summary>
        /// Creates a matrix thats been translated to the given position.
        /// </summary>
        /// <returns></returns>
        static Matrix4 createTranslation(Vector3 position);

        /// <summary>
        /// Creates a matrix thats been scaled by the given vector.
        /// </summary>
        /// <returns></returns>
        static Matrix4 createScale(Vector3 scale);
    };
}


