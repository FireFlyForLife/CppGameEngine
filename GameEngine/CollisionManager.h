#pragma once
#include "BoxShape.h"
#include "Entity.h"
#ifdef _DEBUG
#include <assert.h>
#else
#define assert()
#endif // DEBUG

namespace GameEngine {
	template<typename E, typename T>
	inline bool hasOverlap(const Point& posA, const E& a, const Point& posB, const T& b) {
		assert(false && "Only specialisations are allowed");
		return false;
	}

	//TODO: account for non-AABB Boxes
	template<>
	inline bool hasOverlap(const Point& posA, const BoxShape& a, const Point& posB, const BoxShape& b)
	{
		return (a.x + posA.x < b.x + posB.x + b.width &&
			a.x + posA.x + a.width > b.x + posB.x &&
			a.y + posA.y < b.y + posB.y + b.height &&
			a.height + a.y + posA.y > b.y + posB.y);
	}

	template<typename E, typename T>
	inline void correctOverlap(E& a, T&) {
		assert(false && "Only specialisations are allowed");
		//return false;
	}

	// adapted from: https://www.gamedev.net/resources/_/technical/game-programming/swept-aabb-collision-detection-and-response-r3084
	template<>
	inline void correctOverlap(Entity& a, Entity& b) {
		float moveX = 0;
		float moveY = 0;

		//TODO: don't assume we only have a BoxShape
		BoxShape* colA = dynamic_cast<BoxShape*>(a.getCollider());
		BoxShape* colB = dynamic_cast<BoxShape*>(b.getCollider());
		if (colA == nullptr || colB == nullptr)
			return;

		float l = b.x() - (a.x() + colA->width);
		float r = (b.x() + colB->width) - a.x();
		float t = b.y() - (a.y() + colA->height);
		float u = (b.y() + colB->height) - a.y(); //under

		// check that there was a collision
		if (l > 0 || r < 0 || t > 0 || u < 0)
			return;

		// find the offset of both sides
		moveX = abs(l) < r ? l : r;
		moveY = abs(t) < u ? t : u;

		// only use whichever offset is the smallest
		if (abs(moveX) < abs(moveY)) {
			moveY = 0.0f;
			a.getVel().x = 0.f;
		}
		else {
			moveX = 0.0f;
			a.getVel().y = 0.f;
		}

		a.x(a.x() + moveX);
		a.y(a.y() + moveY);
	}
}