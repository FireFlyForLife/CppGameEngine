#include "HealthBar.h"



namespace GameEngine
{
	HealthBar::HealthBar(Actor* parent, std::string texture_location) : 
		Entity(parent->x(), parent->y()), parent(parent)
	{
		renderSelf = true;
		outline = IMG_Load(texture_location.c_str());
		maxHealth = parent->getHealth();
	}

	HealthBar::~HealthBar()
	{
		SDL_FreeSurface(outline);
	}

	SDL_Surface * HealthBar::getFrame(SDL_Renderer *)
	{
		int health = parent->getHealth();
		if (health <= 0) {
			if (killTime == std::numeric_limits<Uint32>::max())
				killTime = SDL_GetTicks();
			else if (killTime + killDelay < SDL_GetTicks()) {
				enabled = false;
				return nullptr;
			}
		}

		float health_fraction = 0;
		if (health > 0)
			health_fraction = (float)health / (float)maxHealth;

		SDL_Surface* surface = SDL_CreateRGBSurface(0, outline->w, outline->h, 32, 0, 0, 0, 0);
		SDL_Rect rect{ 0, 0, outline->w, outline->h };

		SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 255, 0, 0));

		rect.w = rect.w * health_fraction;

		SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0, 255, 0));

		SDL_BlitSurface(outline, NULL, surface, NULL);

		x(parent->x() + offset.x - surface->w / 2);
		y(parent->y() + offset.y);

		return surface;
	}

	void HealthBar::setParent(Actor * newParent)
	{
		parent = newParent;
	}
	Actor * HealthBar::getParent()
	{
		return parent;
	}
	void HealthBar::setMaxHealth(int newMaxHealth)
	{
		maxHealth = newMaxHealth;
	}
	int HealthBar::getMaxHealth()
	{
		return maxHealth;
	}
}
