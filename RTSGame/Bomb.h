#pragma once
#include "Entity.h"
#include "AnimationController.h"
#include "World.h"
#include "Vector2.h"
#include "Actor.h"

namespace GameEngine
{
	class Bomb :
		public Entity
	{
	public:
		Bomb(float x, float y, Animation ani);
		virtual ~Bomb();

		virtual void Update() override;

	protected:
		int radius = 80;
		int damage = 20;

		AnimationController ani_controller;
	};

}
