#pragma once
#include "World.h"
#include "Vector2.h"
#include "PhysicsGlobals.h"

namespace GameEngine
{
	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		PhysicsEngine(World* world_ptr);
		~PhysicsEngine();

		void update();

		Vector2 gravity{ 0.f, -9.81f };

	protected:
		World* world_ptr = nullptr;
	};

}
