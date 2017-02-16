#include "EnemyCharacter.h"



namespace GameEngine
{
	EnemyCharacter::EnemyCharacter(float x, float y, string texture, const Animation& ani)
		: Character(x, y, texture), ani_controller(this, ani)
	{
		tag = "enemy";
		ani_controller.enabled = false;

		collider = new BoxShape(0, 0, 16, 16);
	}

	EnemyCharacter::EnemyCharacter(float x, float y, int texture_id, const Animation& ani)
		: Character(x, y, texture_id), ani_controller(this, ani)
	{
		tag = "enemy";
		ani_controller.enabled = false;

		collider = new BoxShape(0, 0, 16, 16);
	}

	EnemyCharacter::~EnemyCharacter()
	{
	}

	void EnemyCharacter::Update()
	{
		if (health <= 0) {
			ani_controller.enabled = true;
			physics_type = NONE;
		}
		else {
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

		ani_controller.Update();
	}
}
