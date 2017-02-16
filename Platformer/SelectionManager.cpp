#include "SelectionManager.h"



namespace GameEngine
{
	SelectionManager::SelectionManager()
	{
		ids[0] = mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		ids[1] = mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		ids[2] = mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}


	SelectionManager::SelectionManager(SelectionArea* area)
		: selection_area(area)
	{
		ids[0] = mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		ids[1] = mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		ids[2] = mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });
	}

	SelectionManager::~SelectionManager()
	{
		mouseDownListeners.remove(ids[0]);
		mouseMoveListeners.remove(ids[1]);
		mouseUpListeners.remove(ids[2]);
	}

	void SelectionManager::Update()
	{
	}

	void SelectionManager::OnMouseDown(MouseClickArgs * args, int)
	{
		if (!enabled)
			return;

		if (args->scan_code == 3) {
			if (selection_area) {
				std::cout << selection_area->getRectangle().toStr() << std::endl;
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
		if (!enabled)
			return;

		if (args->dragging && args->scan_code == 4 && selection_area != NULL) {
			World* world = getWorld();
			Point world_point = world->toWorldSpace(args->point);
			selection_area->setSecondPoint(world_point);
		}
	}
	void SelectionManager::OnMouseUp(MouseClickArgs * args, int)
	{
		if (!enabled)
			return;

		if (args->scan_code == 3) {
			
		}
	}
}
