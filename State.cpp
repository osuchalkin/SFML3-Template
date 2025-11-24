#include "State.h"
#include "GlobalState.h"


/******************  PlayingState *********************************************/

PlayingState::PlayingState(GameStateManager& game) :
    State(game),
    mWorld(std::make_unique<World>())
{
    std::cout << "Create PlayingState\n";
}

void PlayingState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scan::Up)
        {
            std::cout << "Up key pressed\n";
        }
        else if (keyPressed->scancode == sf::Keyboard::Scan::I)
        {
            std::cout << "I key pressed for info\n";
            std::cout << "Go to PauseState\n";

            mGame.pushState(std::make_unique<PauseState>(mGame));
        }
    }

    if (const auto* KeyReleased = event.getIf<sf::Event::KeyReleased>())
    {
        if (KeyReleased->scancode == sf::Keyboard::Scan::Up)
        {
            std::cout << "Up key released\n";
        }
    }

    // if need it
    mWorld->checkEvents(event);
};

void PlayingState::update(sf::Time deltaTime)
{
    mWorld->update(deltaTime); // Игра обновляется только здесь
};

void PlayingState::render(sf::RenderWindow& window)
{
    mWorld->render(window);
};


/******************  PauseState *********************************************/

PauseState::PauseState(GameStateManager& game) :
    State(game)
{
}

void PauseState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        mGame.popState();
        std::cout << "Exit from PauseState\n";
    }
}

void PauseState::update(sf::Time deltaTime)
{
}

void PauseState::render(sf::RenderWindow& window)
{
    // Нарисовать фон и инфо-текст.
}