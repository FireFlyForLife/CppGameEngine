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
}