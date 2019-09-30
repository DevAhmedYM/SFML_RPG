#include "Game.h"

void Game::initWindow()
{
	_renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML RPG");
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete _renderWindow;
}

void Game::updateDt()
{
	_dt = _dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (_renderWindow->pollEvent(_sfEvent))
	{
		if (_sfEvent.type == sf::Event::Closed)
			_renderWindow->close();
	}
}

void Game::update()
{
	updateSFMLEvents();
}

void Game::render()
{
	_renderWindow->clear();
	_renderWindow->display();
}

void Game::run()
{
	while (_renderWindow->isOpen())
	{
		updateDt();
		update();
		render();
	}
}
