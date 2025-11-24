#pragma once

#include <SFML/Graphics.hpp> 

#include "GlobalState.h"

class Game
{
public:
	Game();
	void run();
	void changeState(std::unique_ptr<GlobalState> newState);
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
private:
	sf::RenderWindow mWindow;
	sf::Image mIcon;
	std::unique_ptr<GlobalState> mCurrentGlobalState;
};
