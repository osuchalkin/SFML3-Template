#include "Constants.h"
#include "Game.h"


Game::Game() :
	mWindow(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), GAME_NAME, sf::Style::Close),
	mIcon(),
	mGameState(GameState::Playing),
	mFont(),
	mWorld(std::make_unique<World>())
{
	// set window icon AND check assets directory
	if (!mIcon.loadFromFile(ICON_IMAGE))
		throw std::runtime_error("Failed to load png-file from data.");
	mWindow.setIcon(mIcon);

	// set mouse position in window's center
	sf::Vector2i windowCenter(mWindow.getSize() / 2u);
	sf::Mouse::setPosition(windowCenter, mWindow);

	//set Font
	if (!mFont.openFromFile(TTF))
		throw std::runtime_error("Failed to load ttf-file from /assets.");
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
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				mWindow.close();
			else if (keyPressed->scancode == sf::Keyboard::Scancode::I)
			{
				mGameState = GameState::Pause;
				showInformation(mWindow);
			}
			
		}
		// pass event to world
		if (mGameState == GameState::Playing)
		{
			mWorld->checkEvents(mWindow, *event);
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	if (mGameState == GameState::Playing)
	{
		mWorld->update(deltaTime);
	}
}

void Game::render()
{
	mWindow.clear(BCG_COLOR);

	if (mGameState == GameState::Playing)
	{
		mWorld->render(mWindow);
	}

	mWindow.display();
}

void Game::showInformation(sf::RenderWindow& window)
{
	sf::Text title(mFont, "About Game", 50);
	title.setStyle(sf::Text::Bold);
	sf::FloatRect textRect = title.getLocalBounds();
	title.setOrigin(textRect.size / 2.0f);
	title.setPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 6 });
	title.setFillColor(TEXT_COLOR);

	std::vector<sf::Text> infoes;

	std::vector<std::string> messages = {
		"Game",
		"",
		"",
		
		"I used the algorithm suggested by ...:",
		"https://algorithm.com",
		"",
		
		"Esc - exit the game and close the window",
		"I - short info about this game",
		"",
		
		"Programmed in C++ with SFML 3 library.",
		"(c) Oleh Suchalkin  2025"
	};

	for (size_t i = 0; i < messages.size(); ++i)
	{
		sf::Text text(mFont, messages[i], 20);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.size / 2.0f);
		text.setPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 + static_cast<float>(i) * 30 });
		text.setFillColor(TEXT_COLOR);

		infoes.push_back(text);
	}

	bool finished = false;

	while (!finished)
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				finished = true;
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				finished = true;
				mGameState = GameState::Playing;
			}
		}

		window.clear(BCG_COLOR);
		window.draw(title);
		for (const auto& text : infoes)
			window.draw(text);
		window.display();
	}
}