#pragma once
#include <string>
#include <SDL_rect.h>

namespace GameEngine {
	struct Rectangle
	{
		int x;
		int y;
		int width;
		int height;

		Rectangle();
		Rectangle(int x, int y, int width, int height);
		Rectangle(const Rectangle& rect) = default;
		Rectangle(const SDL_Rect& rect);
		~Rectangle();

		Rectangle operator+(const Rectangle& rect);
		Rectangle operator-(const Rectangle& rect);
		Rectangle operator*(const Rectangle& rect);
		Rectangle operator/(const Rectangle& rect);
		//TODO: Add += -= etc operators
		bool operator==(const Rectangle& rect);
		bool operator==(const SDL_Rect& rect);

		std::string toStr() const;

		operator SDL_Rect() const;
	};
}
