#include "Tower.h"



namespace GameEngine
{
	Tower::Tower(float x, float y, int texture)
		: Building(x, y, texture)
	{
	}

	Tower::Tower(float x, float y, string texture)
		: Building(x, y, texture)
	{
	}

	Tower::~Tower()
	{
	}

	void Tower::Update()
	{
		if (health <= 0)
			return;

		if (target == nullptr || target->getHealth() <= 0 || !enemyInRange(target)) {
			target = nullptr;
			lookForEnemies();
		}
		else {
			attackTarget();
		}
	}

	void Tower::lookForEnemies()
	{
		World* world = getWorld();
		for each (auto entity in world->entity_list->entities)
		{
			Enemy* enemy = dynamic_cast<Enemy*>(entity.get());
			if (enemy != nullptr) {
				if (enemy->getHealth() > 0 && enemyInRange(enemy)) {
					target = enemy;
				}
			}
		}
	}

	void Tower::attackTarget()
	{
		Uint32 time = SDL_GetTicks();
		if (lastHit + attack_delay < time) {
			target->addHealth(-attack_damage);
			lastHit = time;
			std::cout << target->getHealth() << std::endl;
		}
	}

	bool Tower::enemyInRange(Enemy * enemy)
	{
		Vector2 dir = Vector2(x(), this->y()) - Vector2(enemy->x(), enemy->y());
		return dir.magnitude2() <= pow(attack_range, 2);
	}
}
