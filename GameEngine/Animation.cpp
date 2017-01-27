#include "Animation.h"



namespace GameEngine
{
	Animation::Animation()
	{
	}

	Animation::Animation(SDL_Texture* texture, const Point & frame_size, 
		int delay, Point* total_size) 
		: delay(delay)
	{
		bool deletePoint = false;
		if (total_size == nullptr) {
			int w, h;
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);
			total_size = new Point(w, h);
			deletePoint = true;
		}

		int width_frames = total_size->x / frame_size.x;
		int height_frames = total_size->y / frame_size.y;
		for (int y = 0; y < height_frames; y++) {
			for (int x = 0; x < width_frames; x += frame_size.x) {
				Rectangle rect{
					x * frame_size.x,
					y * frame_size.y,
					frame_size.x,
					frame_size.y
				};

				int id = Global::texture_manager.add(texture, rect);
				ids.push_back(id);
			}
		}

		if (deletePoint)
			delete total_size;
	}

	Animation::Animation(std::vector<int> ids, int delay) : ids(ids), delay(delay)
	{
	}

	Animation::Animation(int from, int to, int delay) : ids(to - from), delay(delay)
	{
		std::iota(std::begin(ids), std::end(ids), from);
	}


	Animation::~Animation()
	{
	}
	int Animation::frame(int index)
	{
		return ids.at(index);
	}
}
