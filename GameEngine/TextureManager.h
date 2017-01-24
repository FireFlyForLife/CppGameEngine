#pragma once
#include <SDL.h>
#include <array>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <iostream>
#include <math.h>
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
		static const size_t maxTextures = 2048;

		TextureManager();
		TextureManager(SDL_Renderer*);
		~TextureManager();

		SingleTexture& get(int);
		SingleTexture& get(string);
		int add(SDL_Texture*, const string&);
		int add(SDL_Texture*, const string&, const Rectangle& bounds);
		int getID(string);
		void registerID(string, int);

		void setupDefault(SDL_Renderer*);
		void setupDefault(SingleTexture*);
		SingleTexture& getDefault();

	protected:
		SDL_Texture* get_raw_texture(SDL_Texture*);//overload with SingleTexture objects
		SingleTexture* get_SingleTexture(SDL_Texture*, const Rectangle&);//overload with SingleTexture object
		int get_SingleTexture_ID(SDL_Texture*, const Rectangle&);

		std::list<SDL_Texture*> raw_texture_list;
		std::array<SingleTexture*, maxTextures> texture_array;
		int index = 0;
		std::unordered_map<string, int> id_dictionairy;

	private:
		SingleTexture* default_texture = NULL;
	};
}