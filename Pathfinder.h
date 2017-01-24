#pragma once
#include "Point.h"
#include "World.h"
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>

namespace GameEngine
{
	struct Node {
		Point point;
		Node* node;
	};

	std::vector<Point> findPath(World * game_world, const Point& from, const Point& to);
	
}

