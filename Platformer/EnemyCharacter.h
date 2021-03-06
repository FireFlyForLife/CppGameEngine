#pragma once
#include "Character.h"
#include "World.h"
#include "Vector2.h"
#include "GunShot.h"
#include "AnimationController.h"

namespace GameEngine
{
	class EnemyCharacter : public Character
	{
	public:
		const float range = 16 * 20;
		const int damage = 50;
		const float startOffset = 20.f;
		const int fireDelay = 650;

		EnemyCharacter(float x, float y, int textur_id, const Animation& death_animation);
		EnemyCharacter(float x, float y, string texture, const Animation& death_animation);
		virtual ~EnemyCharacter();

		virtual void Update() override;

	protected:
		Uint32 lastFired = SDL_GetTicks();
		AnimationController ani_controller;
	};
}
