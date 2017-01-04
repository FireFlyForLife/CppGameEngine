#include "Rock.h"



namespace GameEngine
{
	Rock::Rock() : Tile("rock")
	{
	}

	Rock::~Rock()
	{
	}
	bool Rock::blocking()
	{
		return true;
	}
}
