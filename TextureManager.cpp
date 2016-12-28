#include "TextureManager.h"


namespace GameEngine {
	TextureManager::TextureManager()
	{
		SingleTexture* texture = new SingleTexture();
		texture->bounds = { 0, 0, 16, 16 };
		texture->raw_texture = NULL;
		default_texture = texture;
	}
	TextureManager::TextureManager(SDL_Renderer* renderer) : renderer(renderer)
	{
		setupDefault(renderer);
		SingleTexture* texture = new SingleTexture();
		texture->bounds = { 0, 0, 16, 16 };
		texture->raw_texture = NULL;
		default_texture = texture;
	}

	TextureManager::~TextureManager()
	{
		std::list<SDL_Texture*>::const_iterator iterator;
		for (iterator = raw_texture_list.begin(); iterator != raw_texture_list.end(); ++iterator) {
			SDL_Texture* texture = *iterator;
			SDL_DestroyTexture(texture);
		}

		for each (SingleTexture* single_texture in texture_array)
		{
			delete single_texture;
		}

		SDL_DestroyTexture(default_texture->raw_texture);
		delete default_texture;
	}

	SingleTexture& TextureManager::get(size_t id)
	{
		if (id > index || id < 0) {
			return *default_texture;
		}

		return *texture_array[id];//TODO: Make sure the decontructor deletes all structs
	}

	SingleTexture& TextureManager::get(string name)
	{
		std::unordered_map<string, size_t>::iterator iterator = id_dictionairy.find(name);
		if (iterator != id_dictionairy.end()) {
			size_t id = iterator->second;
			
			return get(id);
		}

		return *default_texture;
	}

	size_t TextureManager::add(SDL_Texture* texture, string name)
	{
		auto raw_texture = get_raw_texture(texture);
		if (!raw_texture) {
			raw_texture = texture;
			raw_texture_list.push_back(raw_texture);
		}
		//TODO: Finish adding SingleTexture

		//TODO: Increment index

		return 0;
	}

	void TextureManager::setupDefault(SDL_Renderer * renderer)
	{
		//TODO: Should I save this SDL_Renderer?

		Uint32 rMask, gMask, bMask, aMask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rMask = 0xff000000;
		gMask = 0x00ff0000;
		bMask = 0x0000ff00;
		aMask = 0x000000ff;
#else
		rMask = 0x000000ff;
		gMask = 0x0000ff00;
		bMask = 0x00ff0000;
		aMask = 0xff000000;
#endif

		SDL_Surface* default_surface = SDL_CreateRGBSurface(0, 16, 16, 32,
			rMask, gMask, bMask, aMask);

		SDL_Rect bg{ 0, 0, 16, 16 };
		SDL_FillRect(default_surface, &bg, SDL_MapRGBA(default_surface->format, 75, 0, 130, 255));

		SDL_Rect inner{ 1, 1, 14, 14 };
		SDL_FillRect(default_surface, &inner, SDL_MapRGBA(default_surface->format, 75, 0, 130, 200));

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, default_surface);
		default_texture = new SingleTexture();
		default_texture->raw_texture = texture;
		default_texture->bounds = { 0,0,16,16 };

		SDL_FreeSurface(default_surface);
	}

	void TextureManager::setupDefault(SingleTexture * newTexture)
	{
		default_texture = newTexture;
	}

	SingleTexture& TextureManager::getDefault()
	{
		return *default_texture;
	}

	SDL_Texture* TextureManager::get_raw_texture(SDL_Texture * texture)
	{
		for each (SDL_Texture* texture_raw in raw_texture_list)
		{
			if (texture_raw == texture) {
				return texture_raw;
			}
		}
		return nullptr;
	}
	SingleTexture* TextureManager::get_SingleTexture(SDL_Texture* texture_ptr, SDL_Rect& bounds)
	{
		for each (SingleTexture* single_texture in texture_array)
		{
			if (single_texture->raw_texture == texture_ptr && single_texture->bounds == bounds) {
				return single_texture;
			}
		}
		return nullptr;
	}
}