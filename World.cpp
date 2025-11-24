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

void World::checkEvents(const sf::Event& event)
{
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

