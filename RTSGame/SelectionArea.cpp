#include "SelectionArea.h"



namespace GameEngine
{
	SelectionArea::SelectionArea(int x, int y) : end_x(x), end_y(y),
		Entity(x, y, Global::texture_manager.getID("selection_rectangle"))
	{
		renderSelf = true;
	}

	SelectionArea::~SelectionArea()
	{
	}

	std::pair<SingleTexture*, Rectangle*> SelectionArea::getFrame(SDL_Renderer * renderer)
	{
		int width = 16;
		int height = 16;
		int scale_x = width / (x() - end_x);
		int scale_y = height / (y() - end_y);
		SingleTexture* texture = &Global::texture_manager.get(getTexture());
		return std::pair<SingleTexture*, Rectangle*>(texture, new Rectangle(x(), y(), scale_x, scale_y));//TODO: Fix this memory leak
	}



	void SelectionArea::setSecondPoint(int x, int y)
	{
	}
}
