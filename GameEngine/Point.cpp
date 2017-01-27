#include "Point.h"


namespace GameEngine {
	Point::Point() : x(0), y(0)
	{
	}

	Point::Point(int x, int y) : x(x), y(y)
	{
	}

	Point::Point(float x, float y) : x((int)x), y((int)y)
	{
	}

	Point::Point(const SDL_Point & point) : Point(point.x, point.y)
	{
	}

	Point::~Point()
	{
	}

	std::string Point::toStr() const
	{
		std::string txt("Point[x:" + std::to_string(x) + ", y:" + std::to_string(y) + "]");
		return txt;
	}

	Point::operator SDL_Point() const
	{
		SDL_Point p{ this->x, this->y };
		return p;
	}
}



