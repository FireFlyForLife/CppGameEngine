#pragma once
#include "Entity.h"
#include "Point.h"
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
		void setSecondPoint(const Point&);
		Point getSecondPoint();
		Point getFirstPoint();

	protected:
		SDL_Surface * square_16px = NULL;
		int start_x, start_y;
		int end_x, end_y;
	};
}

