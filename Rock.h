#pragma once
#include "Tile.h"

namespace GameEngine
{
	class Rock : public Tile
	{
	public:
		Rock();
		~Rock();

		virtual bool blocking() override;
	};
}

