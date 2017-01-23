#include "GameObject.h"

namespace GameEngine {
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
	}
	World * GameObject::getWorld()
	{
		return living_world;
	}
	void GameObject::setWorld(World * newWorld)
	{
		//The old world pointer does not need to be deleted because it is not an 'owning' pointer.
		living_world = newWorld;
	}
}