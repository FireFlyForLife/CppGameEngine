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
		const float speed = 1.f;
		const float jumpForce = 4.f;
		const float maxSpeed = 5.f;

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
