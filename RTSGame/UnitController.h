#pragma once
#include "Entity.h"
#include "Input.h"
#include "Unit.h"
#include "Vector_Utils.h"
#include "Camera.h"
#include "SelectionArea.h"
#include "World.h"

#include <vector>
#include <algorithm>
#include <math.h>

namespace GameEngine
{
	class UnitController : public Entity
	{
	public:
		bool removeOnUnitDeath = true;

		UnitController(World* game_world);
		virtual ~UnitController();

		virtual void Update() override;

		void addUnit(Unit* unit);
		void killUnit(Unit* unit);
		Unit* getUnit(int index);
		int getUnitAmount();

	protected:
		std::vector<Unit*> units;
		World* world;
		SelectionArea* selection_area = nullptr;

	private:
		void OnMouseDown(MouseClickArgs*, int);
		void OnMouseMove(MouseMoveArgs*, int);
		void OnMouseUp(MouseClickArgs*, int);
	};
}
