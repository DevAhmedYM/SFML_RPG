#include "pch.h"
#include "GameState.h"

GameState::GameState(sf::RenderWindow* renderWindow)
	: State(renderWindow)
{
}

GameState::~GameState()
{
}

void GameState::updateKeybinds(const float& dt)
{
	checkForQuit();
}

void GameState::update(const float& dt)
{
	updateKeybinds(dt);
	_player.update(dt);
}

void GameState::render(sf::RenderTarget* renderTarget)
{
	_player.render(renderTarget == nullptr ? _renderWindow : renderTarget);
}

void GameState::endState()
{
	std::cout << "Ending State\n";
}
