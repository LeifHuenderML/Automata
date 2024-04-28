#include "RainbowGrid.hpp"

RainbowGrid::RainbowGrid()

{
	m_Image.create(GRID_WIDTH, GRID_HEIGHT);
	m_Texture.create(GRID_WIDTH+2, GRID_HEIGHT+2);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0.f, 0.f);

	m_Cells = new RainbowCell * [COLS + 2];
	m_NextCells = new RainbowCell * [COLS + 2];

	for (size_t i = 0; i < COLS + 2; i++)

	{
		m_Cells[i] = new RainbowCell[ROWS + 2];
		m_NextCells[i] = new RainbowCell[ROWS + 2];

		for (size_t j = 0; j < ROWS + 2; j++)

		{
			bool state = rand() % 2;
			m_Cells[i][j].setLocation(i, j);
			m_Cells[i][j].setState(state);
			m_NextCells[i][j].setLocation(i, j);
		}
	}
}

RainbowGrid::~RainbowGrid()

{
	for (size_t i = 0; i < COLS; ++i)

	{
		delete[] m_Cells[i];
		delete[] m_NextCells[i];
	}
	delete[] m_Cells;
	delete[] m_NextCells;
}

int RainbowGrid::findAliveNeighbors(RainbowCell* cell)
{
	sf::Vector2f location = cell->getLocation();
	int x = location.x;
	int y = location.y;

	RainbowCell neighbors[] = {
		m_Cells[x - 1][y - 1],
		m_Cells[x - 1][y],
		m_Cells[x - 1][y + 1],

		m_Cells[x][y - 1],
		m_Cells[x][y + 1],

		m_Cells[x + 1][y - 1],
		m_Cells[x + 1][y],
		m_Cells[x + 1][y + 1] };

	int aliveNeighbors = 0;

	for (int i = 0; i < 8; i++)

	{
		if (neighbors[i].getIsAlive())

		{
			aliveNeighbors++;
		}
	}
	return aliveNeighbors;
}

std::vector<sf::Uint8> RainbowGrid::getImageData()

{
	std::vector<sf::Color> colors;
	for (size_t i = 0; i < COLS + 2; i++)

	{
		for (size_t j = 0; j < ROWS + 2; j++) {
			if (m_Cells[i][j].getIsAlive()) {
				colors.push_back(m_Cells[i][j].getAliveColor());
			}
			else {
				colors.push_back(m_Cells[i][j].getDeadColor());
			}
		}
	}

	std::vector<sf::Uint8> pixels((GRID_WIDTH + 2) * (GRID_HEIGHT + 2) * 4);
	for (int i = 0; i < (GRID_WIDTH + 2) * (GRID_HEIGHT+ 2); i++)
	{
		//TODO: Change to the palette mapping...
		pixels[i*4] = colors[i].r;
		pixels[i*4 + 1] = colors[i].g;
		pixels[i*4 + 2] = colors[i].b;
		pixels[i*4 + 3] = 255;
	}

	return pixels;
}

void RainbowGrid::draw(sf::RenderWindow& window)

{
	m_Texture.update(m_Pixels.data());
	window.draw(m_Sprite);
}

std::vector<std::vector<bool>> RainbowGrid::getState()
{
	std::vector<std::vector<bool>> state(ROWS, std::vector<bool>(COLS, false));
	for (size_t i = 1; i < COLS + 1; i++)
	{
		for (size_t j = 1; j < ROWS + 1; j++)
		{
			state[i][j] = m_Cells[i][j].getIsAlive();
		}
	}

	return state;
}

void RainbowGrid::setState(std::vector<bool> locationValues)
{
	for (int i = 0; i < locationValues.size() - 1; i += 2)
	{
		m_Cells[i][i + 1].setState(1);
	}
}

void RainbowGrid::updateRainbow()

{
	for (size_t i = 1; i < COLS + 1; i++)

	{
		for (size_t j = 1; j < ROWS + 1; j++)

		{
			int aliveNeighbors = findAliveNeighbors(&m_Cells[i][j]);
			if (m_Cells[i][j].getIsAlive() && (aliveNeighbors < 2 || aliveNeighbors > 3))

			{
				m_NextCells[i][j].setState(0);
				continue;
			}
			if (!m_Cells[i][j].getIsAlive() && aliveNeighbors == 3)

			{
				m_NextCells[i][j].setState(1);
				m_NextCells[i][j].setAliveColor(averageColor(&m_Cells[i][j]));
				continue;
			}
			m_NextCells[i][j] = m_Cells[i][j];
		}
	}

	m_Pixels = getImageData();

	for (size_t i = 0; i < COLS + 2; ++i)

	{
		for (size_t j = 0; j < ROWS + 2; ++j)

		{
			m_Cells[i][j] = m_NextCells[i][j];
		}
	}
}

sf::Color RainbowGrid::averageColor(RainbowCell* cell) {
	sf::Vector2f location = cell->getLocation();
	int x = location.x;
	int y = location.y;

	sf::Color avgColor(0, 0, 0, 255);
	int R = 0;
	int G = 0;
	int B = 0;

	std::vector<sf::Color> colors;

	if (m_Cells[x - 1][y - 1].getIsAlive()) {
		colors.push_back(m_Cells[x - 1][y - 1].getAliveColor());
	}
	if (m_Cells[x - 1][y].getIsAlive()) {
		colors.push_back(m_Cells[x - 1][y].getAliveColor());
	}
	if (m_Cells[x - 1][y + 1].getIsAlive()) {
		colors.push_back(m_Cells[x - 1][y + 1].getAliveColor());
	}
	if (m_Cells[x][y - 1].getIsAlive()) {
		colors.push_back(m_Cells[x][y - 1].getAliveColor());
	}
	if (m_Cells[x][y + 1].getIsAlive()) {
		colors.push_back(m_Cells[x][y + 1].getAliveColor());
	}
	if (m_Cells[x + 1][y - 1].getIsAlive()) {
		colors.push_back(m_Cells[x + 1][y - 1].getAliveColor());
	}
	if (m_Cells[x + 1][y].getIsAlive()) {
		colors.push_back(m_Cells[x + 1][y].getAliveColor());
	}
	if (m_Cells[x + 1][y + 1].getIsAlive()) {
		colors.push_back(m_Cells[x + 1][y + 1].getAliveColor());
	}


	for (sf::Color& color : colors) {
		R += color.r;
		G += color.g;
		B += color.b;
	}

	avgColor.r = R / colors.size();
	avgColor.g = G / colors.size();
	avgColor.b = B / colors.size();

	return avgColor;
}

void RainbowGrid::switchCell(int x, int y) {
	m_Cells[x][y].switchState();
}