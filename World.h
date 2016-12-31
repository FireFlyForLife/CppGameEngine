#pragma once
#include <vector>
#include "TileMap.h"
#include "EntityList.h"

namespace GameEngine {
	class World
	{
	public:
		TileMap* map;
		EntityList* entity_list;

	public:
		World();
		~World();
	};
}