#pragma once
#include "GameObject.h"
#include "Globals.h"
#include "Shape.h"
#include "Vector2.h"
#include <string>

namespace GameEngine {
	enum PHYSICS_TYPE {
		NONE,
		STATIC,
		DYNAMIC
	};

	class Entity : public GameObject {
	protected:
		float _x = 0;
		float _y = 0;
		Shape* collider = nullptr;
		Vector2 vel;

	public:
		Entity();
		Entity(float x, float y, int texture = -1);
		Entity(float x, float y, std::string texture_name);
		virtual ~Entity();

		Shape* getCollider();
		void setCollider(Shape* newCollider);

		//TODO: Get rid of these anoying getters and setters.
		float x();
		void x(float);
		float y();
		void y(float);

		void setVel(Vector2 newVel);
		Vector2& getVel();

		PHYSICS_TYPE physics_type = PHYSICS_TYPE::STATIC;

	};

}