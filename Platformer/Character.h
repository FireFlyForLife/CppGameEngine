#pragma once
#include "Entity.h"

namespace GameEngine
{
	class Character : public Entity
	{
	public:
		Character();
		Character(float x, float y, int texture_id = -1);
		Character(float x, float y, string texture);
		Character(Character& other) = default;
		virtual ~Character();

		int getHealth();
		void setHealth(int amount);
		void addHealth(int amount);

	protected:
		int health = 100;
	};
}

