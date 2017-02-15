#include "PlatformPlayer.h"



namespace GameEngine
{
	PlatformPlayer::PlatformPlayer(float x, float y, const Animation& ani)
		: PhysicsPlayer(x, y, "player"), ani_controller(this, ani)
	{
		ani_controller.enabled = false;
	}


	PlatformPlayer::~PlatformPlayer()
	{
	}

	void PlatformPlayer::Update()
	{
		//PhysicsPlayer::Update();
		if (health <= 0) {
			ani_controller.enabled = true;
		}

		ani_controller.Update();
	}

	int PlatformPlayer::getHealth()
	{
		return health;
	}
	void PlatformPlayer::setHealth(int amount)
	{
		health = amount;
	}
	void PlatformPlayer::addHealth(int amount)
	{
		health += amount;
	}

}
