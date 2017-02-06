#pragma once
#include <vector>
#include "Tile.h"
#include "Point.h"
#include "Includes.h"

namespace GameEngine
{
	using tile_ptr = std::shared_ptr<Tile>;

	class TileMap
	{
	public:
		const int width, height;
		const int tile_scale;

		TileMap(class World* parent, int width = 10, int height = 10, int scale = 16);
		~TileMap();

		bool inRange(const Point&) const;
		bool inRange(int x, int y) const;
		tile_ptr at(const Point&) const;
		tile_ptr at(int, int) const;
		void set(tile_ptr, const Point&);
		void set(Tile*, const Point&);
		bool blocking(const Point&) const;
		double cost(const Point&) const;
	protected:
		std::vector<std::vector<tile_ptr>> tiles;
		World* parent;
	};
}
