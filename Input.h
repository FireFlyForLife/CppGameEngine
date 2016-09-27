#pragma once
#include "EventSource.h"
#include "Events.h"
#include <SDL.h>

namespace GameEngine {
	/*
		TODO: Which events need to be fired? And which Structs do they have.
	*/
	/*struct MouseMoveArgs {
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
		bool down;
		__int16 scan_code;

		KeyClickArgs();
		KeyClickArgs(bool down, __int16 scan_code);
	};*/

	EventSource<MouseMoveArgs*, int> mouseMoveListeners;
	EventSource<MouseClickArgs*, int> mouseClickListeners;
	EventSource<MouseClickArgs*, int> mouseDownListeners;
	EventSource<MouseClickArgs*, int> mouseUpListeners;

	EventSource<KeyClickArgs*, int> keyClickListeners;
	EventSource<KeyClickArgs*, int> keyDownListeners;
	EventSource<KeyClickArgs*, int> keyUpListeners;
}