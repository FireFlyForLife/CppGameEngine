#include "Vector2.h"

namespace GameEngine {
	Vector2::Vector2() : x(0), y(0)
	{
	}
	Vector2::Vector2(float x, float y) : x(x), y(y)
	{
	}
	Vector2::Vector2(const Point & p) : x(p.x), y(p.y)
	{
	}

	float Vector2::magnitude2() const
	{
		return pow(x,2) + pow(y, 2);
	}

	float Vector2::magnitude() const
	{
		return sqrt(magnitude2());
	}

	Vector2 Vector2::normalized() const
	{
		return *this / magnitude();
	}

	Vector2 Vector2::operator/(const Vector2 & other) const
	{
		return Vector2(x / other.x, y / other.y);
	}
	Vector2 Vector2::operator*(const Vector2 & other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 Vector2::operator+(const Vector2 & other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Vector2::operator-(const Vector2 & other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2 Vector2::operator/(const float & other) const
	{
		return Vector2(x / other, y / other);
	}
	Vector2 Vector2::operator*(const float & other) const
	{
		return Vector2(x * other, y * other);
	}
	Vector2 Vector2::operator+(const float & other) const
	{
		return Vector2(x + other, y + other);
	}
	Vector2 Vector2::operator-(const float & other) const
	{
		return Vector2(x - other, y - other);
	}

	bool Vector2::operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	bool Vector2::operator!=(const Vector2& other) const {
		return x != other.x || y != other.y;
	}

	Vector2 & v2_min(Vector2 & a, Vector2 & b)
	{
		if (a.magnitude2() > b.magnitude2())
			return b;
		return a;
	}

	float distanceBetween(const Vector2 & a, const Vector2 & b)
	{
		return (a - b).magnitude();
	}

	

}

