#pragma once
#include "EventSource.h"
#include "Events.h"
#include <SDL.h>

namespace GameEngine {
	/*
		TODO: Which events need to be fired?
	*/
	//TODO: have the states of input as well
	

	extern EventSource<MouseMoveArgs*, int> mouseMoveListeners;
	extern EventSource<MouseClickArgs*, int> mouseClickListeners;
	extern EventSource<MouseClickArgs*, int> mouseDownListeners;
	extern EventSource<MouseClickArgs*, int> mouseUpListeners;

	extern EventSource<KeyClickArgs*, int> keyClickListeners;
	extern EventSource<KeyClickArgs*, int> keyDownListeners;
	extern EventSource<KeyClickArgs*, int> keyUpListeners;

	void handle_SDL_Event(SDL_Event* e);
}