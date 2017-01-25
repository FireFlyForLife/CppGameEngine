#pragma once
#include "TextureManager.h"
#include "Globals.h"

namespace GameEngine {
	class World;

	class GameObject {
	public:
		virtual ~GameObject();

		virtual void Update();

		World* getWorld();
		void setWorld(World* newWorld);

		bool renderSelf = false;
		virtual std::pair<SingleTexture*, Rectangle*> getFrame(SDL_Renderer* renderer);
	private:
		World* living_world;
	};
}