#pragma once
#include <SDL.h>
#include <array>
#include "TileMap.h"
#include "Rectangle.h"
#include "TextureManager.h"
#include "Globals.h"

namespace GameEngine {
	class Renderer
	{
	public:
		Renderer(SDL_Renderer*);
		~Renderer();
		//TODO: Add a camera with zoom.
		void renderTileMap(const TileMap&, const Rectangle& bounds);
		void renderTileMap(const TileMap&);

		void renderSingleTexture(SingleTexture*, const Rectangle& target);

	protected:
		SDL_Renderer* gRenderer = NULL;
	};
}