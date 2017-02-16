#pragma once
#include "Entity.h"
#include "BoxShape.h"
#include "SDL_image.h"

namespace GameEngine
{
	class ScalableTargetWall : public Entity
	{
	public:
		ScalableTargetWall(float x, float y, string texture_path, Vector2 size);
		virtual ~ScalableTargetWall();

		virtual SDL_Surface* getFrame(SDL_Renderer*);

	protected:
		Vector2 scale;
		SDL_Surface* surface = nullptr;
	};

}
