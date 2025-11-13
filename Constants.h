#pragma once

#include<SFML/Graphics.hpp>
#include<string>

// Game's name
inline std::string GAME_NAME = "SFML Game";

// FPS
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

// Window dimensions
constexpr unsigned int SCREEN_WIDTH = 800;
constexpr unsigned int SCREEN_HEIGHT = 600;

// Colors
const sf::Color BCG_COLOR(sf::Color::Blue);

// resources
const std::string ICON_IMAGE = "assets/textures/wheel.png";
const std::string TTF = "data/fonts/Roboto-Regular.ttf";