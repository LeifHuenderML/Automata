#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

class Cell
{
public:
    Cell(float x = 0.f, float y = 0.f, bool alive = 0)

    {
        m_Location.x = x;
        m_Location.y = y;
        m_IsAlive = alive;
        m_AliveColor = sf::Color(143, 188, 187, 255);
        m_DeadColor = sf::Color(46, 52, 64, 255);
    }

    sf::Vector2f getLocation()

    {
        return m_Location;
    }

    void setLocation(float x, float y)

    {
        m_Location.x = x;
        m_Location.y = y;
    }

    bool getIsAlive()

    {
        return m_IsAlive;
    }

    void setState(bool state)

    {
        m_IsAlive = state;
    }

    sf::Color getAliveColor()
    {
        return m_AliveColor;
    }

    sf::Color getDeadColor()
    {
        return m_DeadColor;
    }

protected:
    sf::Vector2f m_Location;
    sf::Color m_AliveColor;
    sf::Color m_DeadColor;
    bool m_IsAlive;
};

class ConwayCell : public Cell
{
public:
    ConwayCell()
    {
        m_AliveColor = sf::Color(143, 188, 187, 255);
        m_DeadColor = sf::Color::White;
    }

private:
};

class HighCell : public Cell
{
    HighCell()
    {
        m_AliveColor = sf::Color::Black;
        m_DeadColor = sf::Color::White;
    }
};

class RainbowCell : public Cell
{
public:
private:
};

class Grid
{
public:
    Grid()

    {
        m_Cells = new Cell *[COLS + 2];
        m_NextCells = new Cell *[COLS + 2];

        for (size_t i = 0; i < COLS + 2; i++)

        {
            m_Cells[i] = new Cell[ROWS + 2];
            m_NextCells[i] = new Cell[ROWS + 2];

            for (size_t j = 0; j < ROWS + 2; j++)

            {
                bool state = std::rand() % 2;
                m_Cells[i][j].setLocation(i, j);
                m_Cells[i][j].setState(state);
                m_NextCells[i][j].setLocation(i, j);
            }
        }
    }

    ~Grid()

    {
        for (size_t i = 0; i < COLS; ++i)

        {
            delete[] m_Cells[i];
            delete[] m_NextCells[i];
        }
        delete[] m_Cells;
        delete[] m_NextCells;
    }

    int findAliveNeighbors(Cell *cell)
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
            m_Cells[x + 1][y + 1]};

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

    void createImage()

    {
        m_Image.create(GRID_WIDTH, GRID_HEIGHT);
        for (size_t i = 1; i < COLS + 1; ++i)

        {
            for (size_t j = 1; j < ROWS + 1; ++j)

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

    void updateGrid()

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

        for (size_t i = 0; i < COLS; ++i)

        {
            for (size_t j = 0; j < ROWS; ++j)

            {
                m_Cells[i][j] = m_NextCells[i][j];
            }
        }
    }

    void draw(sf::RenderWindow &window)

    {

        m_Texture.create(GRID_WIDTH, GRID_HEIGHT);

        m_Texture.update(m_Image);
        m_Sprite.setPosition(0.f, 0.f);
        m_Sprite.setTexture(m_Texture);
        window.draw(m_Sprite);
    }

    std::vector<std::vector<bool>> getState()
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

    void setState(std::vector<bool> locationValues)
    {
        for (int i = 0; i < locationValues.size() - 1; i += 2)
        {
            m_Cells[i][i + 1].setState(1);
        }
    }

private:
    const static int GRID_WIDTH = 1024;
    const static int GRID_HEIGHT = 1024;
    const static int COLS = GRID_WIDTH;
    const static int ROWS = GRID_HEIGHT;

    Cell **m_Cells;
    Cell **m_NextCells;

    sf::Image m_Image;
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
};

int main()
{
    srand(time(0));
    Grid grid;
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Automota");

    while (window.isOpen())

    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))

        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        grid.createImage();
        grid.updateGrid();
        grid.draw(window);

        window.display();
    }

    return 0;
}
