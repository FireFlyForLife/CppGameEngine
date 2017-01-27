#pragma once
#include "GameObject.h"
#include "Globals.h"
#include <vector>
#include "Vector_Utils.h"
#include <numeric>
#include "Animation.h"

namespace GameEngine
{
	class AnimationController
	{
	public:
		AnimationController(GameObject*, const Animation& animation);
		virtual ~AnimationController();

		void Update();

		bool loop = false;
		bool enabled = true;
	protected:
		GameObject* target = nullptr;
		Animation ani;
		int index = 0;

	private:
		Uint32 lastChange = SDL_GetTicks();
	};

}
