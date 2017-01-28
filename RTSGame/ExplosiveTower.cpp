#include "ExplosiveTower.h"



namespace GameEngine
{

	ExplosiveTower::ExplosiveTower(float x, float y, Animation ani, string texture)
		: Tower(x, y, texture), ani_controller(this, ani)
	{
		ani_controller.enabled = false;
	}

	ExplosiveTower::ExplosiveTower(float x, float y, Animation ani, int texture)
		: Tower(x, y, texture), ani_controller(this, ani)
	{
	}

	ExplosiveTower::~ExplosiveTower()
	{
	}
	void ExplosiveTower::Update()
	{
		Tower::Update();

		if (getHealth() <= 0)
			ani_controller.enabled = true;

		ani_controller.Update();

		if (getTexture() == -1)
			enabled = false;
	}
}
