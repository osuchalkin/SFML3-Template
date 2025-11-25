#pragma once
#include <SFML/Graphics.hpp> 

class Game;
class State;

class GlobalState
{
protected:
    Game& mGame;
public:
    GlobalState(Game& game) : mGame(game) {}
    virtual ~GlobalState() = default;
    // Input processing
    virtual void handleInput(const sf::Event& event) = 0;
    // Updating the logic
    virtual void update(sf::Time deltaTime) = 0;
    // Drawing
    virtual void render(sf::RenderWindow& window) = 0;
};

/******************  GameTitle  *********************************************/

class GameTitle : public GlobalState
{
private:
    sf::Font mFont;
    sf::Text mTitle;
public:
    GameTitle(Game& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

/******************  GameStateManager  *********************************************/

class GameStateManager : public GlobalState
{
private:
    std::vector<std::unique_ptr<State>> mGameStack;
public:
    GameStateManager(Game& game);
    void handleInput(const sf::Event& event) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void pushState(std::unique_ptr<State> newState);
    void popState();
};

