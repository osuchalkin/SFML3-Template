#pragma once

/******************  Game State Stack *********************************************/

#include <SFML/Graphics.hpp> 
#include <iostream>

#include "World.h"

class GameStateManager;

class State
{
protected:
    GameStateManager& mGame;
public:
    State(GameStateManager& game) : mGame(game) {}
    virtual ~State() = default;
    virtual void handleInput(const sf::Event& event) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

/******************  PlayingState *********************************************/

class PlayingState : public State
{
private:
    // Game World here
    std::unique_ptr<World> mWorld;
public:
    PlayingState(GameStateManager& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

/******************  PauseState *********************************************/

class PauseState : public State
{
    //...
public:
    PauseState(GameStateManager& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

