#pragma once
#include <vector>
#include "TileMap.h"

namespace GameEngine {
	class World
	{
	public:
		TileMap* map;
		//std::vector<void> entities;//TODO: Create entity class

	public:
		World();
		~World();
	};
}