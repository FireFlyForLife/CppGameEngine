#pragma once
#include "Entity.h"

namespace GameEngine
{
	class SelectionArea : public Entity
	{
	public:
		SelectionArea(int start_x, int start_y);
		virtual ~SelectionArea();

		virtual std::pair<SingleTexture*, Rectangle*> getFrame(SDL_Renderer* renderer) override;
		
		void setSecondPoint(int x, int y);

	protected:
		int end_x, end_y;
	};
}

