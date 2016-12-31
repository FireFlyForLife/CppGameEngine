#include "Input.h";

namespace GameEngine {
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

//namespace GameEngine {
//#pragma region MouseMoveArgs
//	MouseMoveArgs::MouseMoveArgs()
//	{
//		point = { 0, 0 };
//		dragging = false;
//	}
//	MouseMoveArgs::MouseMoveArgs(SDL_Point point, bool dragging) : point(point), dragging(dragging)
//	{
//	}
//#pragma endregion
//#pragma region MouseClickArgs
//	MouseClickArgs::MouseClickArgs() : point({0, 0}), down(false), scan_code(0)
//	{
//	}
//	MouseClickArgs::MouseClickArgs(SDL_Point point, bool down, __int8 scan_code) : point(point), down(down), scan_code(scan_code)
//	{
//	}
//#pragma endregion
//#pragma region KeyClickArgs
//	KeyClickArgs::KeyClickArgs() : down(false), scan_code(0)
//	{
//	}
//	
//	KeyClickArgs::KeyClickArgs(bool down, __int16 scan_code) : down(down), scan_code(scan_code)
//	{
//	}
//#pragma endregion
//}