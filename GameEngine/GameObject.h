#pragma once



namespace GameEngine {
	class World;

	class GameObject {
	public:
		virtual ~GameObject();

		virtual void Update();

		World* getWorld();
		void setWorld(World* newWorld);
	private:
		World* living_world;
	};
}