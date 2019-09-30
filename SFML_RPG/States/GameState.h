#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow* renderWindow);
	virtual ~GameState();

public:
	virtual void endState() override;
	virtual void update(const float& dt) override;
	virtual void render(sf::RenderTarget* renderTarget = nullptr) override;
};

#endif

