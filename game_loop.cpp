/**
 * @file GameLoop.cpp
 * @author Leif Huender
 * @brief 
 * @version 0.1
 * @date 2024-01-20
 * 
 * @copyright Copyright (c) 2024 Leif Huender
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "GameLoop.h"




void GameLoop::playMusic(){
    //load a soundtrack and error check
    sf::Music music;
    if (!music.openFromFile("music/nordic study session ~ chill lofi beats Credit: @CozyNordic.mp3")){
        throw std::runtime_error(EXIT_FAILURE);
    }
    //play the music
    music.play();
}

void GameLoop::run(){
    //create the main window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tile Window");

    int grid[rows][cols] = {};

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            grid[i][j] = (i + j) / 2;
        }
    }
 
    playMusic();
 
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        for(int i = 0; i < rows; ++i){
                for(int j = 0; j < cols; ++j){
                    sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
                    tile.setPosition(j * tileSize, i * tileSize);
                    tile.setFillColor(grid[i][j] == 1 ? sf::Color::White : sf::Color::Black);
                    window.draw(tile);
                }
            }

 
        // Update the window
        window.display();
    }
 
    return EXIT_SUCCESS;
}