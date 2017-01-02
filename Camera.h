#pragma once
#include "Entity.h"


namespace GameEngine
{
	class Camera : public Entity
	{
	public:
		Camera(int x, int y);
		~Camera();

		float getZoom();
		void setZoom(float);
	protected:
		float zoom = 1;
	};
}

