#pragma once
#include "Camera.h"
#include "Point.h"

namespace GameEngine
{
	class FollowingCamera : public Camera
	{
	public:
		FollowingCamera(std::weak_ptr<Entity> entity);
		FollowingCamera(std::weak_ptr<Entity> eniity, const Point& offset);
		virtual ~FollowingCamera();

		virtual void Update() override;

		Point offset;

		bool moveX = true;
		bool moveY = true;

	protected:
		std::weak_ptr<Entity> target;
	};
}

