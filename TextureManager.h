#pragma once
#include <SDL.h>
#include <array>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include "Rectangle.h"

using std::string;

namespace GameEngine {
	struct SingleTexture {
		SDL_Texture* raw_texture;
		Rectangle bounds;
	};

	class TextureManager
	{
	public:
		static const size_t maxTextures = 2 ^ 5;

		TextureManager(SDL_Renderer*);
		~TextureManager();

		SingleTexture& get(size_t);
		SingleTexture& get(string);
		size_t add(SDL_Texture*, string);

		SingleTexture& getDefault();

	protected:
		SDL_Renderer* renderer = NULL;

		SDL_Texture* get_raw_texture(SDL_Texture*);//overload with SingleTexture objects
		SingleTexture* get_SingleTexture(SDL_Texture*, SDL_Rect&);//overload with SingleTexture object

		std::list<SDL_Texture*> raw_texture_list;
		std::array<SingleTexture*, maxTextures> texture_array;
		size_t index = 0;
		std::unordered_map<string, size_t> id_dictionairy;

	private:
		SingleTexture* default_texture = NULL;
	};
}