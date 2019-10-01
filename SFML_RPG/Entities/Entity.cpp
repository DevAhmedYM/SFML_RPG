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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(dt, -1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(dt, 1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(dt, 0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(dt, 0.0f, 1.0f);
}

void Entity::render(sf::RenderTarget* renderTarget)
{
	renderTarget->draw(_shape);
}
