//#include "Input.h"
//
//namespace game_engine {
//#pragma region MouseMoveEvent
//	MouseMoveEvent::MouseMoveEvent()
//	{
//		point = { 0, 0 };
//		dragging = false;
//	}
//	MouseMoveEvent::MouseMoveEvent(Point point, bool dragging) : point(point), dragging(dragging)
//	{
//	}
//#pragma endregion
//#pragma region MouseClickEvent
//	MouseClickEvent::MouseClickEvent() : point({0, 0}), down(false), scan_code(0)
//	{
//	}
//	MouseClickEvent::MouseClickEvent(Point point, bool down, __int8 scan_code) : point(point), down(down), scan_code(scan_code)
//	{
//	}
//#pragma endregion
//#pragma region KeyClickEvent
//	KeyClickEvent::KeyClickEvent() : down(false), scan_code(0)
//	{
//	}
//
//	KeyClickEvent::KeyClickEvent(bool down, __int16 scan_code) : down(down), scan_code(scan_code)
//	{
//	}
//#pragma endregion
//#pragma region Add/Del Listeners
//	bool Input::addMouseMoveListener(MouseMoveDelegate* func)
//	{
//		if(vector_contains<MouseMoveDelegate*>(&mouseMoveListeners, func) != -1)
//			return false;
//
//		mouseMoveListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addMouseClickListener(MouseClickDelegate* func)
//	{
//		if (vector_contains<MouseClickDelegate*>(&mouseClickListeners, func) != -1)
//			return false;
//
//		mouseClickListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addMouseUpListener(MouseClickDelegate * func)
//	{
//		if (vector_contains<MouseClickDelegate*>(&mouseUpListeners, func) != -1)
//			return false;
//
//		mouseClickListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addMouseDownListener(MouseClickDelegate * func)
//	{
//		if (vector_contains<MouseClickDelegate*>(&mouseDownListeners, func) != -1)
//			return false;
//
//		mouseClickListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addKeyClickListener(KeyClickDelegate * func)
//	{
//		if (vector_contains<KeyClickDelegate*>(&keyClickListeners, func) != -1)
//			return false;
//
//		keyClickListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addKeyUpListener(KeyClickDelegate * func)
//	{
//		if (vector_contains<KeyClickDelegate*>(&keyUpListeners, func) != -1)
//			return false;
//
//		keyUpListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::addKeyDownListener(KeyClickDelegate * func)
//	{
//		if (vector_contains<KeyClickDelegate*>(&keyDownListeners, func) != -1)
//			return false;
//
//		keyDownListeners.push_back(func);
//		return true;
//	}
//
//	bool Input::delMouseMoveListener(MouseMoveDelegate * func)
//	{
//		int index = vector_contains<MouseMoveDelegate*>(&mouseMoveListeners, func);
//		if (index == -1)
//			return false;
//
//		//TODO: Does this work?
//		keyDownListeners.erase(keyDownListeners.begin() + index);
//		return true;
//	}
//	
//	//#pragma endregion	
//}
//
//
