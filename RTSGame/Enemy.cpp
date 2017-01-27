#include "Enemy.h"



namespace GameEngine
{
	Enemy::Enemy(float x, float y, std::string texture) : Actor(x, y)
	{
		this->collider = new BoxShape(0, 0, 16, 16);
		this->surface = IMG_Load(texture.c_str());
		//renderSelf = true;
	}

	Enemy::~Enemy() {
		SDL_FreeSurface(surface);
	}

	void Enemy::Update() {
		if (health <= 0)
			enabled = false;
	}

	SDL_Surface * Enemy::getFrame(SDL_Renderer *)
	{
		if(health <= 0)
			return nullptr;
		
		SDL_Surface* copy = SDL_CreateRGBSurface(0, surface->w, surface->h, 32, 0, 0, 0, 0);
		SDL_BlitScaled(surface, NULL, copy, NULL);

		return copy;
	}
}