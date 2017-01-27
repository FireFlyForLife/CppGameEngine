#pragma once
#include "Actor.h"
#include "BoxShape.h"

//TODO: Delete this file from the GameEngine project

namespace GameEngine
{
	class Building : public Actor
	{
	public:
		Building(float x, float y, std::string texture);
		Building(float x, float y, int texture_id);

		virtual ~Building();
	};

}
