#pragma once
#include <vector>
#include "Entity.h"

namespace GameEngine {
	class EntityList
	{
	public:
		EntityList();
		~EntityList();

	public:
		std::vector<Entity*> entities;
	};
}
