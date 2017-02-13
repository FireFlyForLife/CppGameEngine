#include "EntityWall.h"



namespace GameEngine
{
	EntityWall::EntityWall(float x, float y, string texture)
		: Entity(x, y, texture)
	{
		collider = new BoxShape(0,0, 16, 16);
	}


	EntityWall::~EntityWall()
	{
	}
}
