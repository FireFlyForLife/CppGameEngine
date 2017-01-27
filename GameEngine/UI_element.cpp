#include "UI_element.h"



namespace GameEngine
{
	UI_element::UI_element(int x, int y, int id) : Entity(x, y, id)
	{
	}

	UI_element::UI_element(int x, int y, string texture) 
		: Entity(x, y, Global::texture_manager.getID(texture))
	{
	}


	UI_element::~UI_element()
	{
	}
}
