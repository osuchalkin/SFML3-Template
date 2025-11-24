#include "GlobalState.h"
#include "Game.h"
#include "State.h"

#include <iostream>

/******************  GameTitle  *********************************************/

GameTitle::GameTitle(Game& game) :
    GlobalState(game)
{
    std::cout << "Set Title\n";
}

void GameTitle::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        mGame.changeState(std::make_unique<GameStateManager>(mGame));
        
        std::cout << "Exit from Title\n";
    }
}

void GameTitle::update(sf::Time deltaTime)
{
}

void GameTitle::render(sf::RenderWindow& window)
{
    // Draw the background and title text.
}

/******************  GameStateManager  *********************************************/

GameStateManager::GameStateManager(Game& game) :
    GlobalState(game),
    mGameStack()
{
    std::cout << "Set GameStateManager\n";
    mGameStack.push_back(std::move(std::make_unique<PlayingState>(*this)));
}

void GameStateManager::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            std::cout << "Exit from GameStateManager\n";
            mGame.changeState(std::make_unique<GameTitle>(mGame));
        }
    }
    if (mGameStack.empty()) return;
    mGameStack.back()->handleInput(event);
}

void GameStateManager::update(sf::Time deltaTime)
{
    if (mGameStack.empty()) return;
    mGameStack.back()->update(deltaTime);
}

void GameStateManager::render(sf::RenderWindow& window)
{
    if (mGameStack.empty()) return;
    
    // drawing current state
    //mGameStack.back()->render(window);
    
    // drawing all stack
    for (const auto& state : mGameStack)
    {
        state->render(window);
    }
}

void GameStateManager::pushState(std::unique_ptr<State> newState)
{
    mGameStack.push_back(std::move(newState));
}

void GameStateManager::popState()
{
    if (!mGameStack.empty())
    {
        mGameStack.pop_back();
    }
}