#pragma once
#include "EventSource.h"
#include "Events.h"
#include <SDL.h>

namespace GameEngine {
	/*
		TODO: Which events need to be fired?
	*/
	//TODO: have the states of input as well
	

	EventSource<MouseMoveArgs*, int> mouseMoveListeners;
	EventSource<MouseClickArgs*, int> mouseClickListeners;
	EventSource<MouseClickArgs*, int> mouseDownListeners;
	EventSource<MouseClickArgs*, int> mouseUpListeners;

	EventSource<KeyClickArgs*, int> keyClickListeners;
	EventSource<KeyClickArgs*, int> keyDownListeners;
	EventSource<KeyClickArgs*, int> keyUpListeners;

	void handle_SDL_Event(SDL_Event* e) {
		if (e->type == SDL_EventType::SDL_KEYDOWN)
		{
			GameEngine::KeyClickArgs args(true, e->key.keysym.scancode);
			GameEngine::keyDownListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_KEYUP) {
			GameEngine::KeyClickArgs args(false, e->key.keysym.scancode);
			GameEngine::keyUpListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
			MouseClickArgs args({ e->button.x, e->button.y }, true, e->button.button);
			mouseDownListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEBUTTONUP) {
			MouseClickArgs args({ e->button.x, e->button.y }, false, e->button.button);
			mouseUpListeners.call(&args, 0);
		}
		else if (e->type == SDL_EventType::SDL_MOUSEMOTION) {
			MouseMoveArgs args({ e->motion.x, e->motion.y }, e->motion.state);
			mouseMoveListeners.call(&args, 0);
		}
	}
}