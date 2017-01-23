#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Shape.h"
#include <string>

namespace GameEngine {
	
	class Entity : public GameObject {
	protected:
		float _x = 0;
		float _y = 0;
		int texture = 0;
		Shape* collider;

	public:
		Entity();
		Entity(float x, float y, int texture = -1);
		Entity(float x, float y, std::string texture_name);
		virtual ~Entity();

		int getTexture();
		void setTexture(int id);

		Shape* getCollider();
		void setCollider(Shape* newCollider);

		float x();
		void x(float);
		float y();
		void y(float);

	};

}