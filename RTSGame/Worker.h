#pragma once
#include "Actor.h"
#include "Spaceport.h"
#include "World.h"
#include "Vector2.h"
#include <random>
#include "Pathfinder.h"

namespace GameEngine
{
	enum WORKER_STATE {
		WORKER_COLLECT,
		WORKER_RETURN,
		WORKER_WALK,
		WORKER_DEPOSIT
	};

	class Worker : public Actor
	{
	public:
		Worker(float x, float y, string texture, Spaceport* base);
		virtual ~Worker();

		virtual void Update() override;

	protected:
		int walk_range = 120;
		int gather_range = 16;
		int gather_amount = 5;
		int gather_speed = 1;
		float speed = 0.075;

		int rangeRandomAlg2(int min, int max);

		WORKER_STATE state = WORKER_DEPOSIT;
		Spaceport* base = nullptr;
		Entity* ore = nullptr;
		int inventory = 0;
		std::vector<Point> path;

		void collect();
		void walkTo();
		void findpathTo(Entity* location);
		void findOre();
	};

}
