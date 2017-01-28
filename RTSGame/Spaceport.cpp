#include "Spaceport.h"



namespace GameEngine
{
	Spaceport::Spaceport(float x, float y, Animation ani, UI_element* ui)
		: Building(x, y, "space_port"), ani_controller(this, ani), ui(ui)
	{
		setHealth(500);
		ani_controller.enabled = false;
		ui->enabled = false;
	}


	Spaceport::~Spaceport()
	{
	}

	void Spaceport::Update()
	{
		if (getHealth() <= 0) {
			ani_controller.enabled = true;
			ui->enabled = true;
		}

		ani_controller.Update();

		if (getTexture() == -1)
			enabled = false;
	}
	int Spaceport::getResources()
	{
		return resource;
	}
	void Spaceport::addResources(int add)
	{
		resource += add;
	}
}
