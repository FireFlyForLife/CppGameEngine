#pragma once
#include <string>
#include <SDL_rect.h>
#include "Rectangle.h"

namespace GameEngine {
	template<typename T>
	struct GenericRectangle
	{
		T x;
		T y;
		T width;
		T height;

		GenericRectangle() 
			: x(0), y(0), width(0), height(0)
		{
		}

		GenericRectangle(T x, T y, T width, T height)
			: x(x), y(y), width(width), height(height)
		{
		}
		
		GenericRectangle(const GenericRectangle<T>& rect) = default;

		GenericRectangle(const SDL_Rect& r)
			: x(r.x), y(r.y), width(r.w), height(r.h)
		{
		}

		~GenericRectangle()
		{
		}

		GenericRectangle<T> operator+(const GenericRectangle<T>& rect) const {
			return GenericRectangle<T>(x + rect.x, y + rect.y, width + rect.width, height + rect.height);
		}
		GenericRectangle<T> operator-(const GenericRectangle<T>& rect) const {
			return GenericRectangle<T>(x - rect.x, y - rect.y, width - rect.width, height - rect.height);
		}
		GenericRectangle<T> operator*(const GenericRectangle<T>& rect) const {
			return GenericRectangle<T>(x * rect.x, y * rect.y, width * rect.width, height * rect.height);
		}
		GenericRectangle<T> operator/(const GenericRectangle<T>& rect) const {
			return GenericRectangle<T>(x / rect.x, y / rect.y, width / rect.width, height / rect.height);
		}
		//TODO: Add += -= etc operators
		bool operator==(const GenericRectangle<T>& rect) const {
			return x == rect.x && y == rect.y && width == rect.width && height == rect.height;
		}
		bool operator==(const SDL_Rect& rect) const {
			return x == rect.x && y == rect.y && width == rect.width && height == rect.height;
		}

		std::string toStr() const {
			std::string txt("Rectangle[x:" + std::to_string(x) +
				" ,y:" + std::to_string(y) +
				" ,w:" + std::to_string(width) +
				" ,h:" + std::to_string(height));
			return txt;
		}

		operator SDL_Rect() const {
			SDL_Rect rect{ x, y, width, height };
			return rect;
		}
	};
}