#pragma once
#include "GameObject.h"
#include "Globals.h"
#include <string>

namespace GameEngine {

	class Entity : public GameObject {
	protected:
		float _x = 0;
		float _y = 0;
		int texture = 0;

	public:
		Entity();
		Entity(int x, int y, int texture = -1);
		Entity(int x, int y, std::string texture_name);
		~Entity();

		int getTexture();
		void setTexture(int id);

		float x();
		void x(float);
		float y();
		void y(float);

	};

}