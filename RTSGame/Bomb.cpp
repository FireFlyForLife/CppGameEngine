#include "Bomb.h"



namespace GameEngine
{
	Bomb::Bomb(float x, float y, Animation ani) 
		: Entity(x, y, "bomb"), ani_controller(this, ani)
	{
	}


	Bomb::~Bomb()
	{
	}

	void Bomb::Update()
	{
		if (getTexture() == -1) {
			enabled = false;
			return;
		}

		ani_controller.Update();

		Vector2 local(x(), y());
		for each (Entity* entity in getWorld()->entity_list->entities)
		{
			Actor* actor = dynamic_cast<Actor*>(entity);
			if (actor != nullptr && distanceBetween(local, { actor->x(), actor->y() }) <= radius) {
				actor->addHealth(-damage);
			}
		}
	}
}
