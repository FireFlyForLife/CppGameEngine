#include "ScalableTargetWall.h"



namespace GameEngine
{
	ScalableTargetWall::ScalableTargetWall(float x, float y, string texture_path, Vector2 size)
		: Entity(x, y), scale(size)
	{
		surface = IMG_Load(texture_path.c_str());

		renderSelf = true;
		callUpdate = false;

		BoxShape* col = new BoxShape(0, 0, size.x, size.y);
		collider = col;
	}

	ScalableTargetWall::~ScalableTargetWall()
	{
		SDL_FreeSurface(surface);
	}

	SDL_Surface * ScalableTargetWall::getFrame(SDL_Renderer *)
	{
		SDL_Surface* scaled = SDL_CreateRGBSurface(NULL, scale.x, scale.y, 32, 0, 0, 0, 0);
		SDL_BlitScaled(surface, NULL, scaled, NULL);

		return scaled;
	}

}