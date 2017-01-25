#include "Renderer.h"
#ifdef _DEBUG
#include <iostream>
#endif // !_DEBUG

using std::get;

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

		int scale = world.map->tile_scale;
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
		offset.x = -offsetX;
		offset.y = -offsetY;
		renderEntityList(*world.entity_list, offset, 0, world.entity_list->entities.size());

		//Render UI
		renderEntityList(*world.UI_elements, Point(), 0, world.UI_elements->entities.size());
	}

	void Renderer::renderTileMap(const TileMap& map, const Rectangle& bounds, const Point& offset)
	{
		int length = map.tile_scale;

		//Get a list of pointers to texture_ids
		int tiles_amount = bounds.width * bounds.height;
		typedef std::tuple<int, Tile*, Point*> sortable_tile;
		std::vector<sortable_tile> ids;
		ids.reserve(tiles_amount);
		for (int x = 0; x < bounds.width; x++) {
			for (int y = 0; y < bounds.height; y++) {
				Tile* tile = map.at(x + bounds.x, y + bounds.y);
				if (tile != nullptr) {
					Point* location = new Point(x, y); //TODO: Make this pass by value not pointer
					ids.push_back(sortable_tile(tile->GetTexture(), tile, location));
				}
			}
		}

		//TODO: sort the list incrementaly

		for each (sortable_tile sorted_tile in ids)
		{
			if (get<1>(sorted_tile)->renderSelf) {
				std::pair<SingleTexture*, Rectangle*> texture = get<1>(sorted_tile)->getFrame(gRenderer);
				Rectangle target;
				target.x = get<2>(sorted_tile)->x * length + offset.x;
				target.y = get<2>(sorted_tile)->y * length + offset.y;
				target.width = length;
				target.height = length;
				renderSingleTexture(*texture.first, *texture.second);
			}
			else {
				SingleTexture* texture = &Global::texture_manager.get(get<0>(sorted_tile));
				Rectangle target;
				target.x = get<2>(sorted_tile)->x * length + offset.x;
				target.y = get<2>(sorted_tile)->y * length + offset.y;
				target.width = length;
				target.height = length;
				renderSingleTexture(*texture, target);
			}

			delete get<2>(sorted_tile);
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
				if (entity->renderSelf) {
					std::pair<SingleTexture*, Rectangle*> texture = entity->getFrame(gRenderer);
					Rectangle target;
					target.x = entity->x() + offset.x;
					target.y = entity->y() + offset.y;
					target.width = texture.first->bounds.width;
					target.height = texture.first->bounds.height;
					renderSingleTexture(*texture.first, *texture.second);
				} else {
					SingleTexture& texture = Global::texture_manager.get(entity->getTexture());
					Rectangle target;
					target.x = entity->x() + offset.x;
					target.y = entity->y() + offset.y;
					target.width = texture.bounds.width;
					target.height = texture.bounds.height;
					renderSingleTexture(texture, target);
				}
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