#pragma once
#include <SDL.h>
#include <string>
namespace GameEngine {
	struct Point
	{
		float x;
		float y;

		Point();
		Point(int x, int y);
		Point(float x, float y);
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

		static const Point zero;
	};
}
