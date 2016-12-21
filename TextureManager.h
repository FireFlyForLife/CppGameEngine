#pragma once
#include <SDL.h>
#include <array>
#include <memory>
#include <string>
#include <unordered_map>

using std::string;

namespace GameEngine {
	struct SingleTexture {
		typedef SDL_Rect Rectangle; //TODO: Make Rectangle class
		std::shared_ptr<SDL_Texture> raw_texture;
		Rectangle bounds;
	};

	class TextureManager
	{
	public:
		static const size_t maxTextures = 2 ^ 5;
		typedef std::shared_ptr<SDL_Texture> texture_ptr;

		TextureManager(SDL_Renderer*);
		~TextureManager();

		SingleTexture* get(size_t);
		int add(SDL_Texture*, string name);

		SDL_Texture* getDefault();

	protected:
		SDL_Renderer* renderer = NULL;

		std::array<texture_ptr, maxTextures> raw_texture_array;
		std::array<SingleTexture, maxTextures> texture_array;
		std::unordered_map<string, size_t> id_dictionairy;

	private:
		SDL_Texture* default_texture = NULL;
	};
}