#pragma once

#include "HighCell.hpp"
#include "Grid.hpp"

class HighGrid : public Grid
{
public:
	HighGrid();

	~HighGrid();

	int findAliveNeighbors(HighCell* cell);

	void createImage();

	void draw(sf::RenderWindow& window);

	void updateHigh();

	std::vector<std::vector<bool>> getState();

	void setState(std::vector<bool> locationValues);

	void switchCell(int x, int y);

protected:
	const static int GRID_WIDTH = 1024;
	const static int GRID_HEIGHT = 1024;
	const static int COLS = GRID_WIDTH;
	const static int ROWS = GRID_HEIGHT;

	HighCell** m_Cells;
	HighCell** m_NextCells;

	sf::Image m_Image;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};