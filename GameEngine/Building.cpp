#include "Building.h"



namespace GameEngine
{
	Building::Building(float x, float y, std::string texture) : Building(x, y, Global::texture_manager.getID(texture))
	{
		
	}
	Building::Building(float x, float y, int texture_id) : Entity(x, y, texture_id)
	{
		BoxShape* col = new BoxShape();

		SingleTexture& singleTexture = Global::texture_manager.get(texture);
		col->width = singleTexture.bounds.width;
		col->height = singleTexture.bounds.height;

		setCollider(col);
	}

	Building::~Building()
	{
	}

	int Building::getHealth()
	{
		return health;
	}
	void Building::setHealth(int newHealth)
	{
		health = newHealth;
	}
	void Building::removeHealth(int diffHealth)
	{
		health += diffHealth;
	}
}
