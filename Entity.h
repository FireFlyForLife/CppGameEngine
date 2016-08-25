#pragma once
#include "Texture.h"
#include "GameObject.h"

namespace objects {

	class Entity : public GameObject {
	protected:
		float x = 0;
		float y = 1;
		Texture* texture;

	public:
		Entity();


	};

}