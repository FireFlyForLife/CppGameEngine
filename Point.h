#pragma once
#include <SDL.h>
#include <string>
namespace GameEngine {
	struct Point
	{
		int x;
		int y;

		Point();
		Point(int x, int y);
		Point(const Point&) = default;
		Point(const SDL_Point& point);
		~Point();

		Point operator+(const Point& point) const {
			return Point(x + point.x, y + point.y);
		}

		Point operator-(const Point& point) const {
			return Point(x - point.x, y - point.y);
		}

		Point operator*(const Point& point) const {
			return Point(x * point.x, y * point.y);
		}

		bool operator==(const Point& point) const {
			return x == point.x && y == point.y;
		}

		bool operator==(const SDL_Point& point) const{
			return x == point.x && y == point.y;
		}

		bool operator!=(const Point& point) const {
			return x != point.x || y != point.y;
		}

		bool operator!=(const SDL_Point& point) const {
			return x != point.x || y != point.y;
		}
		//TODO: Add += -= etc operators

		///watch out for DividedByZeroException
		Point operator/(const Point& point) const{
			return Point(x / point.x, y / point.y);
		}

		std::string toStr() const;

		operator SDL_Point() const;
	};
}
