#pragma once


#include <Vector2.h>
#include <Matrix3.h>

class Actor;

class Transform2D
{

public:

    /// <param name="owner">The actor that owns this transform</param>
    Transform2D(Actor* owner);
    ~Transform2D();

   /// <returns>The current orientation of this actors z axis.</returns>
    MathLibrary::Vector2 getForward();

    /// <summary>
    /// Rotates the object until its forward matches the value given normalized.
    /// </summary>
    /// <param name="value">The value to set the forward to</param>
    void setForward(MathLibrary::Vector2 value);

    /// <returns>A vector representing the position of the object in the world.</returns>
    MathLibrary::Vector2 getWorldPosition();

    /// <summary>
    /// Sets the world position of the transform.
    /// </summary>
    /// <param name="value">The new world coordinates to place the transform.</param>
    void setWorldPostion(MathLibrary::Vector2 value);


    /// <returns>Returns the position of the actor relative to its parent transform.</returns>
    MathLibrary::Vector2 getLocalPosition();

    /// <summary>
    /// Sets the position of the transform relative to its parent transform.
    /// </summary>
    /// <param name="value">The new local coordinates to place the transform.</param>
    void setLocalPosition(MathLibrary::Vector2 value);

    /// <returns>A pointer to the transform that has been set as this transforms parent.</returns>
    Transform2D* getParent() { return m_parent; }

    /// <returns>Sets the parent of this transform.</return
    void setParent(Transform2D* parent);

    /// <summary>
    /// Sets this transform as the given transforms parent so that their matrices are concatenated for following updates.
    /// </summary>
    /// <param name="child">The new child of the transform.</param>
    void addChild(Transform2D* child);

    /// <summary>
    /// Finds a transform at the given index and sets that transform's parent to be nullptr. DOES NOT DELETE THE CHILD!!
    /// </summary>
    /// <param name="index">The index in the children arrray to remove.</param>
    /// <returns>Returns false if the index is out of bounds.</returns>
    bool removeChild(int index);

    /// <summary>
    /// Sets the given transform's parent to be nullptr. DOES NOT DELETE THE CHILD!!
    /// </summary>
    /// <param name="child">The child to look for in the array to remove.</param>
    /// <returns>Returns false if the actor isn't in the list.</returns>
    bool removeChild(Transform2D* child);


    /// <summary>The amount of children attached to this transform.</summary>
    int getChildCount() { return m_childCount; }

    /// <summary>The array containing the children attached to this transform.</summary>
    Transform2D** getChildren() { return m_children; }

    /// <summary>
    /// Changes the scale of the object to be the values given.
    /// </summary>
    /// <param name="scale">The scale of the object on the x and y axis.</param>
    void setScale(MathLibrary::Vector2 scale);

    /// <summary>
    /// Increases the scale of the transform by the given value.
    /// </summary>
    /// <param name="scale">The amount to scale the object on the x and y axis.</param>
    void scale(MathLibrary::Vector2 scale);

    /// <summary>The width and height of the transform.</summary>
    MathLibrary::Vector2 getScale();

    /// <summary>
    /// Set the rotation angle to be the given value in radians
    /// </summary>
    /// <param name="radians">The angle to se the transform's rotation to</param>
    void setRotation(float radians);

    /// <summary>
    /// Increases the angle of rotation by the given amount.
    /// </summary>
    /// <param name="radians">The amount of radians to increase the rotation by</param>
    void rotate(float radians);

    /// <summary>
    /// Rotates the transform to face the given position
    /// </summary>
    /// <param name="position">The position the transform should be facing</param>
    void lookAt(MathLibrary::Vector2 position);

    /// <returns>Gets the actor this transform is attached to.</returns>
    Actor* getOwner() { return m_owner; }

    /// <summary>
    /// Gets the matrix that is represents this local matrix combined with
    /// the parents global matrix
    /// </summary>
    MathLibrary::Matrix3* getGlobalMatrix();

    /// <summary>
    /// Gets the matrix in local space
    /// </summary>
    MathLibrary::Matrix3* getLocalMatrix();

private:
    /// <summary>
    /// Updates the global transform to be the combination of the paernt and local
    /// transforms. Updates the transforms for all children of this transform
    /// </summary>
    void updateTransforms();

private:
    MathLibrary::Matrix3* m_globalMatrix;
    MathLibrary::Matrix3* m_localMatrix;
    MathLibrary::Matrix3* m_rotation;
    MathLibrary::Matrix3* m_translation;
    MathLibrary::Matrix3* m_scale;
    Transform2D** m_children;
    Transform2D* m_parent;
    int m_childCount;
    Actor* m_owner;
    bool m_shouldUpdateTransforms;
};

