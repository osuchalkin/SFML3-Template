#pragma once

#include <SFML/Graphics.hpp> 

#include "World.h"


class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void showInformation(sf::RenderWindow& window);

private:
	sf::RenderWindow mWindow;
	sf::Image mIcon;
	GameState mGameState;
	sf::Font mFont;
	std::unique_ptr<World> mWorld;
};
