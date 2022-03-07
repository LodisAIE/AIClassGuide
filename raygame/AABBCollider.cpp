#include "AABBCollider.h"
#include "CircleCollider.h"
#include "Actor.h"
#include "Transform2D.h"

AABBCollider::AABBCollider(Actor* owner) : Collider::Collider(owner, ColliderType::BOX)
{
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;
}

AABBCollider::AABBCollider(float width, float height, Actor* owner) : Collider::Collider(owner, ColliderType::BOX)
{
	m_width = width;
	m_height = height;
}

float AABBCollider::getLeft()
{
	return getOwner()->getTransform()->getWorldPosition().x - getWidth() / 2;
}

float AABBCollider::getRight()
{
	return getOwner()->getTransform()->getWorldPosition().x + getWidth() / 2;
}

float AABBCollider::getTop()
{
	return getOwner()->getTransform()->getWorldPosition().y - getHeight() / 2;
}

float AABBCollider::getBottom()
{
	return getOwner()->getTransform()->getWorldPosition().y + getHeight() / 2;
}

bool AABBCollider::checkCollisionCircle(CircleCollider* collider)
{
	//Return false if the actor is checking collision against itself
	if (collider->getOwner() == getOwner())
		return false;

	//Call the function to check a circle against an AABB
	return collider->checkCollisionAABB(this);
}

bool AABBCollider::checkCollisionAABB(AABBCollider* collider)
{
	//Return false if the actor is checking collision against itself
	if (collider->getOwner() == getOwner())
		return false;

	//Check for AABB overlap
	if (collider->getLeft() <= getRight() &&
		collider->getTop() <= getBottom() &&
		getLeft() <= collider->getRight() &&
		getTop() <= collider->getBottom())
		return true;

	return false;
}