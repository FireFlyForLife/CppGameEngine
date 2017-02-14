#include "Character.h"



namespace GameEngine
{
	Character::Character()
		: Entity()
	{
	}

	Character::Character(float x, float y, int texture_id)
		: Entity(x, y, texture_id)
	{
	}

	Character::Character(float x, float y, string texture)
		: Entity(x, y, texture)
	{
	}

	Character::~Character()
	{
	}
	int Character::getHealth()
	{
		return health;
	}
	void Character::setHealth(int amount)
	{
		health = amount;
	}
	void Character::addHealth(int amount)
	{
		health += amount;
	}
}
