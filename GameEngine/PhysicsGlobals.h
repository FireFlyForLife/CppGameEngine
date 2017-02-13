#pragma once
#include "EventSource.h"
#include <memory>
#include "Entity.h"

using std::shared_ptr;

namespace GameEngine {
	namespace Global { //TODO: Maybe other namespace?
		extern EventSource<shared_ptr<Entity>&, shared_ptr<Entity>&> CollisionEvent;
	}
}