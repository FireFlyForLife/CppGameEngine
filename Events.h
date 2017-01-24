#pragma once
#include <SDL.h>

namespace GameEngine {
	struct MouseMoveArgs {
	public:
		SDL_Point point;
		bool dragging;

		MouseMoveArgs();
		MouseMoveArgs(SDL_Point point, bool dragging);
	};

	struct MouseClickArgs {
	public:
		SDL_Point point;
		bool down;
		__int8 scan_code;

		MouseClickArgs();
		MouseClickArgs(SDL_Point point, bool down, __int8 scan_code);
	};

	struct KeyClickArgs {
	public:
		bool down;
		__int16 scan_code;

		KeyClickArgs();
		KeyClickArgs(bool down, __int16 scan_code);
	};
}