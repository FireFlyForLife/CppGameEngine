#include "Renderer.h"


namespace GameEngine {
	Renderer::Renderer(SDL_Renderer* renderer) : gRenderer(renderer)
	{

	}


	Renderer::~Renderer()
	{
	}

	void Renderer::renderTileMap(TileMap& map)
	{
		for (size_t i = 0; i < map.width; i++) {
			std::array<int, map.width> gello;
		}
	}
}