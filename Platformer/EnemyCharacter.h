#pragma once
#include "Character.h"
#include "World.h"
namespace GameEngine
{
	class EnemyCharacter : public Character
	{
	public:
		EnemyCharacter(float x, float y, int textur_id);
		EnemyCharacter(float x, float y, string texture);
		virtual ~EnemyCharacter();

		virtual void Update() override;

	protected:
		
	};
}

