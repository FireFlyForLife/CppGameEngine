#pragma once
#include "Actor.h"
#include <SDL_image.h>
#include "Point.h"
#include <limits>

namespace GameEngine
{
	class HealthBar : public Entity
	{
	public:
		HealthBar(Actor* parent, std::string texture_location);
		virtual ~HealthBar();

		virtual SDL_Surface* getFrame(SDL_Renderer*) override;

		void setParent(Actor* newParent);
		Actor* getParent();

		void setMaxHealth(int newMaxHealth);
		int getMaxHealth();

		Point offset{ 5, -20 };
		int killDelay = 750;

	protected:
		int maxHealth = 0;
		Uint32 killTime = std::numeric_limits<Uint32>::max();

		Actor* parent = nullptr;
		SDL_Surface* outline = nullptr;
	};
}