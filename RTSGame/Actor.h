#pragma once
#include "Entity.h"

namespace GameEngine
{
	class Actor : public Entity
	{
	public:
		Actor();
		Actor(float x, float y, int texture = -1);
		Actor(float x, float y, std::string texture_name);
		virtual ~Actor();

		int getHealth();
		void setHealth(int newHealth);
		void addHealth(int addHealth);

	protected:
		int health = 100;
	};
}

