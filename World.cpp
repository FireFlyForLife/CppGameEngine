#include "World.h"

namespace GameEngine {
	World::World()
	{
		map = new TileMap(10, 10);
		entity_list = new EntityList();
	}


	World::~World()
	{

	}
}