#include "Unit.h"

namespace GameEngine
{
	Unit::Unit(float x, float y, std::string texture) : Entity(x, y, texture)
	{
		this->collider = new BoxShape(0, 0, 16, 16);
	}

	Unit::Unit(float x, float y, int id) : Entity(x, y, id)
	{
		this->collider = new BoxShape(0, 0, 16, 16);
	}

	Unit::~Unit()
	{
	}

	void Unit::Update()
	{

	}
	int Unit::getHealth()
	{
		return health;
	}
	void Unit::setHealth(int newHealth)
	{
		health = newHealth;
	}
	void Unit::addHealth(int addHealth)
	{
		health += addHealth;
	}
}
