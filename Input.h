#pragma once
#include <vector>
#include <functional>
#include "Vector_Utils.h"
#include "Includes.h"

using std::vector;
using std::function;

namespace game_engine{
	typedef function<void(struct MouseMoveEvent*)> MouseMoveDelegate;
	typedef function<void(struct MouseClickEvent*)> MouseClickDelegate;
	typedef function<void(struct KeyClickEvent*)> KeyClickDelegate;

	class Input {
	private:
		vector<MouseMoveDelegate*> mouseMoveListeners;
		vector<MouseClickDelegate*> mouseClickListeners;
		vector<MouseClickDelegate*> mouseDownListeners;
		vector<MouseClickDelegate*> mouseUpListeners;

		vector<KeyClickDelegate*> keyClickListeners;
		vector<KeyClickDelegate*> keyDownListeners;
		vector<KeyClickDelegate*> keyUpListeners;

	public:
		bool addMouseMoveListener(MouseMoveDelegate*);
		bool addMouseClickListener(MouseClickDelegate*);
		bool addMouseUpListener(MouseClickDelegate*);
		bool addMouseDownListener(MouseClickDelegate*);
		bool addKeyClickListener(KeyClickDelegate*);
		bool addKeyUpListener(KeyClickDelegate*);
		bool addKeyDownListener(KeyClickDelegate*);

		bool delMouseMoveListener(MouseMoveDelegate*);
		bool delMouseClickListener(MouseClickDelegate*);
		bool delMouseUpListener(MouseClickDelegate*);
		bool delMouseDownListener(MouseClickDelegate*);
		bool delKeyClickListener(KeyClickDelegate*);
		bool delKeyUpListener(KeyClickDelegate*);
		bool delKeyDownListener(KeyClickDelegate*);


		void fireEvent(Event*);

	private:
		void sendEvents();
	};

	struct MouseMoveEvent {
	public:
		Point point;
		bool dragging;

		MouseMoveEvent();
		MouseMoveEvent(Point point, bool dragging);
	};

	struct MouseClickEvent {
	public:
		Point point;
		bool down;
		__int8 scan_code;

		MouseClickEvent();
		MouseClickEvent(Point point, bool down, __int8 scan_code);
	};

	struct KeyClickEvent {
		bool down;
		__int16 scan_code;

		KeyClickEvent();
		KeyClickEvent(bool down, __int16 scan_code);
	};
}