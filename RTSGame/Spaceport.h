#pragma once
#include "Building.h"
#include "AnimationController.h"
#include "UI_element.h"

namespace GameEngine
{
	class Spaceport : public Building
	{
	public:
		Spaceport(float x, float y, Animation ani, UI_element* ui);
		~Spaceport();

		virtual void Update() override;

		int getResources();
		void addResources(int);

	protected:
		AnimationController ani_controller;
		UI_element* ui = nullptr;

		int resource = 0;
	};
}

