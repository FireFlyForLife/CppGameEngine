#include "FollowingCamera.h"



namespace GameEngine
{
	FollowingCamera::FollowingCamera(Entity* entity)
		: Camera(entity->x(), entity->y()), target(entity), offset(entity->x(), entity->y())
	{
	}

	FollowingCamera::FollowingCamera(Entity * entity, const Point & offset)
		: Camera(entity->x(), entity->y()), target(entity), offset(offset)
	{
	}

	FollowingCamera::~FollowingCamera()
	{
	}

	void FollowingCamera::Update()
	{
		if (target != nullptr) {
			x(target->x() - offset.x);
			y(target->y() - offset.y);
		}
	}
}
