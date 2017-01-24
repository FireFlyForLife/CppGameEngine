#include "Entity.h"

namespace GameEngine {

	Entity::Entity() 
		: _x(0.0f), _y(0.0f), texture(-1)
	{
	}

	Entity::Entity(int x, int y, int texture) 
		: _x(x), _y(y), texture(texture)
	{
	}

	Entity::Entity(int x, int y, std::string texture_name) 
		: Entity(x, y, Global::texture_manager.getID(texture_name))
	{
	}

	Entity::~Entity()
	{
		delete collider;
	}

	int Entity::getTexture() {
		return texture;
	}
	void Entity::setTexture(int id) {
		texture = id;
	}

	Shape * Entity::getCollider()
	{
		return collider;
	}

	void Entity::setCollider(Shape * newCollider)
	{
		delete collider;
		collider = newCollider;
	}

	float Entity::x()
	{
		return _x;
	}

	void Entity::x(float x)
	{
		_x = x;
	}

	float Entity::y()
	{
		return _y;
	}

	void Entity::y(float y)
	{
		_y = y;
	}

}