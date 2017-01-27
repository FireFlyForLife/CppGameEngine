#pragma once
#include "Entity.h"
#include <math.h>
#include "ExplosiveEnemy.h"
#include "HealthBar.h"

namespace GameEngine
{
	class SpawnHole : public Entity
	{
	public:
		SpawnHole(int x, int y, Animation ani);
		virtual ~SpawnHole();

		virtual void Update() override;

	protected:
		Uint32 lastPressed = SDL_GetTicks();
		int delay = 10000;
		int min_delay = 1000;
		float delay_multiplier = 0.90;

		HealthBar* generateHealthBar(Actor* enemy);

	private:
		Animation ani;
	};

}
