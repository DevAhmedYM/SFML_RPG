#ifndef STATE_H
#define STATE_H

class State
{
protected:
	sf::RenderWindow* _renderWindow;
	std::vector<sf::Texture> _textures;
	bool _quit;

public:
	State(sf::RenderWindow* renderWindow);
	virtual ~State();

public:
	const bool& getQuit() const;
	virtual void checkForQuit();

public:
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* renderTarget = nullptr) = 0;
	virtual void endState() = 0;
};

#endif

