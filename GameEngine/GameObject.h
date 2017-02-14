#pragma once
#include "TextureManager.h"
#include "Globals.h"

namespace GameEngine {
	class World;

	class GameObject {
	public:
		GameObject();
		GameObject(int texture_id);
		virtual ~GameObject();

		virtual void Update();
		virtual void LateUpdate();

		World* getWorld();
		void setWorld(World* newWorld);

		int getTexture();
		void setTexture(int id);

		bool renderSelf = false;
		virtual SDL_Surface* getFrame(SDL_Renderer* renderer);

		bool enabled = true;
		string tag;
	protected:
		int texture;

	private:
		World* living_world;
	};
}