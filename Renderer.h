#pragma once
#include <SDL.h>
#include <array>
#include "TileMap.h"

namespace GameEngine {
	class Renderer
	{
	public:
		Renderer(SDL_Renderer*);
		~Renderer();

		void renderTileMap(TileMap&);

	protected:
		SDL_Renderer* gRenderer = NULL;
	};
}