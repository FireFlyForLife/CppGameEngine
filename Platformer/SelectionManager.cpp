#include "SelectionManager.h"



namespace GameEngine
{
	SelectionManager::SelectionManager()
	{
		mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}


	SelectionManager::SelectionManager(SelectionArea* area)
		: selection_area(area)
	{
		mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}

	SelectionManager::~SelectionManager()
	{
	}

	void SelectionManager::Update()
	{
	}

	void SelectionManager::OnMouseDown(MouseClickArgs * args, int)
	{
		if (args->scan_code == 3) {
			if (selection_area) {
				getWorld()->entity_list->destroy(selection_area);
				selection_area.reset();
			}
			else {
				World* world = getWorld();
				Point world_point = world->toWorldSpace(args->point);
				
				selection_area.reset(new SelectionArea(world_point.x, world_point.y));
				world->entity_list->add(selection_area);
			}
		}
	}
	void SelectionManager::OnMouseMove(MouseMoveArgs * args, int)
	{
		
		if (args->dragging && args->scan_code == 4 && selection_area != NULL) {
			World* world = getWorld();
			Point world_point = world->toWorldSpace(args->point);
			selection_area->setSecondPoint(world_point);
		}
	}
	void SelectionManager::OnMouseUp(MouseClickArgs * args, int)
	{
		if (args->scan_code == 3) {
			
		}
	}
}
