#include "UnitController.h"


namespace GameEngine
{
	UnitController::UnitController(World* game_world) : world(game_world)
	{
		mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}

	UnitController::~UnitController()
	{
		//The unit controller is not the owner of the units, its just a controller thus not
		//deleting the units on destruction of the controler.
		
		delete selection_area;
	}

	void UnitController::Update()
	{
		if (removeOnUnitDeath) {
			units.erase(//TODO: Test this
				std::remove_if(units.begin(), units.end(), 
					[](Unit* unit) { return unit != nullptr && unit->getHealth() <= 0; }),
				units.end());
		}
	}

	void UnitController::addUnit(Unit * unit)
	{
		units.push_back(unit);
	}

	void UnitController::killUnit(Unit * unit)
	{
		unit->setHealth(0);
	}

	Unit * UnitController::getUnit(int index)
	{
		if (vector_inrange(units, index))
			return units.at(index);
		return nullptr;
	}

	int UnitController::getUnitAmount()
	{
		return units.size();
	}

	void UnitController::OnMouseDown(MouseClickArgs * args, int)
	{
		Point world_point = world->toWorldSpace(args->point);
		delete selection_area;
		selection_area = new SelectionArea(world_point.x, world_point.y);
		world->entity_list->entities.push_back(selection_area);
	}
	void UnitController::OnMouseMove(MouseMoveArgs * args, int)
	{
		if (selection_area != NULL && args->dragging) {
			Point world_point = world->toWorldSpace(args->point);
			selection_area->setSecondPoint(world_point);
		}
	}
	void UnitController::OnMouseUp(MouseClickArgs * args, int)
	{
		EntityList* list = world->entity_list;
		list->entities.erase(std::remove(list->entities.begin(), list->entities.end(), selection_area), list->entities.end());
		delete selection_area;
		selection_area = NULL;
	}
}
