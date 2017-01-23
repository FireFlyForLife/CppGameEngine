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

		TileMap(class World* parent, int width = 10, int height = 10, int scale = 16);
		~TileMap();

		bool inRange(const Point&) const;
		bool inRange(int x, int y) const;
		Tile* at(const Point&) const;
		Tile* at(int, int) const;
		void set(Tile*, const Point&);
		bool blocking(const Point&) const;
		double cost(const Point&) const;
	protected:
		std::vector<std::vector<Tile*>> tiles;
		World* parent;
	};
}
