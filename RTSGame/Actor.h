#pragma once
#include "Entity.h"

namespace GameEngine
{
	class Actor : public Entity
	{
	public:
		using Entity::Entity;
		virtual ~Actor();

		int getHealth();
		void setHealth(int newHealth);
		void addHealth(int addHealth);

	protected:
		int health = 100;
	};
}

