#pragma once
#include "World.h"
#include "Vector2.h"

namespace GameEngine
{
	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		PhysicsEngine(World* world_ptr);
		~PhysicsEngine();

		void update();

		Vector2 gravity{ -9.81, 0 };

	protected:
		World* world_ptr = nullptr;
	};

}
