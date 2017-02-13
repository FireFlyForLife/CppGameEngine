#include "PhysicsGlobals.h"

namespace GameEngine {
	namespace Global {
		EventSource<shared_ptr<Entity>&, shared_ptr<Entity>&> CollisionEvent;
	}
}