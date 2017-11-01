#include "UnitController.h"
#include <iostream>

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
		//The unit controller is not the owner of the selected, its just a controller thus not
		//deleting the selected on destruction of the controler.
		
		delete selection_area;
	}

	void UnitController::Update()
	{
		if (removeOnUnitDeath) {
			selected.erase(//TODO: Test this
				std::remove_if(selected.begin(), selected.end(), 
					[](Unit* unit) { return unit != nullptr && unit->getHealth() <= 0; }),
				selected.end());
		}

		
	}

	void UnitController::addUnit(Unit * unit)
	{
		selected.push_back(unit);
	}

	void UnitController::killUnit(Unit * unit)
	{
		unit->setHealth(0);
	}

	Unit * UnitController::getUnit(int index)
	{
		if (vector_inrange(selected, index))
			return selected.at(index);
		return nullptr;
	}

	int UnitController::getUnitAmount()
	{
		return selected.size();
	}

	void UnitController::OnMouseDown(MouseClickArgs * args, int)
	{
		if (args->scan_code == 1) {
			Point world_point = world->toWorldSpace(args->point);
			//delete selection_area;
			deleteSelectionArea();
			selection_area = new SelectionArea(world_point.x, world_point.y);
			world->entity_list->add(selection_area);
		}
		else if (args->scan_code == 3) {
			for each (Unit* unit in selected)
			{
				int scale = world->map->tile_scale;
				Point start(unit->x() / scale, unit->y() / scale);
				Point world_space = world->toWorldSpace(args->point);
				Point end(world_space.x / scale, world_space.y / scale);
				std::vector<Point> path = findPath(world, start, end);
				
				for (size_t i = 0; i < path.size(); i++)
				{
					path[i] = Point(path[i].x * scale, path[i].y * scale);
				}
				unit->state = MOVING;
				unit->path = path;
			}
		}
	}
	void UnitController::OnMouseMove(MouseMoveArgs * args, int)
	{
		if (args->dragging && args->scan_code == 1 &&selection_area != NULL) {
			Point world_point = world->toWorldSpace(args->point);
			selection_area->setSecondPoint(world_point);
			Rectangle bounds = selection_area->getRectangle();
			BoxShape selection_collider(bounds);
			for each (auto entity in world->entity_list->entities)
			{
				Unit* unit = dynamic_cast<Unit*>(entity.get());
				if (unit) {
					BoxShape* collider = dynamic_cast<BoxShape*>(entity->getCollider()); //TODO: Find solution to this
					if (collider != nullptr) {
						BoxShape world_collider(*collider);
						world_collider.x += unit->x();
						world_collider.y += unit->y();
						selected.clear();
						if (hasOverlap({}, world_collider, {}, selection_collider)) {
							if (vector_find<Unit*>(selected, unit) == -1)
								selected.push_back(unit);
						}
					}
				}
			}
		}
	}
	void UnitController::OnMouseUp(MouseClickArgs * args, int)
	{
		if (args->scan_code == 1) {
			deleteSelectionArea();
			//delete selection_area; //it is a shared_ptr already
			//selection_area = NULL;
		}
	}

	void UnitController::deleteSelectionArea()
	{
		EntityList* list = world->entity_list;

		for (auto it = list->begin(); it != list->end(); ++it)
		{
			if (it->get() == selection_area) {
				list->entities.erase(it);
				return;
			}
		}
	}
}
