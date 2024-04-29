#include "Grid.hpp"

Grid::Grid()

{
	m_Cells = new Cell * [COLS + 2];
	m_NextCells = new Cell * [COLS + 2];

	for (size_t i = 0; i < COLS + 2; i++)

	{
		m_Cells[i] = new Cell[ROWS + 2];
		m_NextCells[i] = new Cell[ROWS + 2];

		for (size_t j = 0; j < ROWS + 2; j++)

		{
			bool state = rand() % 2;
			m_Cells[i][j].setLocation(i, j);
			m_Cells[i][j].setState(state);
			m_NextCells[i][j].setLocation(i, j);
		}
	}
}

Grid::~Grid()

{
	for (size_t i = 0; i < COLS; ++i)

	{
		delete[] m_Cells[i];
		delete[] m_NextCells[i];
	}
	delete[] m_Cells;
	delete[] m_NextCells;
}

int Grid::findAliveNeighbors(Cell* cell)
{
	sf::Vector2f location = cell->getLocation();
	int x = location.x;
	int y = location.y;

	Cell neighbors[] = {
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

void Grid::createImage()

{
	m_Image.create(GRID_WIDTH, GRID_HEIGHT);
	for (size_t i = 1; i < COLS + 1; i++)

	{
		for (size_t j = 1; j < ROWS + 1; j++)

		{
			if (m_Cells[i][j].getIsAlive())

			{
				m_Image.setPixel(i - 1, j - 1, m_Cells[i][j].getAliveColor());
			}
			else
			{
				m_Image.setPixel(i - 1, j - 1, m_Cells[i][j].getDeadColor());
			}
		}
	}

	if (!m_Image.saveToFile("result.png"))
		exit(1);
}

void Grid::updateConway()

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
				continue;
			}
			m_NextCells[i][j] = m_Cells[i][j];
		}
	}

	createImage();

	for (size_t i = 0; i < COLS + 2; i++)

	{
		for (size_t j = 0; j < ROWS + 2; j++)

		{
			m_Cells[i][j] = m_NextCells[i][j];
		}
	}
}

void Grid::draw(sf::RenderWindow& window)

{

	m_Texture.create(GRID_WIDTH, GRID_HEIGHT);

	m_Texture.update(m_Image);
	m_Sprite.setPosition(0.f, 0.f);
	m_Sprite.setTexture(m_Texture);
	window.draw(m_Sprite);
}

std::vector<std::vector<bool>> Grid::getState()
{
	std::vector<std::vector<bool>> state(COLS + 2, std::vector<bool>(ROWS + 2)); // If you need a border
	for (size_t i = 0; i <= COLS + 1; i++) {
		for (size_t j = 0; j <= ROWS + 1; j++) {
			state[i][j] = m_Cells[i][j].getIsAlive();
		}
	}
	return state;
}

void Grid::setState(std::vector<int> locationValues)
{
	for (int i = 0; i < locationValues.size() - 1; i += 2)
	{
		m_Cells[i][i + 1].setState(1);
	}
}

void Grid::switchCell(int x, int y) {
	m_Cells[x][y].switchState();
}