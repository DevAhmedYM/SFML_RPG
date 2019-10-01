#ifndef STATE_H
#define STATE_H

class State
{
protected:
	sf::RenderWindow* _renderWindow;
	std::vector<sf::Texture> _textures;
	std::map<std::string, int>* _supportedKeys;
	std::map<std::string, int> _keyBinds;
	bool _quit;

protected:
	virtual void initKeyBinds() = 0;

public:
	State(sf::RenderWindow* renderWindow, std::map<std::string, int>* supportedKeys);
	virtual ~State();

public:
	const bool& getQuit() const;
	virtual void checkForQuit();

public:
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* renderTarget = nullptr) = 0;
	virtual void endState() = 0;
};

#endif

