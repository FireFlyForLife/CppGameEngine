#pragma once
#include <SDL.h>
#include <string>

struct Point
{
	int x;
	int y;

	Point();
	Point(int x, int y);
	Point(const Point&) = default;
	Point(const SDL_Point& point);
	~Point();

	Point operator+(const Point& point) {
		return Point(x + point.x, y + point.y);
	}

	Point operator-(const Point& point) {
		return Point(x - point.x, y - point.y);
	}

	Point operator*(const Point& point) {
		return Point(x * point.x, y * point.y);
	}

	///watch out for DividedByZeroException
	Point operator/(const Point& point) {
		return Point(x / point.x, y / point.y);
	}

	std::string toString() const;

	operator SDL_Point() const;

	operator std::string() const;
};

