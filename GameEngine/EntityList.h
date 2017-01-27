#pragma once
#include <vector>
#include "Entity.h"
#include "CollisionManager.h"

namespace GameEngine {
	class EntityList
	{
	public:
		EntityList();
		~EntityList();

		std::vector<Entity*> getByIndex(size_t from, size_t to);
		std::vector<Entity*> getInside(const Rectangle& bounds);
		Entity* findWithTag(const string& tag);
		std::vector<Entity*> findAllWithTag(const string& tag);

	public:
		std::vector<Entity*> entities;
	};
}
