#pragma once
#include "Actor.h"
#include "BoxShape.h"
#include "Point.h"
#include "SDL_image.h"
#include "World.h"
#include "Pathfinder.h"
#include "Vector2.h"
#include "Building.h"
#include <queue>

namespace GameEngine
{
	enum ENEMY_STATE {
		ENEMY_MOVING,
		ENEMY_ATTACKING
	};

	class Enemy : public Actor
	{
	public:
		Enemy();
		Enemy(float x, float y, int texture = -1);
		Enemy(float x, float y, std::string texture_name);
		virtual ~Enemy();

		virtual void Update() override;

		ENEMY_STATE state;

	protected:
		string target_tag = "building";
		std::vector<Point> path;
		float speed = 0.3;
		int range = 30;
		int damage = 15;

		Building* target = nullptr;

		void moveAlongPath();
		void findPathToBuilding();
		void attackBuilding();
	};

}
