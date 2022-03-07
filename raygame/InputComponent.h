#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>

class InputComponent :
	public Component
{
public:

	InputComponent() : Component::Component() {}

	MathLibrary::Vector2 getMoveAxis();
	
private:
	RAYLIB_H::KeyboardKey m_action1Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_P;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};

