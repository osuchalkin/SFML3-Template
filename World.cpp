#include "World.h"

#include <SFML/Graphics.hpp>
#include <iostream>     // for debugging

#include "Constants.h"


World::World() 
{
	generateWorld();
}

void World::generateWorld()
{
}

void World::checkEvents(sf::RenderWindow& window, const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
        {
            window.close();
        }
        if (keyPressed->scancode == sf::Keyboard::Scan::Up)
        {
            std::cout << "Up key pressed\n";
        }
    }

    if (const auto* KeyReleased = event.getIf<sf::Event::KeyReleased>())
    {
        if (KeyReleased->scancode == sf::Keyboard::Scan::Up)
        {
            std::cout << "Up key released\n";
        }
    }

    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            std::cout << "Left mouse button pressed at ("
                << mouseButtonPressed->position.x << ", "
                << mouseButtonPressed->position.y << ")\n";
        }
    }
}

void World::update(sf::Time deltaTime)
{
	
}

void World::render(sf::RenderWindow& window)
{
	
}

