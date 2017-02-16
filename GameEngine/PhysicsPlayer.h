#pragma once
#include "Entity.h"
#include "Physics.h"
#include "Input.h"
#include <math.h>
#include "Globals.h"

namespace GameEngine
{
	class PhysicsPlayer : public Entity
	{
	public:
		const float speed = 2.f;
		const float jumpForce = 3.f;
		const float maxSpeed = 10.f;

		PhysicsPlayer(float x, float y, string texture);
		PhysicsPlayer(float x, float y, int texture_id);
		virtual ~PhysicsPlayer();

		virtual void Update() override;

	protected:
		bool on_ground = false;

	private:
		void OnButtonDown(KeyClickArgs* args, int);
		void OnButtonUp(KeyClickArgs* args, int);

		void OnCollision(ent_ptr& a, ent_ptr& b);
	};

}
