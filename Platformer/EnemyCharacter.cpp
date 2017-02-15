#include "EnemyCharacter.h"



namespace GameEngine
{
	EnemyCharacter::EnemyCharacter(float x, float y, string texture)
		: Character(x, y, texture)
	{
		
	}

	EnemyCharacter::EnemyCharacter(float x, float y, int texture_id = -1)
		: Character(x, y, texture_id)
	{
	}

	EnemyCharacter::~EnemyCharacter()
	{
	}

	void EnemyCharacter::Update()
	{
		World* world = getWorld();
		ent_ptr player = world->entity_list->findWithTag("player");
	}
}
