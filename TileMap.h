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

		TileMap(int width = 10, int height = 10);
		~TileMap();

		Tile* at(Point);
		void set(Tile*, Point);
		bool blocking(Point);
	protected:
		std::vector<std::vector<Tile*>> tiles;
	};
}
