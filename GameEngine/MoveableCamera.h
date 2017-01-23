#pragma once
#include "Camera.h"
#include "Input.h"

namespace GameEngine
{
	class MoveableCamera : public Camera
	{
	public:
		MoveableCamera(int x, int y);
		~MoveableCamera();

	protected:
		virtual void OnButtonDown(KeyClickArgs*, int);
	};

}
