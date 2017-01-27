#pragma once
#include "Point.h"
#include <math.h>

namespace GameEngine {
	struct Vector2 {
		Vector2();
		Vector2(float x, float y);
		Vector2(const Point& point);

		float magnitude2() const;
		float magnitude() const;
		Vector2 normalized() const;

		Vector2 operator/(const Vector2& other) const;
		Vector2 operator*(const Vector2& other) const ;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator/(const float& other) const;
		Vector2 operator*(const float& other) const ;
		Vector2 operator+(const float& other) const;
		Vector2 operator-(const float& other) const;
		
		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;
		//TODO: Make all the += operators

		float x, y;
	};

	Vector2& v2_min(Vector2&, Vector2&);
	float distanceBetween(const Vector2& a, const Vector2& b);
}