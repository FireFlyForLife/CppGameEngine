#include "TileMap.h"

namespace GameEngine
{
	TileMap::TileMap(int width, int height, int scale) : width(width), height(height), tile_scale(scale)
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

	bool TileMap::inRange(const Point & p) const
	{
		return inRange(p.x, p.y);
	}

	bool TileMap::inRange(int x, int y) const
	{
		return x >= 0 && x < width && y >= 0 && y < height;
	}

	Tile * TileMap::at(const Point& p) const
	{
		if (inRange(p))
			return tiles[p.x][p.y];
		return nullptr;
	}

	Tile * TileMap::at(int x, int y) const
	{
		if (inRange(x, y))
			return tiles[x][y];
		return nullptr;
	}

	double TileMap::cost(const Point & point) const
	{
		Tile* tile = at(point);
		return tile ? tile->weight() : 100;
	}

	void TileMap::set(Tile* tile, const Point &p)
	{
		if (!inRange(p))
			return;

		delete tiles[p.x][p.y];
		tiles[p.x][p.y] = tile;
	}

	bool TileMap::blocking(const Point& p) const
	{
		Tile* tile = at(p);
		if (tile)
			return tile->blocking();
		return true;
	}
}
