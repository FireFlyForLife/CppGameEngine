#pragma once
#include <vector>
#include "TileMap.h"
#include "EntityList.h"
#include "Camera.h"

namespace GameEngine {
	class World
	{
	public:
		TileMap* map;
		EntityList* entity_list;
		Camera* camera;

	public:
		World();
		~World();
	};
}