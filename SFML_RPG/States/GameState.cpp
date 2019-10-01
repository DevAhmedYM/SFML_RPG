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
}

void GameState::render(sf::RenderTarget* renderTarget)
{
}

void GameState::endState()
{
	std::cout << "Ending State\n";
}
