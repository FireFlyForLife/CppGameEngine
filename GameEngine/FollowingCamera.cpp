#include "FollowingCamera.h"



namespace GameEngine
{
	FollowingCamera::FollowingCamera(std::weak_ptr<Entity> entity)
		: Camera(entity.lock()->x(), entity.lock()->y()), target(entity), offset(entity.lock()->x(), entity.lock()->y())
	{
	}

	FollowingCamera::FollowingCamera(std::weak_ptr<Entity> entity, const Point & offset)
		: Camera(entity.lock()->x(), entity.lock()->y()), target(entity), offset(offset)
	{
	}

	FollowingCamera::~FollowingCamera()
	{
	}

	void FollowingCamera::Update()
	{
		if (!target.expired()) {
			std::shared_ptr<Entity> ptr = target.lock();

			if(moveX)
				x(ptr->x() - offset.x);
			if(moveY)
				y(ptr->y() - offset.y);
		}
	}
}
