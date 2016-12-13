#include "TileMap.h"

namespace GameEngine
{
	TileMap::TileMap(int height, int width)
	{
		tiles.resize(width);
		for (int i = 0; i < width; i++) {
			tiles[i].resize(height, NULL);
		}


	}

	TileMap::~TileMap()
	{
		for each (std::vector<Tile*> tile_vector in tiles)
		{
			for each (Tile* tile in tile_vector) {
				delete tile;
			}
		}
	}
}
