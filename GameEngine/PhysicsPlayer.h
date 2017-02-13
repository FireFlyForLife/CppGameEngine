#pragma once
#include "Entity.h"
#include "Physics.h"
#include "Input.h"

namespace GameEngine
{
	class PhysicsPlayer : public Entity
	{
	public:
		const float speed = 1.f;

		PhysicsPlayer(float x, float y, string texture);
		PhysicsPlayer(float x, float y, int texture_id);
		virtual ~PhysicsPlayer();

	private:
		void OnButtonDown(KeyClickArgs* args, int);
		void OnButtonUp(KeyClickArgs* args, int);

		void OnCollision(ent_ptr& a, ent_ptr& b);
	};

}
