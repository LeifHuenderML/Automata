"""
 * @file env.py
 * @author Leif Huender
 * @brief implementation of the game of life environment
 * @version 0.1
 * @date 2024-04-20
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
"""
import random
import torch
import gym
from gym import spaces
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import matplotlib.pyplot as plt
import os


'''
uses openais gym environment to create a game of life environment
modified to use pytorch tensors and convolutions

methods:
    __init__(): initializes the environment with a grid size of 1024, and creates a grid of random 1s and 0s
    step(action): updates the grid based on the action, calculates the reward, and checks if the game is done
    check_done(next_state): checks if the game is done
    reset(): resets the grid to a random state
    render(state): renders the grid on a matplotlib plot
    update_grid(actions): updates the grid based on the actions
    calc_reward(next_state): calculates the reward based on the next state
    count_living(grid): counts the number of living cells in the grid
'''
class GameOfLifeEnv(gym.Env):
    def __init__(self, grid_size=1024):
        super(GameOfLifeEnv, self).__init__()
        self.grid_size = grid_size
        #set the device to run the computations on the gpu if available
        self.device = torch.device("mps" if torch.backends.mps.is_available() else "cpu")
        #initialize the grid with random 1s and 0s
        self.grid = torch.randint(low=0, high=2, size=(grid_size,grid_size), dtype=torch.float32, device=self.device)
        #initialize the kernel for the convolution
        self.kernel = torch.tensor([[1, 1, 1], [1, 0, 1], [1, 1, 1]], dtype=torch.float32, device=self.device).view(1, 1, 3, 3)

    def step(self, action):
        #update the grid based on the action
        self.update_grid(action)
        #apply the convolution to the grid
        result = F.conv2d(self.grid.unsqueeze(0).unsqueeze(0), self.kernel, padding=1)
        #apply the rules of the game of life
        output = ((result == 3) | ((result == 2) & (self.grid.unsqueeze(0).unsqueeze(0) == 1))).float()
        #get the next state
        next_state = output.squeeze()
        reward = self.calc_reward(next_state)
        self.grid = next_state
        done = self.check_done(next_state)

        return next_state, reward, done
    #check if the game is done
    def check_done(self, next_state):
        if self.count_living(next_state) == self.grid_size * self.grid_size:
            return True
        else: return False
    #reset the grid to a random state
    def reset(self):
        self.grid = torch.randint(low=0, high=2, size=(self.grid_size,self.grid_size), dtype=torch.float32, device=self.device)
        return self.grid
    #render the grid with matplotlib
    def render(self, state):
        grid = state.to('cpu')
        plt.imshow(grid, cmap='gray_r')
        plt.colorbar()
        plt.show()
    #update the grid based on the actions
    def update_grid(self, actions):
        #unpack the actions
        for i in range(0, actions.size(1), 2):
            x = int(actions[0][i])
            y = int(actions[0][i+1])
            #update the grid based on the x and y coordinates
            self.grid[x][y] = 1
        
    #calculate the reward based on the next state and the current state of the grid
    def calc_reward(self, next_state):
        state_count = self.count_living(self.grid)
        next_state_count = self.count_living(next_state)
        return next_state_count / state_count
    #count the number of living cells in the grid
    def count_living(self, grid):
        return torch.sum(grid == 1).item()
