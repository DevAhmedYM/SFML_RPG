#ifndef GAME_H
#define GAME_H

#include "States/GameState.h"

class Game
{
private:
	sf::RenderWindow* _renderWindow;
	sf::Event _sfEvent;

	sf::Clock _dtClock;
	float _dt;

	std::stack<State*> _states;

private:
	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

public:
	void endApplication();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif

