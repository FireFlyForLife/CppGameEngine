#include "MoveableCamera.h"



namespace GameEngine
{
	MoveableCamera::MoveableCamera(int x, int y) : Camera(x, y)
	{
		keyDownListeners.add([this](KeyClickArgs * args, int unused) {OnButtonDown(args, unused); });
	}


	MoveableCamera::~MoveableCamera()
	{
	}

	void MoveableCamera::OnButtonDown(KeyClickArgs * args, int unused)
	{
		int speed = 4;

		switch (args->scan_code)
		{
		case SDL_SCANCODE_LEFT:
			x(x() - speed);
			break;
		case SDL_SCANCODE_RIGHT:
			x(x() + speed);
			break;
		case SDL_SCANCODE_UP:
			y(y() - speed);
			break;
		case SDL_SCANCODE_DOWN:
			y(y() + speed);
			break;
		}
	}
}
