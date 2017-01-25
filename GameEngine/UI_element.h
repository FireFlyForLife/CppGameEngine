#pragma once
#include "Entity.h"

namespace GameEngine
{
	class UI_element : public Entity
	{
	public:
		UI_element(int x, int y);
		virtual ~UI_element();
	};

}
