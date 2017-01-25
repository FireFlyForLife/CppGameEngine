#include "SelectionArea.h"



namespace GameEngine
{
	SelectionArea::SelectionArea(int x, int y) : end_x(x), end_y(y),
		Entity(x, y)
	{
		renderSelf = true;
		square_16px = IMG_Load("Art/Selection_Rect.png");
	}

	SelectionArea::~SelectionArea()
	{
	}

	SDL_Surface* SelectionArea::getFrame(SDL_Renderer * renderer)
	{
		int width = 16;
		int height = 16;
		int scale_x = width / (x() - end_x);
		int scale_y = height / (y() - end_y);
		
		SDL_Surface* surface = SDL_CreateRGBSurface(0, x() - end_x, y() - end_y, 32, 0, 0, 0, 0);
		SDL_BlitScaled(square_16px, NULL, surface, NULL);

		return surface;
	}



	void SelectionArea::setSecondPoint(int x, int y)
	{
	}
}
