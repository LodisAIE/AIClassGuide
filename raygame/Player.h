#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;

class Player :
	public Actor
{
public:
	Player(float x, float y, const char* name) : Actor(x, y, name) {}

	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

