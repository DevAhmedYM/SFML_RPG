#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game
{
private:
	sf::RenderWindow* _renderWindow;
	sf::Event _sfEvent;

	sf::Clock _dtClock;
	float _dt;

private:
	void initWindow();

public:
	Game();
	virtual ~Game();

public:
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif

