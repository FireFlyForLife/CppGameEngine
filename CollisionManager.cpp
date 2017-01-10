#include "CollisionManager.h"

namespace GameEngine {
	/*template<typename E, typename T>
	bool hasOverlap(E a, T b)
	{
		assert(false, "You should use the specialised templates!");
	}*/
	//TODO: Account for non AABB's
	/*template<>
	bool hasOverlap(BoxShape* first, BoxShape* second)
	{
		BoxShape a(*first);
		BoxShape b(*second);

		return (a.x < b.x + b.width &&
			a.x + a.width > b.x &&
			a.y < b.y + b.height &&
			a.height + a.y > b.y);
	}*/
}