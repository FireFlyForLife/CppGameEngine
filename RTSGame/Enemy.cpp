#include "Enemy.h"



namespace GameEngine
{
	Enemy::Enemy()
		: Actor()
	{
		findPathToBuilding();
	}

	Enemy::Enemy(float x, float y, int texture)
		: Actor(x, y, texture)
	{
		findPathToBuilding();
	}

	Enemy::Enemy(float x, float y, std::string texture_name)
		: Enemy(x, y, Global::texture_manager.getID(texture_name))
	{
	}

	Enemy::~Enemy() {
		
	}

	void Enemy::Update() {
		if (health <= 0) {
			enabled = false;
			return;
		}

		switch (state)
		{
		case ENEMY_STATE::ENEMY_MOVING:
			if (path.empty())
				state = ENEMY_ATTACKING;
			else
				moveAlongPath();
			break;
		case ENEMY_STATE::ENEMY_ATTACKING:
			if (target == nullptr || target->getHealth() <= 0) {
				findPathToBuilding();
			}
			else {
				attackBuilding();
			}
			break;
		}
	}

	void Enemy::moveAlongPath()
	{
		Vector2 large_direction = Vector2(path[0]) - Vector2(x(), y());
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

	void Enemy::findPathToBuilding()
	{
		//std::vector<Entity*> buildings = getWorld()->entity_list->findAllWithTag(target_tag);
		

		//Point start{ x(), y() };
		//Point end{ target->x(), target->y() };
		//path = findPath(getWorld(), start, end);
	}

	void Enemy::attackBuilding()
	{
		target->addHealth(-damage);
	}
}