#pragma once
#include "Tower.h"
#include "AnimationController.h"

namespace GameEngine
{
	class ExplosiveTower : public Tower
	{
	public:
		ExplosiveTower(float x, float y, Animation ani, string texture);
		ExplosiveTower(float x, float y, Animation ani, int texture = -1);
		virtual ~ExplosiveTower();

		virtual void Update() override;

	protected:
		AnimationController ani_controller;
	};
}

