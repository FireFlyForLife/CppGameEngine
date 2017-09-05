#pragma once
#include <SDL.h>
#include "Animation.h"
#include "GenericRectangle.h"
#include "GenericPoint.h"

namespace GameEngine
{
	class TextureAtlas
	{
	public:
		explicit TextureAtlas(SDL_Texture* texture_map);
		~TextureAtlas();

		Animation* AddAnimation(IntRect first_frame_pos, int frames_amount, int frame_delay, IntPoint gap = {0, 0});
		int AddSingleTexture(string name, IntRect bounds);

	private:
		SDL_Texture* texture;
		int width, height;
	};
}
