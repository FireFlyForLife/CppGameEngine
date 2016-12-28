#include "TileMap.h"

namespace GameEngine
{
	TileMap::TileMap(int width, int height) : width(width), height(height)
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

	Tile * TileMap::at(Point p) const
	{
		return tiles[p.x][p.y];
	}

	Tile * TileMap::at(int x, int y) const
	{
		return tiles[x][y];
	}

	void TileMap::set(Tile* tile, Point p)
	{
		tiles[p.x][p.y] = tile;
	}

	bool TileMap::blocking(Point p)
	{
		Tile* tile = at(p);
		return tile->blocking();
	}
}
