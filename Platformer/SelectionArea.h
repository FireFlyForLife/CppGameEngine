#pragma once
#include "Entity.h"
#include "Point.h"
#include <SDL_image.h>
#include "World.h"
#include "BoxShape.h"

namespace GameEngine
{
	//Used from the RTSGame example game 
	class SelectionArea : public Entity
	{
	public:
		SelectionArea(int start_x, int start_y);
		virtual ~SelectionArea();

		virtual void Update() override;

		virtual SDL_Surface* getFrame(SDL_Renderer* renderer) override;
		
		void setSecondPoint(int x, int y);
		void setSecondPoint(const Point&);
		Point getSecondPoint();
		Point getFirstPoint();

		Rectangle getRectangle();

	protected:
		SDL_Surface * square_16px = NULL;
		int start_x, start_y;
		int end_x, end_y;
	};
}

