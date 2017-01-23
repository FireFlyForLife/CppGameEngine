#include "World.h"

namespace GameEngine {
	World::World()
	{
		map = new TileMap(this, 150, 150);
		entity_list = new EntityList();
		camera = NULL;
		UI_elements = new EntityList();
	}


	World::~World()
	{
		delete map;
		delete entity_list;
		//delete camera;//TODO: Do I need to delete this?
		delete UI_elements;
	}

	bool World::blocking(const Point& point)
	{
		if (map->blocking(point))
			return true;

		return false;
	}
}