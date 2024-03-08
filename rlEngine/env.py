import gym
from gym import spaces
import numpy as np
import torch.nn.functional as F
import torch
import matplotlib.pyplot as plt
class GameOfLifeEnv(gym.Env):
    def __init__(self, grid_size=10):
        super(GameOfLifeEnv, self).__init__()
        self.grid_size = grid_size
        #initialize the grid to be a boolean matrix of zeros of the grid size
        #self.grid = torch.(self.grid_size, self.grid_size, dtype=torch.float32)
        #for testing starts with a rand initialization
        self.grid = torch.randint(low=0, high=2, size=(grid_size,grid_size), dtype=torch.float32)

    def step(self, action):
        kernel = torch.tensor([[1, 1, 1], [1, 0, 1], [1, 1, 1]], dtype=torch.float32).view(1, 1, 3, 3) 
        result = F.conv2d(self.grid.unsqueeze(0).unsqueeze(0), kernel, padding=1)
        output = ((result == 3) | ((result == 2) & (self.grid.unsqueeze(0).unsqueeze(0) == 1))).float()
        self.grid = output.squeeze()
        # TODO: Update to return state, reward, done, flag, and info
        return self.grid

    def reset(self):
        self.grid = torch.zeros(self.grid_size, self.grid_size, dtype=torch.float32)
    def render(self, mode='human'):
        plt.imshow(self.grid, cmap='gray_r')
        plt.colorbar()
        plt.show()

#https://johnhw.github.io/hashlife/index.md.html
 