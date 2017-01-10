#include "World.h"

namespace GameEngine {
	World::World()
	{
		map = new TileMap(150, 150);
		entity_list = new EntityList();
		camera = NULL;
	}


	World::~World()
	{

	}
	bool World::blocking(const Point& point)
	{
		if (map->blocking(point))
			return true;

		return false;
	}
}