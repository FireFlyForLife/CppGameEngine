#pragma once
#include <vector>
#include "Tile.h"
#include "Point.h"
#include "Includes.h"

namespace GameEngine
{
	class TileMap
	{
	public:
		const int width, height;
		const int tile_scale;

		TileMap(int width = 10, int height = 10, int scale = 16);
		~TileMap();

		Tile* at(Point) const;
		Tile* at(int, int) const;
		void set(Tile*, Point);
		bool blocking(Point);
	protected:
		std::vector<std::vector<Tile*>> tiles;
	};
}
