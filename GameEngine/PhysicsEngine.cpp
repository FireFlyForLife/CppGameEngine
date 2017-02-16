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

		EntityList& entity_list = *world_ptr->entity_list;

		for each (ent_ptr entity in entity_list)
		{
			Vector2& vel = entity->getVel();

			if (entity->physics_type == PHYSICS_TYPE::DYNAMIC) 
				vel = vel + gravity;

			float seconds = (float)Global::deltaTime() / 1000.f;
			Vector2 movement(vel * seconds);

			//TOOD: Make the renderer do this reversing instead of fucking with the whole physics coordinate system
			entity->x(entity->x() + vel.x);
			entity->y(entity->y() - vel.y);
		}

		for(ent_ptr& entity : entity_list)
		{
			if (entity->physics_type == PHYSICS_TYPE::DYNAMIC) {
				//TODO: Make some dank ass system which actually makes use of multiple colliders
				Shape* col_abstract = entity->getCollider();
				BoxShape* col = (BoxShape*)col_abstract;
				Point posA(entity->x(), entity->y());
				if (col != nullptr) {
					for (ent_ptr& target : *world_ptr->entity_list)
					{
						if (target->physics_type == PHYSICS_TYPE::NONE || entity == target)
							continue;

						Shape* col_t_abstract = target->getCollider();
						if (col_t_abstract != nullptr) {
							BoxShape* col_t = (BoxShape*)col_t_abstract;
							Point posB(target->x(), target->y());
							if (hasOverlap(posA, *col, posB, *col_t)) {
								correctOverlap(*entity, *target);
								//no bouncing implemented yet
								//entity->getVel() = Vector2(0, 0);
								Global::CollisionEvent.call(entity, target);
							}
						}
					}
				}
			}
		}
	}
}
