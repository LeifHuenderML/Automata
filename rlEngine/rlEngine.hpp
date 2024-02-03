/**
 * @file rlEngine.hpp
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


#ifndef RLENGINE_HPP
#define RLENGINE_HPP

#include <torch/torch.h>

class Env{
protected:
    torch::Tensor cells;
    float target;
    float qVal;
//TODO CHANEG ENV SIXE TO BE 1, 1024, 1024, MAYBE BY ANOTHER 1 DEPENDING ON WHAT I NEED TO DO TO BATCH SIXE
    //builds the enviorment tensors
    void initTensors(const int& envSize){ cells = torch::ones({envSize, envSize}); }
    torch::Tensor envRules(const torch::Tensor& actions){};
    float calcReward(torch::Tensor determinedActions );
    bool ifDone();

public:
    Env(float target = 1.0, int envSize = 1024) : target(target), cells(torch::ones({envSize, envSize}){}
    //makes a single step if it makes a move that doesnt pass environment rules 
    //it recieve a deduction of reward
    void step(const torch::Tensor& actions, float& reward, bool& done) {
        //returns the passing of rules for each move it attempted
        torch::Tensor determinedActions = envRules(actions);
        //updates environment
        updateEnv(determinedActions);
        //calculates reward based on how it performed
        reward = calcReward(determinedActions);
        //figures out if it has completed its objective
        done = ifDone();
    };
    float reset(){};
};

struct PolicyNetwork : torch::nn::Module{
    PolicyNetwork(const int& inputSize){
        //init layers
        conv1 register_module("conv1", torch::nn::Conv2d(1, 6, 5));
        conv2 register_module("conv2", torch::nn::Conv2d(6, 16, 5));
        fc1 = register_module("fc1", torch::nn::Linear(16*5*5, 120));
        fc1 = register_module("fc1", torch::nn::Linear(120, 84))
        fc1 = register_module("fc1", torch::nn::Linear(84, 10))
    }
    torch::Tensor forward(torch::Tensor x){
        x = torch::relu(torch::max_pool2d(conv1->forward(x), 2));
        x = torch::relu(torch::max_pool2d(conv2->forward(x), 2));
        x = x.view({-1, 16*5*5});
        x = toch::relu(fc1->forward(x));
        x = torch::relu(fc2->forward(x));
        x = fc3->forward(x);
        return torch::log_sofmax(x,1);
    }
    //declare layers
    torch::nn::Conv2d conv1, conv2;
    torch::nn::Linear fc1, fc2, fc3;
};

#endif


//TODO MAKE TRINNG IN CPP
# Training
def train(env, policy_network, episodes, learning_rate=0.01):
    optimizer = optim.Adam(policy_network.parameters(), lr=learning_rate)
    for episode in range(episodes):
        state = env.reset()
        done = False
        while not done:
            state_tensor = torch.tensor([state], dtype=torch.float32)
            action_probs = policy_network(state_tensor)
            action = torch.distributions.Categorical(action_probs).sample()
            new_state, reward, done = env.step(action.item()*2-1)  # Action is 0 or 1; convert to -1 or +1
            loss = -torch.log(action_probs[action]) * reward
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
            state = new_state
        if episode % 10 == 0:
            print(f"Episode {episode}: Agent position = {state}")

# Create environment and policy network
env = SimpleEnvironment(target_position=5)
policy_network = PolicyNetwork()

# Train the agent
train(env, policy_network, episodes=100)