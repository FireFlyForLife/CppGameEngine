#include "World.h"

namespace GameEngine {
	World::World()
	{
		map = new TileMap(this, 150, 150);
		entity_list = new EntityList(this);
		UI_elements = new EntityList(this);
	}


	World::~World()
	{
		delete map;
		delete entity_list;
		//delete camera;//TODO: Do I need to delete this?
		delete UI_elements;
	}

	bool World::blocking(const Point& point)
	{
		if (map->blocking(point))
			return true;

		return false;
	}
	void World::Update()
	{
		for (int x = 0; x < map->width; x++) {
			for (int y = 0; y < map->height; y++) {
				tile_ptr tile = map->at(x, y);
				if (tile != nullptr) {
					tile->Update();
				}
			}
		}
		for (int i = 0; i < entity_list->entities.size(); i++) {
			std::shared_ptr<Entity> entity = entity_list->entities[i];
			if (entity != nullptr) {
				if (entity->getWorld() == nullptr)
					entity->setWorld(this);//TODO: Should I remove this?
				entity->Update();
			}
		}
		for (int i = 0; i < UI_elements->entities.size(); i++) {
			std::shared_ptr<Entity> entity = UI_elements->entities[i];
			if (entity != nullptr) {
				entity->Update();
			}
		}

		Global::time_on_last_frame = SDL_GetTicks();
	}

	void World::LateUpdate() {
		for (int x = 0; x < map->width; x++) {
			for (int y = 0; y < map->height; y++) {
				tile_ptr tile = map->at(x, y);
				if (tile != nullptr) {
					tile->LateUpdate();
				}
			}
		}
		for (int i = 0; i < entity_list->entities.size(); i++) {
			std::shared_ptr<Entity> entity = entity_list->entities[i];
			if (entity != nullptr) {
				entity->LateUpdate();
			}
		}
		for (int i = 0; i < UI_elements->entities.size(); i++) {
			std::shared_ptr<Entity> entity = UI_elements->entities[i];
			if (entity != nullptr) {
				entity->LateUpdate();
			}
		}
	}

	Point World::toScreenSpace(const Point & worldSpace)
	{
		if (camera.expired())
			return worldSpace;
		int x = worldSpace.x - camera.lock()->x();
		int y = worldSpace.y - camera.lock()->y();

		return Point(x, y);
	}
	Point World::toWorldSpace(const Point & screenSpace)
	{
		//TODO: Add zooming
		int x = screenSpace.x + camera.lock()->x();
		int y = screenSpace.y + camera.lock()->y();

		return Point(x, y);
	}
}