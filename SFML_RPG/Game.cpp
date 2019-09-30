#include "Game.h"

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode windowBounds(800, 600);
	unsigned frameRateLimit = 120;
	bool verticalSyncEnabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> frameRateLimit;
		ifs >> verticalSyncEnabled;
	}

	ifs.close();

	_renderWindow = new sf::RenderWindow(windowBounds, title);
	_renderWindow->setFramerateLimit(frameRateLimit);
	_renderWindow->setVerticalSyncEnabled(verticalSyncEnabled);
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
