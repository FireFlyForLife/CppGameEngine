#pragma once
#include "TextureManager.h"
#include "Globals.h"

namespace GameEngine {
	class World;

	class GameObject {
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Update();

		World* getWorld();
		void setWorld(World* newWorld);

		bool renderSelf = false;
		virtual SDL_Surface* getFrame(SDL_Renderer* renderer);

		bool enabled = true;

	private:
		World* living_world;
	};
}