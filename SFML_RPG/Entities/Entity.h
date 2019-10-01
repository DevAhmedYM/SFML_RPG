#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
private:
	

protected:
	sf::RectangleShape _shape;
	float _movementSpeed;

public:
	Entity();
	virtual ~Entity();

public:
	virtual void move(const float& dt, const float xDir, const float yDir);

public:
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* renderTarget = nullptr);
};

#endif
