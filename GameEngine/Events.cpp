#include "Events.h"

namespace GameEngine {
#pragma region MouseMoveArgs
	MouseMoveArgs::MouseMoveArgs()
	{
		point = { 0, 0 };
		dragging = false;
	}
	MouseMoveArgs::MouseMoveArgs(SDL_Point point, bool dragging) : point(point), dragging(dragging)
	{
	}
#pragma endregion
#pragma region MouseClickArgs
	MouseClickArgs::MouseClickArgs() : point({0, 0}), down(false), scan_code(0)
	{
	}
	MouseClickArgs::MouseClickArgs(SDL_Point point, bool down, __int8 scan_code) : point(point), down(down), scan_code(scan_code)
	{
	}
#pragma endregion
#pragma region KeyClickArgs
	KeyClickArgs::KeyClickArgs() : down(false), scan_code(0)
	{
	}
		
	KeyClickArgs::KeyClickArgs(bool down, __int16 scan_code) : down(down), scan_code(scan_code)
	{
	}
#pragma endregion
}
