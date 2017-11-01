#include "PlacementManager.h"



namespace GameEngine
{
	PlacementManager::PlacementManager(Entity* preview) : preview(preview)
	{
		preview->enabled = false;

		move_id = mouseMoveListeners.add([this](MouseMoveArgs* args, int id) {this->OnMouseMove(args, id); });
		down_id = mouseDownListeners.add([this](MouseClickArgs* args, int id) { this->OnMouseDown(args, id); });
	}


	PlacementManager::~PlacementManager()
	{
		mouseMoveListeners.remove(move_id);
		mouseDownListeners.remove(down_id);
		delete placement_entity;
	}
	void PlacementManager::prepare(Entity * entity)
	{
		bCanPlace = true;
		if (placement_entity != nullptr)
			delete placement_entity; //if we did not place the entity, delete it.

		placement_entity = entity;
		preview->enabled = true;
	}
	bool PlacementManager::canPlace()
	{
		return bCanPlace;
	}
	void PlacementManager::OnMouseMove(MouseMoveArgs * args, int)
	{
		if (bCanPlace) {
			int scale = getWorld()->map->tile_scale;
			Point worldLocation = getWorld()->toWorldSpace(args->point);
			worldLocation.x = ((worldLocation.x + scale / 2) / scale) * scale;
			worldLocation.y = ((worldLocation.y + scale / 2) / scale) * scale;
			preview->x(worldLocation.x);
			preview->y(worldLocation.y);
		}
	}
	void PlacementManager::OnMouseDown(MouseClickArgs * args, int)
	{
		if (bCanPlace && args->scan_code == 1) {
			int scale = getWorld()->map->tile_scale;
			Point loc = { preview->x() / scale, preview->y() / scale};
			if (!getWorld()->blocking(loc)) {
				placement_entity->x(preview->x());
				placement_entity->y(preview->y());
				getWorld()->entity_list->add(placement_entity);
				placement_entity = nullptr;
				bCanPlace = false;
				preview->enabled = false;
			}
		}
	}
}
