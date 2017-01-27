#pragma once
#include "BoxShape.h"
#include "Input.h"
#include "Point.h"
#include <vector>
#include "Vector2.h"
#include "SDL.h"
#include "World.h"
#include "Enemy.h"
#include "Actor.h"

namespace GameEngine
{
	enum UNIT_STATE {
		IDLE,
		MOVING,
		ATTACKING,
	};

	//TODO: Use this
	class UnitTarget : public Entity
	{
	public:
		UnitTarget(float x, float y);
	};

	class Unit : public Actor
	{
	public:
		Unit(float x, float y, std::string texture);
		Unit(float x, float y, int id);
		virtual ~Unit();

		virtual void Update() override;

		bool enemyInRange(Enemy* enemy);

		UNIT_STATE state = UNIT_STATE::IDLE;
		std::vector<Point> path;
		Enemy* target = nullptr;
		
		
	protected:
		float sight_range = 40;
		float attack_range = 30;
		float speed = 0.1;
		float attack_delay = 2000;
		float attack_damage = 50;

		Uint32 lastHit = SDL_GetTicks();

		void moveAlongPath();
		void lookForEnemies();
		void attackTarget();
	};
}

