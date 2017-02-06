#pragma once
#include <vector>
#include "Entity.h"
#include "Vector_Utils.h"
#include "CollisionManager.h"

namespace GameEngine {
	using ent_ptr = std::shared_ptr<Entity>;

	class EntityList
	{
	public:
		EntityList(World* world);
		~EntityList();

		size_t size();

		ent_ptr add(ent_ptr ptr);
		ent_ptr add(Entity* ptr);
		ent_ptr at(size_t index);
		void destroy(size_t ptr);
		void destroy(ent_ptr ptr);

		ent_ptr& operator[](int index) {
			return entities[index];
		}

		std::vector<ent_ptr> getByIndex(size_t from, size_t to);
		std::vector<ent_ptr> getInside(const Rectangle& bounds);
		ent_ptr findWithTag(const string& tag);
		std::vector<ent_ptr> findAllWithTag(const string& tag);

	public:
		std::vector<ent_ptr> entities;

	protected:
		World* parent = nullptr;

	public:
		auto begin();
		auto end();
	};
}
