#pragma once
#include "Texture.h"
#include "GameObject.h"
#include <string>

namespace objects {

	class Tile : public GameObject{
	protected:
		__int32 x = 0; 
		__int32 y = 0;
		Texture* texture = NULL;

	public:
		Tile(std::string textureLocation);

		//TODO: Return Point Struct
		__int32 GetX();
		__int32 GetY();
		void SetX(__int32 x);
		void SetY(__int32 y);
		
	};

}