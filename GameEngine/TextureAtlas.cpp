#include "TextureAtlas.h"

namespace GameEngine
{
	TextureAtlas::TextureAtlas(SDL_Texture* texture_map)
		: texture(texture_map)
	{
		SDL_QueryTexture(texture_map, NULL, NULL, &width, &height);
	}

	TextureAtlas::~TextureAtlas()
	{
	}

	Animation* TextureAtlas::AddAnimation(IntRect first_frame, int frames, int delay, IntPoint gap)
	{
//		if ((width - first_frame.x) % first_frame.width != 0)
//			throw new std::exception(("Error adding animation: '" + name + "', the grid is not alligned").c_str());

		std::vector<int> ids{ frames };

		IntRect frame_pos = first_frame;
		for (int i = 0; i < frames; ++i)
		{
			int id = Global::texture_manager.add(texture, Rectangle(frame_pos));
			ids.push_back(id);

			if (frame_pos.x + gap.x + frame_pos.width * 2 < width)
			{
				frame_pos.x += frame_pos.width + gap.x;
			}
			else
			{
				frame_pos.y += frame_pos.height + gap.y;
				frame_pos.x = 0;
			}
		}

		return new Animation( ids, delay);
	}

	int TextureAtlas::AddSingleTexture(string name, IntRect bounds)
	{
		return Global::texture_manager.add(texture, name, static_cast<Rectangle>( bounds ));
	}
}
