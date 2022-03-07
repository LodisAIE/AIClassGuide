#include "Collider.h"
#include "Actor.h"
#include "CircleCollider.h"
#include "AABBCollider.h"

bool Collider::checkCollision(Actor* other)
{
	//Try to store a collider of either type
	CircleCollider* otherCircleCollider = dynamic_cast<CircleCollider*>(other->getCollider());
	AABBCollider* otherAABBCollider = dynamic_cast<AABBCollider*>(other->getCollider());

	//Check collision based on the collider type
	if (otherCircleCollider)
		return checkCollisionCircle(otherCircleCollider);
	else if (otherAABBCollider)
		return checkCollisionAABB(otherAABBCollider);

	return false;
}