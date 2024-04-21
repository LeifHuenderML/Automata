/**
 * @file main.cpp
 * @author Leif Huender
 * @brief implementation of the cpp automata neural network to make predicitons
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
 */

// #include "model.hpp"
#include <random>
#include <iostream>
#include <memory>
#include <vector>
#include <torch/script.h>
//displays a 1d vector
void print1d(std::vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
//displays a 2d vector
void print2d(std::vector<std::vector<bool>> vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
//creates a random state for a 2d vector
void randomize(std::vector<std::vector<bool>> &vec){
    //random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);
    //fill the vector with random values
    for(int i = 0; i < 1024; i++){
        for(int j = 0; j < 1024; j++){
            vec[i][j] = d(gen);
        }
    }
}

int main(){
    // //create a random state
    // std::vector<std::vector<bool>> state(1024, std::vector<bool>(1024));
    // randomize(state);
    // //print the state
    // std::cout<< "State: \n";
    // print2d(state);
    // std::cout<< "===============================================\n";
    // //create the automata
    // AutomataMind automata;

    // //predict the actions
    // std::vector<int> actions = automata.predict(state);
    // //print the actions
    // std::cout<< "Actions: \n";
    // print1d(actions);
    // std::cout<< "===============================================\n";
    std::string model_path = "model.pt";
    torch::jit::script::Module module;
    module = torch::jit::load(model_path);
    std::cout << "Model loaded from " << model_path << '\n';
    std::vector<std::vector<torch::jit::IValue>> inputs;
    inputs.push_back({torch::ones({1, 3, 224, 224})});
    // at::Tensor output = module.forward(inputs).toTensor();
    // std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/5) << '\n';


    return 0;
}