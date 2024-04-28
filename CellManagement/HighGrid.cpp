#include "HighGrid.hpp"

HighGrid::HighGrid()

{
	m_Cells = new HighCell * [COLS + 2];
	m_NextCells = new HighCell * [COLS + 2];

	for (size_t i = 0; i < COLS + 2; i++)

	{
		m_Cells[i] = new HighCell[ROWS + 2];
		m_NextCells[i] = new HighCell[ROWS + 2];

		for (size_t j = 0; j < ROWS + 2; j++)

		{
			bool state = rand() % 2;
			m_Cells[i][j].setLocation(i, j);
			m_Cells[i][j].setState(state);
			m_NextCells[i][j].setLocation(i, j);
		}
	}
}

HighGrid::~HighGrid()

{
	for (size_t i = 0; i < COLS; ++i)

	{
		delete[] m_Cells[i];
		delete[] m_NextCells[i];
	}
	delete[] m_Cells;
	delete[] m_NextCells;
}

int HighGrid::findAliveNeighbors(HighCell* cell)
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

void HighGrid::createImage()

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

void HighGrid::updateHigh()

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
				m_NextCells[i][j].setAliveColor(m_NextCells[i][j].m_Colors[0]);
				continue;
			}
			if (!m_Cells[i][j].getIsAlive() && aliveNeighbors == 6)

			{
				m_NextCells[i][j].setState(1);
				m_NextCells[i][j].setAliveColor(m_NextCells[i][j].m_Colors[1]);
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

void HighGrid::draw(sf::RenderWindow& window)

{

	m_Texture.create(GRID_WIDTH, GRID_HEIGHT);

	m_Texture.update(m_Image);
	m_Sprite.setPosition(0.f, 0.f);
	m_Sprite.setTexture(m_Texture);
	window.draw(m_Sprite);
}

std::vector<std::vector<bool>> HighGrid::getState()
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

void HighGrid::setState(std::vector<bool> locationValues)
{
	for (int i = 0; i < locationValues.size() - 1; i += 2)
	{
		m_Cells[i][i + 1].setState(1);
	}
}

void HighGrid::switchCell(int x, int y) {
	m_Cells[x][y].switchState();
}
