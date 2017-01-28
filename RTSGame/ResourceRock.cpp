#include "ResourceRock.h"



namespace GameEngine
{
	ResourceRock::ResourceRock(int x, int y) : Entity(x, y, "resource_rock")
	{
		tag = "ore";
	}


	ResourceRock::~ResourceRock()
	{
	}
}
