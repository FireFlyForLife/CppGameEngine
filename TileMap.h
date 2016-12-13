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
		TileMap(int width = 10, int height = 10);
		~TileMap();

		Tile* at(Point p);
		void setTile(Tile, Point);
		bool blocking(Point p);
	protected:
		std::vector<std::vector<Tile*>> tiles;
	};
}
