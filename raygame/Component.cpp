#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
	m_started = false;
}

void Component::assignOwner(Actor* owner)
{
	if (getOwner())
		return;

	m_owner = owner;
}
