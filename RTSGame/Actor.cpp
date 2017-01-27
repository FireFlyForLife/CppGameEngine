#include "Actor.h"



namespace GameEngine
{
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
