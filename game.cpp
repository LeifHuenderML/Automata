#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

const int RESOLUTION = 4;

struct Grid
{
    const static int GRID_WIDTH = 2048;
    const static int GRID_HEIGHT = 2048;
    const static int COLS = GRID_WIDTH / RESOLUTION;
    const static int ROWS = GRID_HEIGHT / RESOLUTION;

    int **m_Arr;
    int **m_NewArr;
    std::vector<int> m_Neighbors;

    Grid()
    {
        m_Arr = new int *[COLS];
        m_NewArr = new int *[COLS];
        for (size_t i = 0; i < COLS + 2; ++i)
        {
            m_Arr[i] = new int[ROWS];
            m_NewArr[i] = new int[ROWS];
            for (size_t j = 0; j < ROWS + 2; ++j)
            {
                m_NewArr[i][j] = 0;
                m_Arr[i][j] = rand() % 2;
            }
        }
    }

    ~Grid()
    {
        for (size_t i = 0; i < COLS; ++i)
        {
            delete[] m_Arr[i];
            delete[] m_NewArr[i];
        }
        delete[] m_Arr;
        delete[] m_NewArr;
    }

    void update2DArray()
    {
        for (size_t i = 1; i < COLS + 1; ++i)
        {
            for (size_t j = 1; j < ROWS + 1; ++j)
            {
                int aliveNeighbors = findNeighbors(i, j);
                if (m_Arr[i][j] && (aliveNeighbors < 2 || aliveNeighbors > 3))
                {
                    m_NewArr[i][j] = 0;
                    continue;
                }
                if (!m_Arr[i][j] && aliveNeighbors == 3)
                {
                    m_NewArr[i][j] = 1;
                    continue;
                }
                m_NewArr[i][j] = m_Arr[i][j];
            }
        }
        for (size_t i = 0; i < COLS + 2; ++i)
        {
            for (size_t j = 0; j < ROWS + 2; ++j)
            {
                m_Arr[i][j] = m_NewArr[i][j];
            }
        }
    }

    int findNeighbors(int x, int y)
    {
        m_Neighbors = {
            m_Arr[x - 1][y - 1],
            m_Arr[x - 1][y],
            m_Arr[x - 1][y + 1],

            m_Arr[x][y - 1],
            m_Arr[x][y + 1],

            m_Arr[x + 1][y - 1],
            m_Arr[x + 1][y],
            m_Arr[x + 1][y + 1]};

        int aliveNeighbors = 0;

        for (int neighbor : m_Neighbors)
        {
            if (neighbor)
            {
                aliveNeighbors++;
            }
        }
        return aliveNeighbors;
    }

    void printArray()
    {
        for (size_t i = 0; i < COLS + 2; ++i)
        {
            for (size_t j = 0; j < ROWS + 2; ++j)
            {
                std::cout << m_Arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void drawArray(sf::RenderWindow &window)
    {
        sf::Color color0(0, 0, 0);
        sf::Color color1(255, 255, 255);
        sf::Color color2(255, 128, 0);
        sf::Color color3(153, 255, 255);
        for (size_t i = 0; i < COLS + 1; ++i)
        {
            for (size_t j = 0; j < ROWS + 1; ++j)
            {
                sf::RectangleShape shape;

                shape.setSize(sf::Vector2f(GRID_WIDTH / COLS, GRID_HEIGHT / ROWS));
                shape.setPosition((GRID_WIDTH / COLS) * i, (GRID_HEIGHT / ROWS) * j);
                if (m_Arr[i][j])
                {
                    shape.setFillColor(color0);
                    window.draw(shape);
                    continue;
                }
                shape.setFillColor(color1);
                window.draw(shape);
            }
        }
    }

    bool getState(int x, int y)
    {
        bool state = m_Arr[x][y];

        return state;
    }

    void switchState(int x, int y)
    {
        m_Arr[x][y] = !getState(x, y);
    }
};

int main(int argc, char const *argv[])
{
    const int WINDOW_WIDTH = 1024;
    const int WINDOW_HEIGHT = 1024;

    srand(time(0));

    Grid grid;
    grid.printArray();

    bool play = false;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Automota");
    sf::View view(sf::Vector2f(350.f, 300.f), sf::Vector2f(300.f, 200.f));
    window.setView(view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(0);
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                    // int x = event.mouseButton.x / RESOLUTION;
                    // int y = event.mouseButton.y / RESOLUTION;
                    int x = worldPos.x / RESOLUTION;
                    int y = worldPos.y / RESOLUTION;
                    grid.switchState(x, y); // Toggle cell state
                    window.clear();
                    grid.drawArray(window);
                    window.display();
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    play = !play;
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    view.move(0, 1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    view.move(0, -1);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    view.move(-1, 0);
                    window.setView(view);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    view.move(1, 0);
                    window.setView(view);
                }
            }
            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0)
                {
                    view.zoom(1.1f);
                    window.setView(view);
                }
                if (event.mouseWheel.delta > 0)
                {
                    view.zoom(0.9f);
                    window.setView(view);
                }
            }

            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        while (play)
        {
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    exit(0);
                }

                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                        // int x = event.mouseButton.x / RESOLUTION;
                        // int y = event.mouseButton.y / RESOLUTION;
                        int x = worldPos.x / RESOLUTION;
                        int y = worldPos.y / RESOLUTION;
                        grid.switchState(x, y); // Toggle cell state
                        window.clear();
                        grid.drawArray(window);
                        window.display();
                    }
                }

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        play = !play;
                    }

                    if (event.key.code == sf::Keyboard::Down)
                    {
                        view.move(0, 1);
                        window.setView(view);
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        view.move(0, -1);
                        window.setView(view);
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        view.move(-1, 0);
                        window.setView(view);
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        view.move(1, 0);
                        window.setView(view);
                    }
                }

                if (event.type == sf::Event::MouseWheelMoved)
                {
                    if (event.mouseWheel.delta < 0)
                    {
                        view.zoom(1.1f);
                        window.setView(view);
                    }
                    if (event.mouseWheel.delta > 0)
                    {
                        view.zoom(0.9f);
                        window.setView(view);
                    }
                }

                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                }
            }

            window.clear();
            // sf::sleep(sf::milliseconds(85));
            grid.drawArray(window);
            grid.update2DArray();
            window.display();
        }
    }

    return 0;
}
