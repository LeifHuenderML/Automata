/**
 * @file uiManager.hpp
 * @author Leif Huender, Aaron, Shaun Swant
 * @brief UIManager Responsibilities
 * Manages all user interface elements, including buttons, menus, and 
 * status displays. This involves rendering text, handling layout, and 
 * responding to user interactionsHandles user inputs (button clicks, menu selections)
 *  and translates them into actions within the game, such as starting a new game,
 *  pausing, or adjusting settings.
 * 
 * UIManager Technical Details
 * Utilizes SFML's graphics and window modules to render UI elements and handle 
 * input eventsImplementsa UI event system that allows components to communicate 
 * and react to user actionsEmploysa layout system to automatically arrange UI 
 * elements, ensuring a consistent and responsive design across different screen 
 * sizes and resolutions.
 * @version 0.1
 * @date 2024-01-24
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