#include "SpawnHole.h"

namespace GameEngine
{
	SpawnHole::SpawnHole(int x, int y, Animation ani) 
		: Entity(x, y, "hole"), ani(ani)
	{
	}


	SpawnHole::~SpawnHole()
	{
	}

	void SpawnHole::Update()
	{
		Uint32 time = SDL_GetTicks();
		if (lastPressed + delay < time) {
			ExplosiveEnemy* expl_enemy = new ExplosiveEnemy(x(), y(), "enemy", ani);
			HealthBar* bar = generateHealthBar(expl_enemy);
			getWorld()->entity_list->entities.push_back(expl_enemy);
			getWorld()->entity_list->entities.push_back(bar);

			lastPressed = time;
			delay *= delay_multiplier;
			delay = fmax(delay, min_delay);
		}

	}

	HealthBar * SpawnHole::generateHealthBar(Actor * enemy)
	{
		HealthBar* expl_bar = new HealthBar(enemy, "Art/Health_Bar.png");
		return expl_bar;
	}

}