#pragma once
#include "Camera.h"
#include "Point.h"

namespace GameEngine
{
	class FollowingCamera : public Camera
	{
	public:
		FollowingCamera(Entity* entity);
		FollowingCamera(Entity* entity, const Point& offset);
		virtual ~FollowingCamera();

		virtual void Update() override;

		Point offset;

	protected:
		Entity* target = nullptr;
	};
}

