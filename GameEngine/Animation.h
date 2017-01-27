#pragma once
#include <vector>
#include <numeric>
#include "Point.h"
#include "Rectangle.h"
#include "Globals.h"
#include <SDL_image.h>

namespace GameEngine
{
	struct Animation
	{
		Animation();
		Animation(SDL_Texture* texture, const Point & frame_size,
			int delay, Point* size = nullptr);
		Animation(std::vector<int> ids, int delay);
		Animation(int from, int to, int delay);
		~Animation();

		int frame(int index);

		std::vector<int> ids;
		int delay = 100;
	};
}

