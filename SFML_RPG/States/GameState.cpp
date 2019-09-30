#include "GameState.h"

GameState::GameState(sf::RenderWindow* renderWindow)
	: State(renderWindow)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	std::cout << "Hello from GameState\n";
}

void GameState::render(sf::RenderTarget* renderTarget)
{
}
