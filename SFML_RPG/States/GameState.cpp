#include "pch.h"
#include "GameState.h"

void GameState::initKeyBinds()
{
	_keyBinds.emplace("MOVE_LEFT", _supportedKeys->at("A"));
	_keyBinds.emplace("MOVE_RIGHT", _supportedKeys->at("D"));
	_keyBinds.emplace("MOVE_UP", _supportedKeys->at("W"));
	_keyBinds.emplace("MOVE_DOWN", _supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* renderWindow, std::map<std::string, int>* supportedKeys)
	: State(renderWindow, supportedKeys)
{
	initKeyBinds();
}

GameState::~GameState()
{
}

void GameState::updateInput(const float& dt)
{
	checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keyBinds.at("MOVE_LEFT"))))
		_player.move(dt, -1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keyBinds.at("MOVE_RIGHT"))))
		_player.move(dt, 1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keyBinds.at("MOVE_UP"))))
		_player.move(dt, 0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keyBinds.at("MOVE_DOWN"))))
		_player.move(dt, 0.0f, 1.0f);
}

void GameState::update(const float& dt)
{
	updateInput(dt);
	_player.update(dt);
}

void GameState::render(sf::RenderTarget* renderTarget)
{
	if (!renderTarget)
		renderTarget = _renderWindow;

	_player.render(renderTarget);
}

void GameState::endState()
{
	std::cout << "Ending State\n";
}
