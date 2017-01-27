#include "AnimationController.h"



namespace GameEngine
{
	AnimationController::AnimationController(GameObject* target, const Animation& animation) 
		: target(target), ani(animation)
	{
	}

	AnimationController::~AnimationController()
	{
	}

	void AnimationController::Update()
	{
		if (!enabled)
			return;

		Uint32 time = SDL_GetTicks();
		if (lastChange + ani.delay < time) {
			if (index >= ani.ids.size()) {
				if (loop)
					target->setTexture(ani.frame(0));
				else
					target->setTexture(-1);
			} else
				target->setTexture(ani.frame(index++));
			lastChange = time;
		}
	}
}
