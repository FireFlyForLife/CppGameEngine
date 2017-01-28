#include "Worker.h"



namespace GameEngine
{
	Worker::Worker(float x, float y, string texture, Spaceport* base)
		: Actor(x, y, texture), base(base)
	{
	}


	Worker::~Worker()
	{
	}

	void Worker::Update()
	{
		if (base == nullptr)
			base = dynamic_cast<Spaceport*>( getWorld()->entity_list->findWithTag("base") );
		
		if (base->getHealth() <= 0)
			return;

		Vector2 self_loc{ x(), y() };
		if (inventory == gather_amount) { //inv is full
			ore = nullptr;
			Vector2 base_loc{ base->x(), base->y() };
			if (distanceBetween(self_loc, base_loc) < gather_range) { //deposit
				base->addResources(inventory);
				inventory = 0;
			}
			else { //or go to base
				if (path.empty())
					findpathTo(base);
				else
					walkTo();
			}
		}
		else {
			if (ore == nullptr) {
				findOre();
			}
			else {
				Vector2 ore_loc{ ore->x(), ore->y() };
				if (distanceBetween(self_loc, ore_loc) < gather_range) {
					collect();
				}
				else {
					if (path.empty())
						findpathTo(ore);
					else
						walkTo();
				}
			}
		}
	}
	void Worker::collect()
	{
		inventory += gather_speed;
		inventory = fmin(inventory, gather_amount);
	}
	void Worker::walkTo()
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
	void Worker::findpathTo(Entity * loc)
	{
		int scale = getWorld()->map->tile_scale;
		Point self{ x() / scale, y() / scale };
		Point other{ loc->x() / scale, loc->y() / scale };
		path = findPath(getWorld(), self, other);
	}
	void Worker::findOre()
	{
		std::vector<Entity*> ores = getWorld()->entity_list->findAllWithTag("ore");
		ores.erase(std::remove_if(ores.begin(), ores.end(), [this](Entity* entity) {
			Vector2 mypos{ x(), y() };
			Vector2 target{ entity->x(), entity->y() };
			return distanceBetween(mypos, target) > walk_range;
		}), ores.end());

		if (ores.size() <= 0)
			return;

		int ore_num = rangeRandomAlg2(0, ores.size() - 1);

		ore = ores[ore_num];
	}

	int Worker::rangeRandomAlg2(int min, int max) {
		int n = max - min + 1;
		int remainder = RAND_MAX % n;
		int x;
		do {
			x = rand();
		} while (x >= RAND_MAX - remainder);
		return min + x % n;
	}
}
