#pragma once
#include "Entity.h"
#include <SDL_image.h>

namespace GameEngine
{
	class SelectionArea : public Entity
	{
	public:
		SelectionArea(int start_x, int start_y);
		virtual ~SelectionArea();

		virtual SDL_Surface* getFrame(SDL_Renderer* renderer) override;
		
		void setSecondPoint(int x, int y);

	protected:
		SDL_Surface * square_16px = NULL;
		int end_x, end_y;
	};
}

