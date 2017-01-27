#include "GameObject.h"

namespace GameEngine {
	GameObject::GameObject() : texture(0)
	{
	}

	GameObject::GameObject(int texture_id) : texture(texture_id)
	{
	}

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
	SDL_Surface* GameObject::getFrame(SDL_Renderer * renderer)
	{
		return Global::texture_manager.getDefaultSurface();
	}

	int GameObject::getTexture() {
		return texture;
	}
	void GameObject::setTexture(int id) {
		texture = id;
	}
}