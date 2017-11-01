#include "Enemy.h"



namespace GameEngine
{
	Enemy::Enemy()
		: Actor()
	{
	}

	Enemy::Enemy(float x, float y, int texture)
		: Actor(x, y, texture)
	{
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
				state = ENEMY_MOVING;
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
		int scale = getWorld()->map->tile_scale;
		Vector2 large_direction = Vector2(path[0])*scale - Vector2(x(), y());
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
		std::vector<ent_ptr> buildings = getWorld()->entity_list->findAllWithTag(target_tag);
		buildings.erase(std::remove_if(buildings.begin(), buildings.end(), isNotEnabled()), buildings.end());
		auto compare = [this](ent_ptr a, ent_ptr b) { 
			return distanceBetween({ x(), y() }, { a->x(), a->y() }) > distanceBetween({ x(), y() }, { b->x(), b->y() });
		};
		std::priority_queue<ent_ptr, std::vector<ent_ptr>, decltype(compare)> pr_queue(compare);
		for each (auto entity in buildings)
		{
			pr_queue.emplace(entity);
		}

		if (pr_queue.size() <= 0)
			return;

		ent_ptr top = pr_queue.top();
		target = reinterpret_cast<Building*>(top.get());

		int scale = getWorld()->map->tile_scale;

		Point start{ x() / scale, y() / scale };
		Point end{ target->x() / scale, target->y() / scale};
		path = findPath(getWorld(), start, end);
	}

	void Enemy::attackBuilding()
	{
		Uint32 time = SDL_GetTicks();
		if (lastHit + attack_delay < time) {
			target->addHealth(-damage);
			lastHit = time;
			std::cout << target->getHealth() << std::endl;
		}
	}
	bool Enemy::isNotEnabled::operator()(ent_ptr entity)
	{
		return !(entity.get() != nullptr && entity->enabled);
	}
}