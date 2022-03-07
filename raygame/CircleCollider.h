#pragma once
#include "Collider.h"
class CircleCollider :
	public Collider
{
public:
	CircleCollider(Actor* owner);
	CircleCollider(float collisionRadius, Actor* owner);

	/// <summary>
	/// Returns the size of this collider
	/// </summary>
	float getCollisionRadius() { return m_collisionRadius; }

	/// <summary>
	/// Sets the size of this collider
	/// </summary>
	void setCollisionRadius(float value) { m_collisionRadius = value; }

	/// <summary>
	/// Checks collsion between this collider and a circle
	/// </summary>
	/// <param name="otherCollider">The other collider to check collision against</param>
	bool checkCollisionCircle(CircleCollider* otherCollider) override;

	/// <summary>
	/// Checks collision between this collider and an AABB
	/// </summary>
	/// <param name="otherCollider">The other collider to check collision against</param>
	bool checkCollisionAABB(AABBCollider* otherCollider) override;

private:
	float m_collisionRadius;
};

