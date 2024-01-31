#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

const int WIDTH = 1024;
const int HEIGHT = 1024;
const int RESOLUTION = 4;
const int CELL_SIZE = WIDTH / RESOLUTION;
const int COLS = WIDTH / RESOLUTION;
const int ROWS = HEIGHT / RESOLUTION;

struct Grid
{
    int m_Arr[COLS + 2][ROWS + 2];
    int m_NewArr[COLS + 2][ROWS + 2];
    std::vector<int> m_Neighbors;

    Grid()
    {
        for (int i = 0; i < COLS + 2; ++i)
        {
            for (int j = 0; j < ROWS + 2; ++j)
            {
                // m_Arr[i][j] = 0;
                m_NewArr[i][j] = 0;
                m_Arr[i][j] = rand() % 2;
            }
        }
    }

    void update2DArray()
    {
        for (int i = 1; i < COLS + 1; ++i)
        {
            for (int j = 1; j < ROWS + 1; ++j)
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
        for (int i = 0; i < COLS + 2; ++i)
        {
            for (int j = 0; j < ROWS + 2; ++j)
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
        for (int i = 0; i < COLS + 2; ++i)
        {
            for (int j = 0; j < ROWS + 2; ++j)
            {
                std::cout << m_Arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void drawArray(sf::RenderWindow &window)
    {
        sf::Color color0(0, 0, 204);
        sf::Color color1(255, 51, 255);
        sf::Color color2(255, 128, 0);
        sf::Color color3(153, 255, 255);
        for (int i = 0; i < COLS + 1; ++i)
        {
            for (int j = 0; j < ROWS + 1; ++j)
            {
                sf::RectangleShape shape;

                shape.setSize(sf::Vector2f(WIDTH / COLS, HEIGHT / ROWS));
                shape.setPosition((WIDTH / COLS) * i, (HEIGHT / ROWS) * j);
                if (m_Arr[i][j])
                {
                    int randnum = rand();
                    int color = randnum % 3;
                    if (color == 2)
                    {
                        shape.setFillColor(color0);
                    }
                    else if (color == 1)
                    {
                        shape.setFillColor(color1);
                    }
                    else
                    {
                        shape.setFillColor(color2);
                    }
                    window.draw(shape);
                    continue;
                }
                shape.setFillColor(color3);
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
    srand(time(0));

    Grid grid;
    grid.printArray();

    bool play = false;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Automota");
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
                    int x = event.mouseButton.x / RESOLUTION;
                    int y = event.mouseButton.y / RESOLUTION;
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
            }
            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta > 0)
                {
                    view.zoom(1.1f);
                    window.setView(view);
                }
                if (event.mouseWheel.delta < 0)
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
                        int x = event.mouseButton.x / RESOLUTION;
                        int y = event.mouseButton.y / RESOLUTION;
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
                }

                if (event.type == sf::Event::MouseWheelMoved)
                {
                    if (event.mouseWheel.delta > 0)
                    {
                        view.zoom(1.1f);
                        window.setView(view);
                    }
                    if (event.mouseWheel.delta < 0)
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
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
        }
    }

    return 0;
}
