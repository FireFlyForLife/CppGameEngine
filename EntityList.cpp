#include "EntityList.h"


namespace GameEngine {
	EntityList::EntityList()
	{
	}


	EntityList::~EntityList()
	{
		for each (Entity* entity in entities)
		{
			delete entity;
		}
	}
	std::vector<Entity*> EntityList::getByIndex(size_t from, size_t to)
	{
		std::vector<Entity*> results;

		for (size_t i = from; i < to; i++) {
			Entity* entity = entities.at(i);
			if (entity != nullptr) {
				results.push_back(entity);
			}
		}

		return results;
	}

	std::vector<Entity*> EntityList::getInside(const Rectangle & bounds)
	{
		BoxShape boxshape(bounds);
		std::vector<Entity*> results;

		for each (Entity* entity in entities)
		{
			Shape* collider = entity->getCollider();
			BoxShape* box = static_cast<BoxShape*>(collider);
			if (collider != nullptr && hasOverlap(collider, collider))
				results.push_back(entity);
		}

		return results;
	}

}