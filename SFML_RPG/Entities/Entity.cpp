#include "pch.h"
#include "Entity.h"

Entity::Entity()
{
	_shape.setSize(sf::Vector2f(50.0f, 50.0f));
	_shape.setFillColor(sf::Color::White);
	_movementSpeed = 100.0f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float xDir, const float yDir)
{
	_shape.move(xDir * dt * _movementSpeed, yDir * dt * _movementSpeed);
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* renderTarget)
{
	renderTarget->draw(_shape);
}
