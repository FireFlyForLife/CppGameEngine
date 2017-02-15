#include "GunShot.h"

namespace GameEngine
{
	GunShot::GunShot(float x, float y, const Vector2& target, SDL_Color color, float speed, int damage)
		: Entity(x, y), target(target), color(color), speed(speed), damage(damage)
	{
		renderSelf = true;
	}

	GunShot::~GunShot()
	{
	}

	void GunShot::Update()
	{
		distance += speed * Global::deltaTime();
	}

	void GunShot::LateUpdate()
	{
		if (distance > maxDistance) {
			enabled = false;
			return;
		}

		Rectangle point(x()-1, y()-1, 3.f, 3.f);
		std::vector<ent_ptr> entities = getWorld()->entity_list->getInside(point);
		for each (ent_ptr entity in entities)
		{
			std::shared_ptr<Character> enemy = std::dynamic_pointer_cast<Character>(entity);
			if (enemy != nullptr) {
				enemy->addHealth(-damage);
				enabled = false;
				continue;
			}

			std::shared_ptr<PlatformPlayer> player = std::dynamic_pointer_cast<PlatformPlayer>(entity);
			if (player != nullptr) {
				player->addHealth(-damage);
				enabled = false;
				continue;
			}
		}
	}

	SDL_Surface * GunShot::getFrame(SDL_Renderer * renderer)
	{
		Uint8 r, g, b, a;
		SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		float x1 = x();
		float y1 = y();
		Vector2 start(x1, y1);
		Vector2 dir = (target - start).normalized();
		Vector2 end = start + dir * distance;
		SDL_RenderDrawLine(renderer, x1, y1, end.x, end.y);

		SDL_SetRenderDrawColor(renderer, r, g, b, a);

		return nullptr;
	}

	float GunShot::getTraveledDistance()
	{
		return distance;
	}
}
