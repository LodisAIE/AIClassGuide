#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent :
	public Component
{
public:
	MoveComponent() : Component::Component() {}

	/// <summary>
	/// Get the current speed and direction of this actor
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Set the current speed and direction of this actor
	/// </summary>
	/// <param name="velocity">The new velocity of this actor</param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	/// <summary>
	/// Get the maximum magnitude of this actors velocity vector
	/// </summary>
	float getMaxSpeed() { return m_maxSpeed; }

	bool getUpdateFacing() { return m_updateFacing; }
	void setUpdateFacing(bool value) { m_updateFacing = value; }

	/// <summary>
	/// Set the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <param name="maxSpeed"></param>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	//Inherited from component class
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
	bool m_updateFacing;
};

