#pragma once
#include "TextureManager.h"

namespace GameEngine {
	namespace Global {
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		extern Uint32 time_on_last_frame;
		Uint32 deltaTime();

		extern TextureManager texture_manager;
	}
}