#pragma once

#include "Grid.hpp"
#include "RainbowCell.hpp"

class RainbowGrid : public Grid {
public:
	RainbowGrid();
	~RainbowGrid();
	std::vector<sf::Uint8> getImageData();
	void draw(sf::RenderWindow& window);
	sf::Color averageColor(RainbowCell* cell);
	int findAliveNeighbors(RainbowCell* cell);
	void updateRainbow();
	std::vector<std::vector<bool>> getState();
	void setState(std::vector<bool> locationValues);
	void switchCell(int x, int y);

protected:
	const static int GRID_WIDTH = 1024;
	const static int GRID_HEIGHT = 1024;
	const static int COLS = GRID_WIDTH;
	const static int ROWS = GRID_HEIGHT;

	RainbowCell** m_Cells;
	RainbowCell** m_NextCells;

	sf::Image m_Image;
	std::vector<sf::Uint8> m_Pixels;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
};