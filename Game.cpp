#include "Constants.h"
#include "Game.h"


Game::Game() :
	mWindow(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), GAME_NAME, sf::Style::Close),
	mIcon(),
	mWorld(std::make_unique<World>())
{
	// set window icon AND check assets directory
	if (!mIcon.loadFromFile(ICON_IMAGE))
		throw std::runtime_error("Failed to load png-file from data.");
	mWindow.setIcon(mIcon);

	// set mouse position in window's center
	sf::Vector2i windowCenter(mWindow.getSize() / 2u);
	sf::Mouse::setPosition(windowCenter, mWindow);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			processEvents();
			update(TIME_PER_FRAME);
		}
		render();
	}
}

void Game::processEvents()
{
	while (const std::optional event = mWindow.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			mWindow.close();

		// pass event to world
		mWorld->checkEvents(mWindow, *event);
	}
}

void Game::update(sf::Time deltaTime)
{
	mWorld->update(deltaTime);
}

void Game::render()
{
	mWindow.clear(BCG_COLOR);

	mWorld->render(mWindow);

	mWindow.display();
}
