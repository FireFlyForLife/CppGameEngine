#pragma once
#include "Entity.h"
#include "BoxShape.h"

namespace GameEngine
{
	class EntityWall : public Entity
	{
	public:
		EntityWall(float x, float y, string texture);
		virtual ~EntityWall();
	};
}

