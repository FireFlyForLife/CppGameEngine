#include "PlatformPlayer.h"



namespace GameEngine
{
	PlatformPlayer::PlatformPlayer(float x, float y, const Animation& ani)
		: PhysicsPlayer(x, y, "player"), ani_controller(this, ani)
	{
	}


	PlatformPlayer::~PlatformPlayer()
	{
	}

	void PlatformPlayer::Update()
	{
		
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
