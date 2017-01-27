#include "Unit.h"

namespace GameEngine
{
	Unit::Unit(float x, float y, std::string texture) : Actor(x, y, texture)
	{
		this->collider = new BoxShape(0, 0, 16, 16);
	}

	Unit::Unit(float x, float y, int id) : Actor(x, y, id)
	{
		this->collider = new BoxShape(0, 0, 16, 16);
	}

	Unit::~Unit()
	{
	}

	void Unit::Update()
	{
		switch (state)
		{
		case IDLE:
			lookForEnemies();
			break;
		case MOVING:
			if (path.empty())
				state = IDLE;
			else
				moveAlongPath();
			break;
		case ATTACKING:
			if (target == nullptr || target->getHealth() <= 0 || !enemyInRange(target)) {
				target == nullptr;
				state = IDLE;
			}
			else
				attackTarget();
			break;
		default:
			break;
		}
	}

	void Unit::moveAlongPath()
	{
		Vector2 large_direction = Vector2(path[0]) -  Vector2(x(), y());
		if (large_direction.magnitude2() == 0) {
			path.erase(path.begin());
			return;
		}

		Vector2 dir = large_direction.normalized() * (speed * (float)Global::deltaTime());
		Vector2 move = v2_min(dir, large_direction);
		x(x() + move.x);
		y(y() + move.y);
		if (move == large_direction) {
			path.erase(path.begin());
		}
	}

	void Unit::lookForEnemies()
	{
		World* world = getWorld();
		for each (Entity* entity in world->entity_list->entities)
		{
			Enemy* enemy = dynamic_cast<Enemy*>(entity);
			if (enemy != nullptr) {
				if (enemyInRange(enemy)) {
					state = ATTACKING;
					target = enemy;
				}
			}
		}
	}

	void Unit::attackTarget()
	{
		Uint32 time = SDL_GetTicks();
		if (lastHit + attack_delay < time) {
			target->addHealth(-attack_damage);
			lastHit = time;
			std::cout << target->getHealth() << std::endl;
		}
	}

	bool Unit::enemyInRange(Enemy * enemy)
	{
		Vector2 dir = Vector2(x(), this->y()) - Vector2(enemy->x(), enemy->y());
		return dir.magnitude2() <= pow(attack_range, 2);
	}

	UnitTarget::UnitTarget(float x, float y) : Entity(x, y)
	{
	}
}
