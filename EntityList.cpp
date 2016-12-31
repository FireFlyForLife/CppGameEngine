#include "EntityList.h"


namespace GameEngine {
	EntityList::EntityList()
	{
	}


	EntityList::~EntityList()
	{
		for each (Entity* entity in entities)
		{
			delete entity;
		}
	}
}