#pragma once
#include "Enemy.h"
#include "Point.h"
#include "Animation.h"
#include "AnimationController.h"

namespace GameEngine
{
	class ExplosiveEnemy : public Enemy
	{
	public:
		ExplosiveEnemy(float x, float y, std::string texture ,const Animation& ani);
		ExplosiveEnemy(float x, float y, int texture, const Animation& ani);
		virtual ~ExplosiveEnemy();

		virtual void Update() override;

	protected:
		AnimationController ani_controller;
	};

}
