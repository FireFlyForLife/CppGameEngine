#pragma once
#include "Building.h"
#include "Enemy.h"

namespace GameEngine
{
	class Tower : public Building
	{
	public:
		Tower(float x, float y, int texture = -1);
		Tower(float x, float y, string texture);
		virtual ~Tower();

		virtual void Update() override;

		bool enemyInRange(Enemy* enemy);

	protected:
		float attack_range = 60;
		float attack_delay = 2000;
		float attack_damage = 40;
		Uint32 lastHit = SDL_GetTicks();
		Enemy* target = nullptr;

		void lookForEnemies();
		void attackTarget();
	};
}