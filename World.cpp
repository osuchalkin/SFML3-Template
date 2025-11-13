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
        // keyPressed теперь является указателем на структуру sf::Event::KeyPressed
        if (keyPressed->scancode == sf::Keyboard::Scan::Q)
        {
            window.close();
        }
        if (keyPressed->scancode == sf::Keyboard::Scan::I)
        {
            std::cout << "I key pressed for Info\n";
        }
    }
    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        // mouseButtonPressed теперь является указателем на структуру sf::Event::MouseButtonPressed
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

