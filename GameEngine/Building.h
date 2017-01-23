#pragma once
#include "Entity.h"
#include "BoxShape.h"

//TODO: Delete this file from the GameEngine project

namespace GameEngine
{
	class Building : public Entity
	{
	public:
		Building(float x, float y, std::string texture);
		Building(float x, float y, int texture_id);

		virtual ~Building();
		
		int getHealth();
		void setHealth(int newHealth);
		void removeHealth(int diffHealth);

	protected:
		int health = 100;
	};

}
