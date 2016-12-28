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
		//Get a list of pointers to texture_ids
		int tiles_amount = bounds.width * bounds.height;
		typedef std::pair<int, Point*> dwasd;
		std::vector<dwasd> ids(tiles_amount);
		for (int x = bounds.x; x < bounds.width + bounds.x; x++) {
			for (int y = bounds.y; y < bounds.height + bounds.y; y++) {
				Tile* tile = map.at(x, y);
				Point* location = new Point(x, y);
				ids.push_back(dwasd(tile->GetTexture(), location));
			}
		}

		//TODO: sort the list incrementaly

		for each (dwasd sorted_tile in ids)
		{
			//SingleTexture& texture = Universal::texture_manager.get(sorted_tile.first);
			Rectangle target;
			target.x = sorted_tile.second->x;
			target.y = sorted_tile.second->y;
			target.width = 16; //TODO: Do I need to save a 'scale' or something?
			target.height = 16;
			//renderSingleTexture(&texture, target);
		}
		
		//TODO: Clean up point pointers in ids
	}
	void Renderer::renderTileMap(const TileMap & map)
	{
		Rectangle bound(0, 0, map.width, map.height);
		renderTileMap(map, bound);
	}
	void Renderer::renderSingleTexture(SingleTexture * texture, const Rectangle& target)
	{
		SDL_RenderCopy(gRenderer, texture->raw_texture, &(SDL_Rect)(texture->bounds), &(SDL_Rect)(target));
	}
}