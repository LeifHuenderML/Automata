"""
 * @file trainer.py
 * @author Leif Huender
 * @brief implementation of the Trainer class for training the DQN model
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
from collections import namedtuple, deque
from env import GameOfLifeEnv
from model import DQN



#used for pusing to the memory stack    
Transition = namedtuple('Transition', ('state', 'action', 'next_state', 'reward'))
#memory class for storing the transitions
class Memory(object):
    def __init__(self, capacity):
        self.memory = deque([], maxlen=capacity)
    def push(self, *args):
        self.memory.append(Transition(*args))

    def sample(self,batch_size):
        return random.sample(self.memory, batch_size)

    def __len__(self):
        return len(self.memory)



'''
Trainer class for training the DQN model
methods:
    __init__(): initializes the trainer with the environment, model, device, episodes, iterations, batch size, memory size, gamma, learning rate, tau, optimizer, losses, and rewards
    train(): trains the model over the specified number of episodes and iterations
    optimize(): optimizes the model by calculating the loss and updating the weights
    sanity_check(): prints the model, environment, number of parameters, and model size
    get_action(state): gets the action based on the state
    save_model(path): saves the model to the specified path
    load_model(path): loads the model from the specified path
    training_bar(iteration): prints a progress bar for the training
    plot_metrics(): plots the losses per episode
attributes:
    env: the game of life environment
    model: the DQN model
    device: the device to run the computations on
    episodes: the number of episodes to train the model
    iterations: the number of iterations per episode
    batch_size: the batch size for training
    memory: the memory for storing the transitions
    target_net: the target network for updating the weights
    lr: the learning rate
    tau: the tau value for updating the target network
    optimizer: the optimizer for training the model
    losses: the losses per episode
    rewards: the rewards per episode'''

class Trainer:
    def __init__(self, episodes=200, iterations=1000, batch_size=32, lr=1e-4, memory_size=1000, tau=0.005):
        self.env = GameOfLifeEnv()
        self.model = DQN()
        self.device = torch.device("mps" if torch.backends.mps.is_available() else "cpu")
        self.episodes = episodes
        self.iterations = iterations
        self.batch_size = batch_size
        self.memory = Memory(memory_size)

        self.lr = lr
        self.tau = tau
        self.optimizer = torch.optim.Adam(self.model.parameters(), lr=self.lr, amsgrad=True)
        self.model.to(self.device)
        self.losses = []
        self.rewards = []

    def train(self):
        print("Training Started...")
        for episode in range(self.episodes):
            #reset the environment
            state = self.env.reset()
            iteration = 0
            done = False
            cum_reward = 0
            print(f'Episode: {episode} of {self.episodes}')
            #loop through the iterations
            for iteration in range(self.iterations):
                #print the progress bar
                self.training_bar(iteration)
                #get the action based on the state
                state = state.unsqueeze(0).unsqueeze(1)
                action = self.get_action(state)
                #take a step in the environment
                next_state, reward, done = self.env.step(action)
                cum_reward += reward
                reward = torch.tensor([reward], device=self.device)
                #push the transition to the memory
                self.memory.push(state,action,next_state,reward)
                #update the state
                state = next_state
                #optimize the model
                loss = self.optimize()
                #append the loss
                self.losses.append(loss)
                
                if done:
                    break
                iteration += 1
            self.rewards.append(cum_reward/iteration)
        self.save_model('model.pth')
            
        print("Training Ended...")
        self.plot_metrics()
        

    def optimize(self):
        #if the memory is less than the batch size dont optimize
        if len(self.memory) < self.batch_size:
            return  
        #sample the transitions
        transitions = self.memory.sample(self.batch_size)
        batch = Transition(*zip(*transitions))
        #concatenate the states and actions
        state_batch = torch.cat(batch.state)
        reward_batch = torch.cat(batch.reward)
        #get the model output
        model_output = self.model(state_batch)
        #get the expected values
        expected_values = torch.repeat_interleave(reward_batch.unsqueeze(1), 200, dim=1)  
        criterion = nn.MSELoss() 
        #calculate the loss
        loss = criterion(model_output,expected_values)
        #zero the gradients
        self.optimizer.zero_grad()
        #backpropagate the loss
        loss.backward()
        #clip the gradients
        torch.nn.utils.clip_grad_value_(self.model.parameters(), 100)
        #update the weights
        self.optimizer.step()

        return loss.item()
        
    def sanity_check(self):
            print(f"model: {self.model}")
            print(f"env: {self.env}")
            n_params = sum(p.numel() for p in self.model.parameters())
            print(f"Number of parameters: {n_params}")
            torch.save(self.model.state_dict(), 'sanity_check_model.pth')
            model_size_mb = os.path.getsize('sanity_check_model.pth') / 1e6
            print(f"Model size: {model_size_mb} MB")
    #get the action based on the state
    def get_action(self, state):
        #randomly select an action
        if random.random() > 0.1:
            return torch.randint(low=0, high=self.env.grid_size, size=(1, 200), dtype=torch.float32, device=self.env.device)   
        else:
        #get the model output
            return self.model(state)
        
    def save_model(self, path):
        torch.save(self.model.state_dict(), path)

    def load_model(self, path):
        self.model.load_state_dict(torch.load(path))

    def training_bar(self, iteration):
        if(iteration %10 == 0): print('|#', end='')

    def plot_metrics(self):
        plt.figure(figsize=(12, 5))
        plt.subplot(1, 2, 1)
        plt.plot(self.losses, label='Loss')
        plt.title('Loss per Episode')
        plt.legend()
        plt.show()