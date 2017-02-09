#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Shape.h"
#include <string>

namespace GameEngine {
	enum ENTITY_MOVEMENT {
		STATIC,
		KINEMATIC,
		DYNAMIC
	};

	class Entity : public GameObject {
	protected:
		float _x = 0;
		float _y = 0;
		Shape* collider = nullptr;

	public:
		Entity();
		Entity(float x, float y, int texture = -1);
		Entity(float x, float y, std::string texture_name);
		virtual ~Entity();

		Shape* getCollider();
		void setCollider(Shape* newCollider);

		float x();
		void x(float);
		float y();
		void y(float);

		ENTITY_MOVEMENT movement_type = ENTITY_MOVEMENT::KINEMATIC;

	};

}