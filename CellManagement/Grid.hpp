#pragma once

#include "Cell.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Grid
{
public:
	Grid();

	~Grid();

	int findAliveNeighbors(Cell* cell);

	void createImage();

	void draw(sf::RenderWindow& window);

	void updateConway();

	std::vector<std::vector<bool>> getState();

	void setState(std::vector<bool> locationValues);

	void switchCell(int x, int y);

protected:
	const static int GRID_WIDTH = 1024;
	const static int GRID_HEIGHT = 1024;
	const static int COLS = GRID_WIDTH;
	const static int ROWS = GRID_HEIGHT;

	Cell** m_Cells;
	Cell** m_NextCells;

	sf::Image m_Image;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};