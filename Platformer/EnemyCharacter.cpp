#include "EnemyCharacter.h"



namespace GameEngine
{
	EnemyCharacter::EnemyCharacter(float x, float y, string texture)
		: Character(x, y, texture)
	{
		tag = "enemy";

		collider = new BoxShape(0, 0, 16, 16);
	}

	EnemyCharacter::EnemyCharacter(float x, float y, int texture_id = -1)
		: Character(x, y, texture_id)
	{
		tag = "enemy";

		collider = new BoxShape(0, 0, 16, 16);
	}

	EnemyCharacter::~EnemyCharacter()
	{
	}

	void EnemyCharacter::Update()
	{
		World* world = getWorld();
		ent_ptr player = world->entity_list->findWithTag("player");
		Vector2 self(x(), y());
		Vector2 target(player->x(), player->y());
		float distance = distanceBetween(self, target);
		if (distance <= range) {
			float current = SDL_GetTicks();
			if (lastFired + fireDelay < current) {
				Vector2 dir = (target - self).normalized();
				Vector2 s = self + dir * startOffset;
				GunShot* shot = new GunShot(s.x, s.y, dir, 225.f);
				world->entity_list->add(shot);

				lastFired = current;
			}
		}
	}
}
