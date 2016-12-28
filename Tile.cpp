#include "Tile.h"

namespace GameEngine {
	Tile::Tile()
	{

	}
	Tile::Tile(std::string textureLocation)
	{
		texture = NULL;
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

	uint16_t Tile::GetTexture()
	{
		return texture;
	}

	bool Tile::blocking()
	{
		return false;
	}

	int Tile::weight()
	{
		return 1;
	}

}
