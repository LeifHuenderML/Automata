/**
 * @file cellManager.hpp
 * @author Leif Huender
 * @brief CellManager Responsibilities
 * Manages the cell grid and its state, which involves storing and updating
 *  a two-dimensional array of cells. Updates the cells based on cellular 
 * automata rules, which determine the state of each cell in the grid based 
 * on the states of its neighbors. Can handle different types of cells through 
 * polymorphism. A base class `Cell` can be extended to create various specialized
 *  cells, allowing for a versatile system capable of simulating different scenarios.
 * 
 * CellManager Technical Details
 * Implements efficient data structures (arrays, matrices) to store the state of 
 * each cell and to perform batch updates on the grid. Employs optimized algorithms 
 * for updating cells based on cellular automata rules, minimizing unnecessary 
 * calculations. Facilitates the extension of cell behavior through a well-defined 
 * inheritance hierarchy, where each subclass of `Cell` can override specific methods 
 * to alter its behavior.
 * 
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

/*
DELETE EVENTUALLY THIS IS JUST TO HELP FIGURE OUT FRAME WORK
- `GameController <-> UIManager`: GameController receives user inputs from UIManager (menu selections, 
in-game commands) and updates the game state accordingly. It also sends state updates to UIManager to 
reflect changes in the game, such as transitioning between menus and the game scene.

- `GameController <-> CellManager`: GameController triggers updates in CellManager based on game state 
(starting a new simulation, pausing) and user inputs (e.g., modifying cell states, changing simulation parameters).

- `CellManager <-> RLEngine`: CellManager provides cell grid states to RLEngine for training and strategy
 application. RLEngine, in turn, sends back actions or policy updates that CellManager uses to adjust cell 
 behavior or simulation parameters.

- `CellManager <-> Environment`: The Environment imposes conditions on the cell grid, such as altering resource
 availability or introducing hazards. CellManager updates cell states based on these conditions, ensuring that the 
 simulation reflects the dynamic interplay between cells and their environment.

*/

