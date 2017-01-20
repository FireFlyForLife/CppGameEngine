#pragma once
#include "Entity.h"
#include "BoxShape.h"

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
