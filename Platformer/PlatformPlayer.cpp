#include "PlatformPlayer.h"



namespace GameEngine
{
	PlatformPlayer::PlatformPlayer(float x, float y, const Animation& ani)
		: PhysicsPlayer(x, y, "player"), ani_controller(this, ani)
	{
		mouseDownListeners.add([this](MouseClickArgs* args, int id) { OnMouseDown(args, id); });
		mouseMoveListeners.add([this](MouseMoveArgs* args, int id) { OnMouseMove(args, id); });
		mouseUpListeners.add([this](MouseClickArgs* args, int id) { OnMouseUp(args, id); });

		ani_controller.enabled = false;
		tag = "player";
	}


	PlatformPlayer::~PlatformPlayer()
	{
	}

	void PlatformPlayer::Update()
	{
		if (crosshair.expired()) {
			Entity* ch = new Entity(0, 0, "crosshair");
			crosshair = getWorld()->UI_elements->add(ch);
		}

		if (health <= 0) {
			ani_controller.enabled = true;
		}

		ani_controller.Update();
	}

	void PlatformPlayer::OnMouseDown(MouseClickArgs * args, int)
	{
		if (args->scan_code == 1) {
			GunShot* shot = new GunShot(x(), y(), Vector2(args->point.x, args->point.y));
			getWorld()->entity_list->add(shot);
		}
		else if (args->scan_code == 3) {
			crosshair.lock()->enabled = false;
		}
			
	}

	void PlatformPlayer::OnMouseMove(MouseMoveArgs * args, int)
	{
		if (!crosshair.expired()) {
			ent_ptr ptr = crosshair.lock();
			ptr->x(args->point.x);
			ptr->y(args->point.y);
		}
	}

	void PlatformPlayer::OnMouseUp(MouseClickArgs * args, int)
	{
		if (args->scan_code == 3) {
			crosshair.lock()->enabled = true;
		}
	}

	int PlatformPlayer::getHealth()
	{
		return health;
	}
	void PlatformPlayer::setHealth(int amount)
	{
		health = amount;
	}
	void PlatformPlayer::addHealth(int amount)
	{
		health += amount;
	}


}
