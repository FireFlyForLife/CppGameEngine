#pragma once
#include "Entity.h"
#include "Input.h"
#include "World.h"

namespace GameEngine
{
	class PlacementManager : public Entity
	{
	public:
		PlacementManager(Entity* preview);
		virtual ~PlacementManager();

		void prepare(Entity* entity);

		bool canPlace();

	protected:
		bool bCanPlace = false;
		Entity* preview = nullptr;
		Entity* placement_entity = nullptr;

	private:
		void OnMouseMove(MouseMoveArgs* args, int);
		int move_id = -1;
		void OnMouseDown(MouseClickArgs* args, int);
		int down_id = -1;
	};
}

