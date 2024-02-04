/**
 * @file rlEngine.cpp
 * @author Leif Huender
 * @brief RLEngine Responsibilities
 * Manages the reinforcement learning aspect using the C++ PyTorch API, 
 * a powerful library for machine learning and neural network computation.
 * Trains models to learn optimal strategies under different conditions by
 *  interacting with the game environment, receiving feedback, and adjusting 
 * strategies based on the rewards received.Interfaces with CellManager to apply
 *  learned strategies to the cell grid and observe the results, effectively 
 * allowing the AI to control aspects of the game or simulate intelligent behavior.
 * 
 * RLEngine Technical Details
 * Implements reinforcement learning algorithms 
 * (Q-learning, policy gradients) that can operate on the state representations 
 * provided by the CellManager.Uses PyTorch's automatic differentiation and 
 * neural network modules to build and train models that can predict the value 
 * of actions or directly output optimal actions.Integrates with the game loop, 
 * allowing the AI to periodically receive state updates, perform actions, and receive 
 * feedback in the form of rewards.

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

#include "rlEngine.hpp"


void RLEngine::train(int episodes, float learningRate){
    torch::optim::Adam optimizer(nn->parameters(), torch::optim::AdamOptions(0.001));
    int batchSize = 32;
    int currBatchSize = 0;
    int totalReward = 0;
    for(int episode = 0; episode < episodes; ++episode){
        //resets the grid of cells to be all dead
        //resets the other numbers that are dependent on each iteration
        torch::Tensor state = env.reset();
    
        bool done = false;
        while(!done){
            torch::Tensor actionProbs = nn.forward(state);
            torch::tensor action = sampleActions(actionProbs);
            float reward = 0.0;
            env.step(action, reward, done);

            rememberBatch(state, action, reward, next_state);
            ++currBatchSize;
            if(batchSize == currBatchSize){
                torch::Tensor batch = sampleBatch();
                loss = calculate_loss(batch, nn);
                optimizer.zero_grad();
                loss.backward()
                optimizer.step();
            }
            totalReward += reward;
        }
        if(episodes % 10 == 0){
            std::cout << "Episode: " << episode << " Total Reward: " << totalReward << "\n";
        }
    }
}

torch::Tensor sampleActions(torch::Tensor actionProbs)

void RLEngine::runTraining(){
    int episodes = 100;
    float lr = 0.01;
    train(episodes, lr);
}

void RLEngine::test(){}