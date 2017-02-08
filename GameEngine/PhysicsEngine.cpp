#include "PhysicsEngine.h"



namespace GameEngine
{
	PhysicsEngine::PhysicsEngine()
	{
	}

	PhysicsEngine::PhysicsEngine(World * world_ptr)
		: world_ptr(world_ptr)
	{
	}


	PhysicsEngine::~PhysicsEngine()
	{
	}
	void PhysicsEngine::update()
	{
		if (world_ptr == nullptr)
			return;

		World& world = *world_ptr;
		for(ent_ptr entity : (world.entity_list))
		{

		}
	}
}
