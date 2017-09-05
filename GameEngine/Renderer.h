#pragma once
#include <SDL.h>
#include <array>
#include "TileMap.h"
#include "Rectangle.h"
#include "TextureManager.h"
#include "Globals.h"
#include "EntityList.h"
#include "World.h"
#include <math.h>
#include <tuple>

namespace GameEngine {
	class Renderer
	{
	public:
		Renderer(SDL_Renderer*);
		virtual ~Renderer();
		//TODO: Add a camera with zoom.
		virtual void renderWorld(const World&);
		virtual void renderTileMap(const TileMap&, const Rectangle& bounds, const Point& offset);
		virtual void renderTileMap(const TileMap&);
		virtual void renderEntityList(const EntityList&, const Point& offset, size_t from, size_t to);
		virtual void renderEntityList(const EntityList&);

		void renderSurface(SDL_Surface*, SDL_Rect* target, SDL_Rect* bounds = NULL);
		void renderTexture(SDL_Texture*, SDL_Rect* target, SDL_Rect* bounds = NULL);
		void renderSingleTexture(const SingleTexture&, const Rectangle& target);

	protected:
		SDL_Renderer* gRenderer = NULL;
	};
}