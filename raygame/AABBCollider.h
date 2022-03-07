#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(Actor* owner);
	AABBCollider(float width, float height, Actor* owner);

	/// <summary>
	/// The width of the collider
	/// </summary>
	float getWidth() { return m_width; }
	/// <summary>
	/// The height of the collider
	/// </summary>
	float getHeight() { return m_height; }

	/// <summary>
	/// The position of the left side of the collider
	/// </summary>
	float getLeft();

	/// <summary>
	/// The position of the right side of the collider
	/// </summary>
	float getRight();

	/// <summary>
	/// The position of the top of the collider
	/// </summary>
	float getTop();

	/// <summary>
	/// The position of the bottom of the collider
	/// </summary>
	float getBottom();

	// Inherited via Collider
	virtual bool checkCollisionCircle(CircleCollider* collider) override;
	virtual bool checkCollisionAABB(AABBCollider* collider) override;

private:
	float m_width;
	float m_height;
};

