
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

#include "../CellManagement/Grid.hpp"
#include "../CellManagement/HighGrid.hpp"
#include "../CellManagement/RainbowGrid.hpp"
#include "../rlEngine/interface.hpp"

class GameLoop {
public:
	void eventHandler(sf::RenderWindow& window, Grid* grid, int player);
	void eventHandler(sf::RenderWindow& window, HighGrid* grid, int player);
	void eventHandler(sf::RenderWindow& window, RainbowGrid* grid, int player);
	void gameLoop(std::string gameMode, int player);
};

