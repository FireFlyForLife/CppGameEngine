#pragma once
#include <SDL.h>
#include <string>
#include "Point.h"

namespace GameEngine {

	//From: http://stackoverflow.com/questions/14294267/class-template-for-numeric-types
	template<
		typename T, //real type
		typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	>
	struct GenericPoint
	{
		T x;
		T y;

		GenericPoint() : x(0), y(0){}
		GenericPoint(T x, T y) : x(x), y(y){}
		GenericPoint(const GenericPoint&) = default;
		GenericPoint(const SDL_Point& p) : GenericPoint(p.x, p.y) {}
		GenericPoint(const Point& p) : GenericPoint(p.x, p.y){}
		~GenericPoint(){}

		GenericPoint operator+(const GenericPoint& point) const {
			return Point(x + point.x, y + point.y);
		}

		GenericPoint operator-(const GenericPoint& point) const {
			return Point(x - point.x, y - point.y);
		}

		GenericPoint operator*(const GenericPoint& point) const {
			return Point(x * point.x, y * point.y);
		}

		bool operator==(const GenericPoint& point) const {
			return x == point.x && y == point.y;
		}

		bool operator==(const SDL_Point& point) const {
			return x == point.x && y == point.y;
		}

		bool operator!=(const GenericPoint& point) const {
			return x != point.x || y != point.y;
		}

		bool operator!=(const SDL_Point& point) const {
			return x != point.x || y != point.y;
		}
		//TODO: Add += -= etc operators

		///watch out for DividedByZeroException
		GenericPoint operator/(const GenericPoint& point) const {
			return Point(x / point.x, y / point.y);
		}

		std::string toStr() const {
			std::string txt("Point[x:" + std::to_string(x) + ", y:" + std::to_string(y) + "]");
			return txt;
		}

		operator SDL_Point() const {
			SDL_Point p{ this->x, this->y };
			return p;
		}

		operator Point() const
		{
			Point p{ x, y };
			return p;
		}

		static const GenericPoint zero{0, 0};
	};

	using IntPoint = GenericPoint<int>;
	using FloatPoint = GenericPoint<float>;
	using DoublePoint = GenericPoint<double>;
}
