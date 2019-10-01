#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "./Entities/Entity.h"

class GameState : public State
{
private:
	Entity _player;

protected:
	virtual void initKeyBinds() override;

public:
	GameState(sf::RenderWindow* renderWindow, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

public:
	virtual void updateInput(const float& dt) override;
	virtual void update(const float& dt) override;
	virtual void render(sf::RenderTarget* renderTarget = nullptr) override;	
	virtual void endState() override;	
};

#endif

