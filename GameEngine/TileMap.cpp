#include "TileMap.h"

namespace GameEngine
{
	TileMap::TileMap(class World* parent, int width, int height, int scale) : parent(parent), width(width), height(height), tile_scale(scale)
	{
		tiles.resize(width);
		for (int i = 0; i < width; i++) {
			tiles[i].resize(height, NULL);
		}
	}

	TileMap::~TileMap()
	{
	}

	bool TileMap::inRange(const Point & p) const
	{
		return inRange(p.x, p.y);
	}

	bool TileMap::inRange(int x, int y) const
	{
		return x >= 0 && x < width && y >= 0 && y < height;
	}

	tile_ptr TileMap::at(const Point& p) const
	{
		if (inRange(p))
			return tiles[p.x][p.y];
		return nullptr;
	}

	tile_ptr TileMap::at(int x, int y) const
	{
		if (inRange(x, y))
			return tiles[x][y];
		return nullptr;
	}

	double TileMap::cost(const Point & point) const
	{
		tile_ptr tile = at(point);
		return tile ? tile->weight() : 100;
	}

	void TileMap::set(tile_ptr tile, const Point &p)
	{
		if (!inRange(p))
			return;

		tiles[p.x][p.y] = tile;
		tiles[p.x][p.y]->setWorld(parent);
	}

	void TileMap::set(Tile* tile, const Point& p) {
		if (!inRange(p))
			return;

		tiles[p.x][p.y].reset(tile);
		tiles[p.x][p.y]->setWorld(parent);
	}

	bool TileMap::blocking(const Point& p) const
	{
		tile_ptr tile = at(p);
		if (tile != nullptr)
			return tile->blocking();
		return true;
	}
}
