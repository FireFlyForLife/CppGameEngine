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
		SDL_FreeSurface(square_16px);
	}

	SDL_Surface* SelectionArea::getFrame(SDL_Renderer * renderer)
	{
		Rectangle rect = getRectangle();

		x(rect.x);
		y(rect.y);

		SDL_Surface* surface = SDL_CreateRGBSurface(0, rect.width, rect.height, 32, 0, 0, 0, 0);
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
	Rectangle SelectionArea::getRectangle()
	{
		int pos_x = fmin(start_x, end_x);
		int pos_y = fmin(start_y, end_y);
		int w = abs(end_x - start_x);
		int h = abs(end_y - start_y);

		return Rectangle(pos_x, pos_y, w, h);
	}
}
