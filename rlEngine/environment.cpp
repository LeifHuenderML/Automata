/**
 * @file envionrment.cpp
 * @author Leif Huender
 * @brief 
 * @version 0.1
 * @date 2024-02-03
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

#include "environment.hpp"


    for(int row = 1; row < accessor.size(0) - 1; ++row){
        for(int col = 1; col < accessor.size(1) - 1; ++col){
            int liveNeighbors = 0;

            for(int x = -1; x <= 1; ++x){
                for(int y = -1; y <= 1; ++y){
                    if(x == 0 && y == 0) continue;
                    int nRow = row + x;
                    int nCol = col + y;

                    if(nRow >= 0 && nCol >= 0 && nRow < accessor.size(0) && nCol < accessor.size(1)) {
                        if(accessor[nRow][nCol] || actions[nRow][nCol].item<bool>()) {
                            liveNeighbors++;
                        }
                    }
                }
            }

            if((accessor[row][col] || actions[row][col].item<bool>()) && (liveNeighbors == 2 || liveNeighbors == 3)){
                newCells[row][col] = true;
            } else if((!accessor[row][col] && !actions[row][col].item<bool>()) && liveNeighbors == 3){
                newCells[row][col] = true;
            } else {
                newCells[row][col] = false; 
            }
        }
    }

    return newCells;
}
