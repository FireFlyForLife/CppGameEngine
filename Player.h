#pragma once
#include <string>
#include "Entity.h"
#include "Input.h"

namespace GameEngine {
	class Player :
		public Entity
	{
	public:
		const int speed = 4;

		Player(float x, float y, std::string texture_name);
		virtual ~Player();

	protected:
		virtual void OnButtonDown(KeyClickArgs*, int);
	};
}
