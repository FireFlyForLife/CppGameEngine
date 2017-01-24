#pragma once
#include "Entity.h"
#include "BoxShape.h"

namespace GameEngine
{
	class CommandableEntity : public Entity
	{
	public:
		CommandableEntity(int x, int y);
		~CommandableEntity();

		 virtual void Update() override;
	};
}

