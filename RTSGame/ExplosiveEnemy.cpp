#include "ExplosiveEnemy.h"



namespace GameEngine
{
	ExplosiveEnemy::ExplosiveEnemy(float x, float y, std::string texture, const Animation& ani)
		: Enemy(x, y, texture), ani_controller(this, ani)
	{
		ani_controller.enabled = false;
	}

	ExplosiveEnemy::ExplosiveEnemy(float x, float y, int texture, const Animation& ani)
		: Enemy(x, y, texture), ani_controller(this, ani)
	{
		ani_controller.enabled = false;
	}

	ExplosiveEnemy::~ExplosiveEnemy()
	{
	}
	void ExplosiveEnemy::Update()
	{
		int health = getHealth();
		if(health > 0)
			Enemy::Update();

		if (health <= 0)
			ani_controller.enabled = true;

		ani_controller.Update();
	}
}
