#pragma once
#include "Entity.h"

namespace GameEngine
{
	class UI_element : public Entity
	{
	public:
		UI_element(int x, int y, int texture = -1);
		UI_element(int x, int y, string texture);
		virtual ~UI_element();
	};

}
