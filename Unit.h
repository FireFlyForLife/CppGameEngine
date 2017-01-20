#pragma once
#include "Entity.h"
#include "BoxShape.h"
#include "Input.h"

namespace GameEngine
{
	//TODO: Create a state machine for this
	class Unit : public Entity
	{
	public:
		Unit(float x, float y, std::string texture);
		Unit(float x, float y, int id);
		~Unit();

		virtual void Update() override;

		int getHealth();
		void setHealth(int newHealth);
		void addHealth(int addHealth);

	protected:
		int health = 100;
	};
}

