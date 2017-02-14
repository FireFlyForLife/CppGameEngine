#include "PhysicsPlayer.h"



namespace GameEngine
{
	PhysicsPlayer::PhysicsPlayer(float x, float y, string texture)
		: Entity(x, y, texture)
	{
		keyDownListeners.add([this](KeyClickArgs * args, int unused) {OnButtonDown(args, unused); });
		keyUpListeners.add([this](KeyClickArgs * args, int unused) {OnButtonUp(args, unused); });
		Global::CollisionEvent.add([this](ent_ptr & a, ent_ptr & b) {OnCollision(a, b); });
		collider = new BoxShape(0, 0, 16, 16);

		physics_type = PHYSICS_TYPE::DYNAMIC;
	}

	PhysicsPlayer::PhysicsPlayer(float x, float y, int texture_id)
		: Entity(x, y, texture_id)
	{
		keyDownListeners.add([this](KeyClickArgs * args, int unused) {OnButtonDown(args, unused); });
		keyUpListeners.add([this](KeyClickArgs * args, int unused) {OnButtonUp(args, unused); });
		Global::CollisionEvent.add([this](ent_ptr & a, ent_ptr & b) {OnCollision(a, b); });
		collider = new BoxShape(0, 0, 16, 16);

		physics_type = PHYSICS_TYPE::DYNAMIC;
	}

	PhysicsPlayer::~PhysicsPlayer()
	{
	}

	void PhysicsPlayer::Update()
	{
		std::cout << Global::deltaTime() << std::endl;
	}

	void PhysicsPlayer::OnButtonDown(KeyClickArgs * args, int)
	{
		switch (args->scan_code)
		{
		case SDL_SCANCODE_A:
			vel.x = -speed;
			break;
		case SDL_SCANCODE_D:
			vel.x = speed;
			break;
		case SDL_SCANCODE_W:
			if (on_ground) {
				vel.y = jumpForce;
				on_ground = false;
			}
			break;
		case SDL_SCANCODE_S:
			vel.y += -speed / 2;
			break;
		}

		vel.x = fmin(vel.x, maxSpeed);
		vel.y = fmin(vel.y, maxSpeed);
	}

	void PhysicsPlayer::OnButtonUp(KeyClickArgs * args, int)
	{
		short scan = args->scan_code;
		if (scan == SDL_SCANCODE_A || scan == SDL_SCANCODE_D) {
			vel.x = 0;
		}
		/*else if (scan == SDL_SCANCODE_W || scan == SDL_SCANCODE_S) {
			vel.y = 0;
		}*/
	}
	void PhysicsPlayer::OnCollision(ent_ptr & a, ent_ptr & b)
	{
		if(a.get() == this && b->y() > a->y())
			on_ground = true;
	}
}
