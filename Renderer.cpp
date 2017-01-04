#include "Renderer.h"
#ifdef _DEBUG
#include <iostream>
#endif // !_DEBUG

namespace GameEngine {
	Renderer::Renderer(SDL_Renderer* renderer) : gRenderer(renderer)
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::renderWorld(const World & world)
	{
		//render tilemap
		int offsetX, offsetY;
		if (world.camera != nullptr) {
			offsetX = world.camera->x();
			offsetY = world.camera->y();
		}
		else {
			offsetX = 0;
			offsetY = 0;
		}

		int	scale = world.map->tile_scale;
		Rectangle bounds;
		bounds.x = floor(offsetX / scale);
		bounds.y = floor(offsetY / scale);
		bounds.width = ceil((Global::SCREEN_WIDTH) / scale) + 1;
		bounds.height = ceil((Global::SCREEN_HEIGHT) / scale) + 1;
		Point remaining_offset;
		remaining_offset.x = -(offsetX % scale);
		remaining_offset.y = -(offsetY % scale);
		
		renderTileMap(*world.map, bounds, remaining_offset);

		//renderEntities
		Point offset;
		offset.x = offsetX;
		offset.y = offsetY;
		renderEntityList(*world.entity_list, offset, 0, world.entity_list->entities.size());
	}

	void Renderer::renderTileMap(const TileMap& map, const Rectangle& bounds, const Point& offset)
	{
		int length = map.tile_scale;

		//Get a list of pointers to texture_ids
		int tiles_amount = bounds.width * bounds.height;
		typedef std::pair<int, Point*> dwasd;
		std::vector<dwasd> ids;
		ids.reserve(tiles_amount);
		for (int x = 0; x < bounds.width; x++) {
			for (int y = 0; y < bounds.height; y++) {
				Tile* tile = map.at(x + bounds.x, y + bounds.y);
				if (tile != nullptr) {
					Point* location = new Point(x, y);
					ids.push_back(dwasd(tile->GetTexture(), location));
				}
			}
		}

		//TODO: sort the list incrementaly

		for each (dwasd sorted_tile in ids)
		{
			SingleTexture& texture = Global::texture_manager.get(sorted_tile.first);
			Rectangle target;
			target.x = sorted_tile.second->x * length + offset.x;
			target.y = sorted_tile.second->y * length + offset.y;
			target.width = length;
			target.height = length;
			renderSingleTexture(texture, target);
			delete sorted_tile.second;
		}
	}

	void Renderer::renderTileMap(const TileMap & map)
	{
		Rectangle bound(0, 0, map.width, map.height);
		Point empty_point;
		renderTileMap(map, bound, empty_point);
	}

	void Renderer::renderEntityList(const EntityList & list, const Point& offset, size_t from, size_t to)
	{
		for (size_t i = from; i < to; i++) {
			Entity* entity = list.entities.at(i);
			if (entity != nullptr) {
				//TODO: Account for camera
				SingleTexture& texture = Global::texture_manager.get(entity->getTexture());
				Rectangle target;
				target.x = entity->x();
				target.y = entity->y();
				target.width = texture.bounds.width;
				target.height = texture.bounds.height;
				renderSingleTexture(texture, target);
			}
		}
	}

	void Renderer::renderEntityList(const EntityList & list)
	{
		size_t to = list.entities.size();
		size_t from = 0;
		Point empty_offset;
		renderEntityList(list, empty_offset, from, to);
	}

	void Renderer::renderSingleTexture(const SingleTexture& texture, const Rectangle& target)
	{
		SDL_RenderCopy(gRenderer, texture.raw_texture, &(SDL_Rect)(texture.bounds), &(SDL_Rect)(target));
	}
}