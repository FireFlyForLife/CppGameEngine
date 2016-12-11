#pragma once
#include "Tile.h"

namespace GameEngine
{
	class TileMap
	{
	public:
		TileMap();
		~TileMap();
	protected:
		objects::Tile tiles[10][10];
	};
}
