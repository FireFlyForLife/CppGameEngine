#include "Spaceport.h"



namespace GameEngine
{
	Spaceport::Spaceport(float x, float y) : Building(x, y, "space_port")
	{
		setHealth(500);
	}


	Spaceport::~Spaceport()
	{
	}
}
