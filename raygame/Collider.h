#pragma once
enum ColliderType
{
	CIRCLE,
	BOX
};

class Actor;
class CircleCollider;
class AABBCollider;

class Collider
{
public:
	Collider() {};
	Collider(Actor* owner, ColliderType type) { m_owner = owner;  m_type = type; }

	/// <summary>
	/// Gets the owner of this collider
	/// </summary>
	/// <returns></returns>
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Gets the type of this collider
	/// </summary>
	ColliderType getColliderType() { return m_type; }

	/// <summary>
	/// Checks if the collider overlaps another
	/// </summary>
	/// <param name="other">The actor to check collision against</param>
	bool checkCollision(Actor* other);


	virtual bool checkCollisionCircle(CircleCollider* collider) { return false; }
	virtual bool checkCollisionAABB(AABBCollider* collider) { return false; }
	virtual void draw() {}

private:
	Actor* m_owner;
	ColliderType m_type;
};

