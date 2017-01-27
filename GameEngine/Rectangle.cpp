#include "Rectangle.h"

namespace GameEngine {
	Rectangle::Rectangle() :
		x(0), y(0), width(0), height(0)
	{
	}

	Rectangle::Rectangle(int x, int y, int width, int height) :
		x(x), y(y), width(width), height(height)
	{
	}

	Rectangle::Rectangle(const SDL_Rect & rect) : Rectangle(rect.x, rect.y, rect.w, rect.h)
	{
	}

	Rectangle::~Rectangle()
	{
	}
	Rectangle Rectangle::operator+(const Rectangle & rect)
	{
		return Rectangle(x + rect.x, y + rect.y, width + rect.width, height + rect.height);
	}
	Rectangle Rectangle::operator-(const Rectangle & rect)
	{
		return Rectangle(x - rect.x, y - rect.y, width - rect.width, height - rect.height);
	}
	Rectangle Rectangle::operator*(const Rectangle & rect)
	{
		return Rectangle(x * rect.x, y * rect.y, width * rect.width, height * rect.height);
	}
	Rectangle Rectangle::operator/(const Rectangle & rect)
	{
		return Rectangle(x / rect.x, y / rect.y, width / rect.width, height / rect.height);
	}
	bool Rectangle::operator==(const Rectangle & rect)
	{
		return x == rect.x && y == rect.y && width == rect.width && height == rect.height;
	}
	bool Rectangle::operator==(const SDL_Rect & rect)
	{
		return x == rect.x && y == rect.y && width == rect.w && height == rect.h;
	}
	std::string Rectangle::toStr() const
	{
		std::string txt("Rectangle[x:" + std::to_string(x) +
			" ,y:" + std::to_string(y) +
			" ,w:" + std::to_string(width) +
			" ,h:" + std::to_string(height));
		return txt;
	}
	Rectangle::operator SDL_Rect() const
	{
		SDL_Rect rect{ x, y, width, height };
		return rect;
	}
}