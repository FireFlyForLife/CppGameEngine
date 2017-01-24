#include "CommandableEntity.h"



namespace GameEngine
{
	CommandableEntity::CommandableEntity(int x, int y) : Entity(x, y, "robot")
	{
		this->collider = new BoxShape(0, 0, 16, 16);
	}


	CommandableEntity::~CommandableEntity()
	{
	}

	void CommandableEntity::Update()
	{

	}
}
