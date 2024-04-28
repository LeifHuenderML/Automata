
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

#include "Grid.hpp"
#include "HighGrid.hpp"
#include "RainbowGrid.hpp"

class GameLoop {
public:
	void eventHandler(sf::RenderWindow& window, Grid* grid, bool player);
	void eventHandler(sf::RenderWindow& window, HighGrid* grid, bool player);
	void eventHandler(sf::RenderWindow& window, RainbowGrid* grid, bool player);
	void gameLoop(std::string gameMode, bool player);
};

