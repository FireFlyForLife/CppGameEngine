#include "EntityList.h"


namespace GameEngine {
	EntityList::EntityList()
	{
	}


	EntityList::~EntityList()
	{
		//because everything is a object, everything should delete automatically when going out of scope.
	}

	size_t EntityList::size()
	{
		return entities.size();
	}

	ent_ptr EntityList::add(ent_ptr ptr)
	{
		entities.push_back(ptr);
		return ptr;
	}

	ent_ptr EntityList::add(Entity * ptr)
	{
		ent_ptr pointer(ptr);
		entities.push_back(pointer);
		return pointer;
	}

	ent_ptr EntityList::at(size_t index)
	{
		if(vector_inrange(entities, index))
			return entities.at(index);
		return ent_ptr();
	}

	void EntityList::destroy(size_t ptr)
	{
		auto it = vector_itaratorAt(entities, ptr);
		entities.erase(it);
	}

	void EntityList::destroy(ent_ptr ptr)
	{
		int index = vector_find(entities, ptr);

		if (index != -1) {
			auto it = vector_itaratorAt(entities, index);
			entities.erase(it);
		}
	}

	std::vector<ent_ptr> EntityList::getByIndex(size_t from, size_t to)
	{
		std::vector<ent_ptr> results;

		for (size_t i = from; i < to; i++) {
			ent_ptr entity = entities.at(i);
			if (entity != nullptr) {
				results.push_back(entity);
			}
		}

		return results;
	}

	std::vector<ent_ptr> EntityList::getInside(const Rectangle & bounds)
	{
		BoxShape boxshape(bounds);
		std::vector<ent_ptr> results;

		for each (ent_ptr entity in entities)
		{
			Shape* collider = entity->getCollider();
			BoxShape* box = static_cast<BoxShape*>(collider);
			if (collider != nullptr && hasOverlap(collider, collider))
				results.push_back(entity);
		}

		return results;
	}

	ent_ptr EntityList::findWithTag(const string & tag)
	{
		for each (ent_ptr entity in entities)
		{
			if (entity->tag == tag)
				return entity;
		}
		return nullptr;
	}

	std::vector<ent_ptr> EntityList::findAllWithTag(const string & tag)
	{
		std::vector<ent_ptr> ret;
		for each (ent_ptr entity in entities)
		{
			if (entity->tag == tag)
				ret.push_back(entity);
		}
		return ret;
	}

	auto EntityList::begin()
	{
		return entities.begin();
	}

	auto EntityList::end()
	{
		return entities.end();
	}

}