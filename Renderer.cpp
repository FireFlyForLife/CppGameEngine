#include "Renderer.h"


namespace GameEngine {
	Renderer::Renderer(SDL_Renderer* renderer) : gRenderer(renderer)
	{

	}


	Renderer::~Renderer()
	{
	}

	void Renderer::renderTileMap(const TileMap& map, const Rectangle& bounds)
	{
		int length = map.tile_scale;

		//Get a list of pointers to texture_ids
		int tiles_amount = bounds.width * bounds.height;
		typedef std::pair<int, Point*> dwasd;
		std::vector<dwasd> ids;
		ids.reserve(tiles_amount);
		for (int x = bounds.x; x < bounds.width + bounds.x; x++) {
			for (int y = bounds.y; y < bounds.height + bounds.y; y++) {
				Tile* tile = map.at(x, y);
				if (tile != NULL) {
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
			target.x = sorted_tile.second->x * length;
			target.y = sorted_tile.second->y * length;
			target.width = length;
			target.height = length;
			renderSingleTexture(texture, target);
			delete sorted_tile.second;
		}
	}

	void Renderer::renderTileMap(const TileMap & map)
	{
		Rectangle bound(0, 0, map.width, map.height);
		renderTileMap(map, bound);
	}

	void Renderer::renderEntityList(const EntityList & list, size_t from, size_t to)
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
		renderEntityList(list, from, to);
	}

	void Renderer::renderSingleTexture(const SingleTexture& texture, const Rectangle& target)
	{
		SDL_RenderCopy(gRenderer, texture.raw_texture, &(SDL_Rect)(texture.bounds), &(SDL_Rect)(target));
	}
}