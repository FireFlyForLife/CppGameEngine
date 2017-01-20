#pragma once
#include "Entity.h"
#include "Input.h"
#include "Unit.h"
#include "Vector_Utils.h"

#include <vector>
#include <algorithm>

namespace GameEngine
{
	class UnitController : public Entity
	{
	public:
		bool removeOnUnitDeath = true;

		UnitController();
		~UnitController();

		virtual void Update() override;

		void addUnit(Unit* unit);
		void killUnit(Unit* unit);
		Unit* getUnit(int index);
		int getUnitAmount();

	protected:
		std::vector<Unit*> units;

	private:
		void OnMouseDown(MouseClickArgs*, int);
		void OnMouseMove(MouseMoveArgs*, int);
		void OnMouseUp(MouseClickArgs*, int);
	};
}
