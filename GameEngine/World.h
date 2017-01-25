#pragma once
#include <vector>
#include "TileMap.h"
#include "EntityList.h"
#include "Camera.h"

namespace GameEngine {
	class World
	{
	public:
		TileMap* map;
		EntityList* entity_list;
		EntityList* UI_elements;
		Camera* camera;

	public:
		World();
		~World();

		//TODO: Add more convenience methods
		virtual bool blocking(const Point&);
		
		Point toScreenSpace(const Point&);
		Point toWorldSpace(const Point&);
	};
}