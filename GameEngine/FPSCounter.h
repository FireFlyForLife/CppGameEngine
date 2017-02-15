#pragma once
#include "Entity.h"
#include <SDL_ttf.h>
#include "Globals.h"

namespace GameEngine
{
	class FPSCounter : public Entity
	{
	public:
		FPSCounter();
		~FPSCounter();

		SDL_Surface* getFrame(SDL_Renderer*) override;
		void Update() override;
		
		void enableDrawing(TTF_Font* font);
		void disableDrawing();

		bool debugPrint = true;

	protected:
		TTF_Font* font = nullptr;
	};

}
