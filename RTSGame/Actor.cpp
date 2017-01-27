#include "Actor.h"



namespace GameEngine
{
	Actor::Actor()
		: Entity(0, 0, -1)
	{
	}

	Actor::Actor(float x, float y, int texture)
		: Entity(x, y, texture)
	{
	}

	Actor::Actor(float x, float y, std::string texture_name)
		: Actor(x, y, Global::texture_manager.getID(texture_name))
	{
	}

	Actor::~Actor()
	{
	}

	int Actor::getHealth()
	{
		return health;
	}
	void Actor::setHealth(int newHealth)
	{
		health = newHealth;
	}
	void Actor::addHealth(int addHealth)
	{
		health += addHealth;
	}
}
