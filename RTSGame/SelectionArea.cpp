#include "SelectionArea.h"



namespace GameEngine
{
	SelectionArea::SelectionArea(int x, int y) : Entity(x, y), 
		end_x(x), end_y(y), start_x(x), start_y(y)
	{
		renderSelf = true;
		square_16px = IMG_Load("Art/Selection_Rect.png");
	}

	SelectionArea::~SelectionArea()
	{
	}

	SDL_Surface* SelectionArea::getFrame(SDL_Renderer * renderer)
	{
		int dx = fmin(start_x, end_x);
		int dy = fmin(start_y, end_y);
		x(dx);
		y(dy);

		int dw = abs(end_x - start_x);
		int dh = abs(end_y - start_y);
		
		SDL_Surface* surface = SDL_CreateRGBSurface(0, dw, dh, 32, 0, 0, 0, 0);
		SDL_BlitScaled(square_16px, NULL, surface, NULL);

		return surface;
	}

	void SelectionArea::setSecondPoint(int _x, int _y)
	{
		end_x = _x;
		end_y = _y;
	}
	void SelectionArea::setSecondPoint(const Point & p )
	{
		setSecondPoint(p.x, p.y);
	}
	Point SelectionArea::getSecondPoint()
	{
		return Point(end_x, end_y);
	}
	Point SelectionArea::getFirstPoint()
	{
		return Point(start_x, start_y);
	}
}
