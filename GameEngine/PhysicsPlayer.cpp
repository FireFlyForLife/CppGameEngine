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
			vel.y = speed;
			break;
		case SDL_SCANCODE_S:
			vel.y = -speed;
			break;
		}
	}

	void PhysicsPlayer::OnButtonUp(KeyClickArgs * args, int)
	{
		short scan = args->scan_code;
		if (scan == SDL_SCANCODE_A || scan == SDL_SCANCODE_D) {
			vel.x = 0;
		}
		else if (scan == SDL_SCANCODE_W || scan == SDL_SCANCODE_S) {
			vel.y = 0;
		}
	}
	void PhysicsPlayer::OnCollision(ent_ptr & a, ent_ptr & b)
	{
		std::cout << "COLLLL" << std::endl;
	}
}
