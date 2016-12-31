#include "Player.h"



namespace GameEngine
{
	Player::Player(float x, float y, std::string texture_name)
		: Entity(x, y, Global::texture_manager.getID(texture_name))
	{
		keyDownListeners.add([this](KeyClickArgs * args, int unused) {OnButtonDown(args, unused); });
	}


	Player::~Player()
	{
	}

	void Player::OnButtonDown(KeyClickArgs * args, int unused)
	{
		switch (args->scan_code)
		{
		case SDL_SCANCODE_A:
			x(x() - speed);
			break;
		case SDL_SCANCODE_D:
			x(x() + speed);
			break;
		case SDL_SCANCODE_W:
			y(y() - speed);
			break;
		case SDL_SCANCODE_S:
			y(y() + speed);
			break;
		}
	}
}
