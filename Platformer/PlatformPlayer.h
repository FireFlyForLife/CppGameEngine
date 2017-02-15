#pragma once
#include "PhysicsPlayer.h"
#include "AnimationController.h"
#include "GunShot.h"

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
		std::weak_ptr<Entity> crosshair;

		int health = 100;

	private:
		void OnMouseDown(MouseClickArgs*, int);
		void OnMouseMove(MouseMoveArgs*, int);
		void OnMouseUp(MouseClickArgs*, int);
	};

}
