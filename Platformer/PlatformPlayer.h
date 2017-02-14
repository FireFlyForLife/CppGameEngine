#pragma once
#include "PhysicsPlayer.h"
#include "AnimationController.h"

namespace GameEngine
{
	class PlatformPlayer : public PhysicsPlayer
	{
	public:
		PlatformPlayer(float x, float y, const Animation& death_animation);
		~PlatformPlayer();

		void Update() override;

		int getHealth();
		void setHealth(int amount);
		void addHealth(int amount);

	protected:
		AnimationController ani_controller;

		int health = 100;
	};

}
