#include "GunShot.h"

namespace GameEngine
{
	GunShot::GunShot(float x, float y, const Vector2& dir, float speed, SDL_Color color, int damage)
		: Entity(x, y), dir(dir.normalized()), color(color), speed(speed), damage(damage)
	{
		renderSelf = true;
	}

	GunShot::~GunShot()
	{
	}

	void GunShot::Update()
	{
		distance += speed * (Global::deltaTime() / 1000.f);
	}

	void GunShot::LateUpdate()
	{
		if (distance > maxDistance) {
			enabled = false;
			callUpdate = false;
			return;
		}

		Rectangle point(x() + dir.x * distance - 1, y() + dir.y * distance - 1, 3.f, 3.f);
		std::vector<ent_ptr> entities = getWorld()->entity_list->getInside(point);
		for each (ent_ptr entity in entities)
		{
			std::shared_ptr<Character> enemy = std::dynamic_pointer_cast<Character>(entity);
			if (enemy != nullptr) {
				enemy->addHealth(-damage);
				enabled = false;
				callUpdate = false;
				continue;
			}

			std::shared_ptr<PlatformPlayer> player = std::dynamic_pointer_cast<PlatformPlayer>(entity);
			if (player != nullptr) {
				player->addHealth(-damage);
				enabled = false;
				callUpdate = false;
				continue;
			}

			if ((entity->physics_type == STATIC || entity->physics_type == DYNAMIC) && entity->getCollider() != nullptr) {
				//TODO: Spawn explosion

				enabled = false;
				callUpdate = false;
				continue;
			}
		}
	}

	SDL_Surface * GunShot::getFrame(SDL_Renderer * renderer)
	{
		Uint8 r, g, b, a;
		SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		World* w = getWorld();

		Vector2 offset;
		if (!w->camera.expired()) {
			ent_ptr camera = w->camera.lock();
			offset.x = camera->x();
			offset.y = camera->y();
		}

		float x1 = x();
		float y1 = y();
		Vector2 start(x1, y1);
		Vector2 end = start + dir * distance;
		Point s = w->toScreenSpace({ start.x, start.y });
		Point e = w->toScreenSpace({ end.x, end.y });
		SDL_RenderDrawLine(renderer, s.x, s.y, e.x, e.y);

		SDL_SetRenderDrawColor(renderer, r, g, b, a);

		return nullptr;
	}

	float GunShot::getTraveledDistance()
	{
		return distance;
	}
}
