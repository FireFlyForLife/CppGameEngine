#include "World.h"

namespace GameEngine {
	World::World()
	{
		map = new TileMap(this, 150, 150);
		entity_list = new EntityList();
		camera = NULL;
		UI_elements = new EntityList();
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
				Tile* tile = map->at(x, y);
				if (tile != nullptr) {
					tile->Update();
				}
			}
		}
		for each (Entity* entity in entity_list->entities)
		{
			if (entity != nullptr) {
				if (entity->getWorld() == nullptr)
					entity->setWorld(this);//TODO: Move this on add to the entity list
				entity->Update();
			}
		}
		for each (Entity* entity in UI_elements->entities)
		{
			if (entity != nullptr) {
				entity->Update();
			}
		}

		Global::time_on_last_frame = SDL_GetTicks();
	}
	Point World::toScreenSpace(const Point & worldSpace)
	{
		int x = worldSpace.x - camera->x();
		int y = worldSpace.y - camera->y();

		return Point(x, y);
	}
	Point World::toWorldSpace(const Point & screenSpace)
	{
		//TODO: Add zooming
		int x = screenSpace.x + camera->x();
		int y = screenSpace.y + camera->y();

		return Point(x, y);
	}
}