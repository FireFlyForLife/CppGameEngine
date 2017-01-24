#include "Camera.h"



namespace GameEngine
{
	Camera::Camera(int x, int y) : Entity(x, y)
	{
	}


	Camera::~Camera()
	{
	}

	float Camera::getZoom()
	{
		return zoom;
	}

	void Camera::setZoom(float zoom)
	{
		this->zoom = zoom;
	}
}
