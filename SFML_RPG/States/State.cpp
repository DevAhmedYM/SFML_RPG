#include "pch.h"
#include "State.h"

State::State(sf::RenderWindow* renderWindow)
	: _renderWindow(renderWindow)
	, _quit(false)
{
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return _quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		_quit = true;
	}
}
