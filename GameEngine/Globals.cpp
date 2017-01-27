#include "Globals.h"

namespace GameEngine {
	namespace Global {
		Uint32 time_on_last_frame = SDL_GetTicks();
		TextureManager texture_manager;
		Uint32 deltaTime()
		{
			return SDL_GetTicks() - time_on_last_frame;
		}
	}
}