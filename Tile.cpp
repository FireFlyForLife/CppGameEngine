#include "Tile.h"

namespace objects {

	Tile::Tile(std::string textureLocation)
	{
		texture = new Texture(textureLocation);
	}

	__int32 Tile::GetX()
	{
		return x;
	}

	__int32 Tile::GetY() {
		return y;
	}

	void Tile::SetX(__int32 x)
	{
		this->x = x;
	}

	void Tile::SetY(__int32 y)
	{
		this->y = y;
	}

}
