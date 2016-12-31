#pragma once
#include "Texture.h"
#include "GameObject.h"
#include "Globals.h"
#include <string>

namespace GameEngine {

	class Tile : public GameObject{
	protected:
		__int32 x = 0;
		__int32 y = 0;
		int texture = NULL;

	public:
		Tile();
		Tile(std::string texture_name);
		Tile(size_t texture_id);

		//TODO: Return Point Struct
		__int32 GetX();
		__int32 GetY();
		void SetX(__int32 x);
		void SetY(__int32 y);

		int GetTexture();
		
		virtual bool blocking();
		virtual int weight();

		
	};

}