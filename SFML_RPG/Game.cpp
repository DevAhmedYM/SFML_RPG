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

void Game::initStates()
{
	_states.push(new GameState(_renderWindow));
}

Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete _renderWindow;

	while (!_states.empty())
	{
		auto& state = _states.top();
		delete state;
		_states.pop();
	}
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

	if (!_states.empty())
	{
		_states.top()->update();
	}
}

void Game::render()
{
	_renderWindow->clear();

	if (!_states.empty())
	{
		_states.top()->render();
	}

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
