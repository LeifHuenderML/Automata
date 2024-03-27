/**
 * @file gameController.hpp
 * @author Leif Huender, Aaron, Shaun Swant
 * @brief 
 * @version 0.1
 * @date 2024-01-24
 * Orchestrates the game loop using the Simple and Fast Multimedia Library (SFML), 
 * a multimedia C++ API. This involves initializing the rendering window, 
 * handling frame updates, and managing event polling for user interactions.
 * Manages transitions between different game states (such as: menu, in-game, game over) 
 * by maintaining a state machine. Each state encapsulates specific behaviors and 
 * can trigger transitions based on events or conditions.
 * Handles high-level interactions between major components (CellManager, UIManager, RLEngine) 
 * by serving as a mediator, ensuring that each component's state and data are synchronized 
 * with the overall game state.
 * GameController Technical Details:
 * Utilizes the SFML event system to process user inputs (keyboard, mouse) 
 * and window events (close, resize).
 * Implements a game loop that calculates the delta time between frames to ensure 
 * consistent updates and rendering regardless of performance fluctuations.
 * Manages a stack of game states, allowing for flexible control over the flow of the game, 
 * such as pausing and resuming.

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

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class GameController{
private:
    //private data members 
    const int windowHeight = 1600;
    const int windowWidth = 1800;
    const int rows = 10;
    const int cols = 10;
    const int tileSize = 5;
    //private function members
    void playMusic();
public:
    GameController();
    void run();
};

#endif