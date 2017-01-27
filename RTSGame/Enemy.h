#pragma once
#include "Actor.h"
#include "BoxShape.h"
#include "SDL_image.h"

namespace GameEngine
{
	class Enemy : public Actor
	{
	public:
		Enemy(float x, float y, std::string full_texture_location);
		virtual ~Enemy();

		virtual void Update() override;
		virtual SDL_Surface* getFrame(SDL_Renderer*) override;

	private:
		SDL_Surface* surface;
	};

}
