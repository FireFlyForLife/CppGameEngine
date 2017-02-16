#pragma once
#include "Entity.h"
#include "Globals.h"
#include "World.h"
#include "Character.h"
#include "PlatformPlayer.h"

namespace GameEngine
{
	class GunShot : public Entity
	{
	public:
		const float speed;
		const int damage;
		const float maxDistance = 600.f;

		GunShot(float x, float y, const Vector2& dir, float speed = 1225.f, SDL_Color color = { 240,0,0 }, int damage = 50);
		virtual ~GunShot();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual SDL_Surface* getFrame(SDL_Renderer* renderer) override;

		float getTraveledDistance();

		SDL_Color color;

	protected:
		Vector2 dir;
		float distance = 0;
	};
}