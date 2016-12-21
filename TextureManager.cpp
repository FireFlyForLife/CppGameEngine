#include "TextureManager.h"


namespace GameEngine {
	TextureManager::TextureManager(SDL_Renderer* renderer) : renderer(renderer)
	{
		Uint32 rMask = 0x4B000000;
		Uint32 gMask = 0x00000000;
		Uint32 bMask = 0x00008200;
		Uint32 aMask = 0x000000FF;
		SDL_Surface* default_surface = SDL_CreateRGBSurface(0, 16, 16, 16,
			rMask, gMask, bMask, aMask);

		SDL_Rect inner{ 1, 1, 14, 14 };
		SDL_FillRect(default_surface, &inner, 0x9400D3FF);

		default_texture = SDL_CreateTextureFromSurface(renderer, default_surface);

		SDL_FreeSurface(default_surface);
	}

	TextureManager::~TextureManager()
	{
		for (int i = 0; i < raw_texture_array.size(); i++) {
			SDL_Texture* texture = raw_texture_array[i].get();
			SDL_DestroyTexture(texture);
		}

		SDL_DestroyTexture(default_texture);
	}

	SingleTexture* TextureManager::get(size_t id)
	{
		if (id > texture_array.size() || id < 0)
			return NULL;

		return &texture_array[id];//TODO: Make sure the decontructor deletes all structs
	}

	SDL_Texture * TextureManager::getDefault()
	{
		return default_texture;
	}
}