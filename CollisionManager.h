#pragma once
#include "BoxShape.h"
#ifdef _DEBUG
#include <assert.h>
#endif // DEBUG

namespace GameEngine {
	template<typename E, typename T>
	bool hasOverlap(E* a, T* b);

	template<typename E, typename T>
	inline bool hasOverlap(E* a, T* b) {
		assert(false, "wasd");
		return false;
	}


	template<>
	inline bool hasOverlap<BoxShape, BoxShape>(BoxShape* first, BoxShape* second)
	{
		BoxShape a(*first);
		BoxShape b(*second);

		return (a.x < b.x + b.width &&
			a.x + a.width > b.x &&
			a.y < b.y + b.height &&
			a.height + a.y > b.y);
	}
}