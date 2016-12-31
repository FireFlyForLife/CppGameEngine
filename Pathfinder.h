#pragma once
#include "Point.h"
#include "World.h"

namespace GameEngine
{
	struct Node {
		Point point;
		Node* node;
	};

	Node* findPath(World* game_world);
}

