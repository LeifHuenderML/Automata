/**
 * @file model.hpp
 * @author Leif Huender, Aaron, Shaun Swant
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
#ifndef MODEL_HPP
#define MODEL_HPP

#include <torch/torch.h>
#include <vector>
#include <string>
#include <memory>

class AutomataNN : public torch::nn::Module {
public:
    AutomataNN() {
        // Register and initialize each layer of the neural network.
        conv1 = register_module("conv1", torch::nn::Conv2d(torch::nn::Conv2dOptions(1, 16, 3).stride(2).padding(1)));
        pool1 = register_module("pool1", torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2).stride(2)));
        conv2 = register_module("conv2", torch::nn::Conv2d(torch::nn::Conv2dOptions(16, 32, 3).stride(2).padding(1)));
        pool2 = register_module("pool2", torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2).stride(2)));
        conv3 = register_module("conv3", torch::nn::Conv2d(torch::nn::Conv2dOptions(32, 64, 3).stride(2).padding(1)));
        pool3 = register_module("pool3", torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2).stride(2)));
        conv4 = register_module("conv4", torch::nn::Conv2d(torch::nn::Conv2dOptions(64, 128, 3).stride(2).padding(1)));
        conv5 = register_module("conv5", torch::nn::Conv2d(torch::nn::Conv2dOptions(128, 256, 3).stride(2).padding(1)));

        fc1 = register_module("fc1", torch::nn::Linear(256 * 6 * 6, 2048)); // Adjust the input features to match your exact dimensions.
        fc2 = register_module("fc2", torch::nn::Linear(2048, 1024));
        fc3 = register_module("fc3", torch::nn::Linear(1024, 256));
        fc4 = register_module("fc4", torch::nn::Linear(256, 200));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(conv1->forward(x));
        x = pool1->forward(x);
        x = torch::relu(conv2->forward(x));
        x = pool2->forward(x);
        x = torch::relu(conv3->forward(x));
        x = pool3->forward(x);
        x = torch::relu(conv4->forward(x));
        x = torch::relu(conv5->forward(x));

        // Flatten the output from the convolutional layers before passing it to the fully connected layers.
        x = x.view({x.size(0), -1});// This needs to match the input dimensions of fc1.
        x = torch::relu(fc1->forward(x));
        x = torch::relu(fc2->forward(x));
        x = torch::relu(fc3->forward(x));
        x = fc4->forward(x);
        return x;
    }
    void load_parameters(const std::string& model_path) {
        torch::jit::script::Module module;
        module = torch::jit::load(model_path);
        std::cout << "Model loaded from " << model_path << '\n';
    }

private:
    torch::nn::Conv2d conv1{nullptr}, conv2{nullptr}, conv3{nullptr}, conv4{nullptr}, conv5{nullptr};
    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr}, fc4{nullptr};
    torch::nn::MaxPool2d pool1{nullptr}, pool2{nullptr}, pool3{nullptr};
};



class AutomataMind {
public:
    AutomataMind() : model(AutomataNN()) {
        std::string model_path = "model.pt";
        model.load_parameters(model_path);
    }

    // Adjust the method to take a 2D vector of bools
    std::vector<int> predict(const std::vector<std::vector<bool>>& state) {
        // Converts the 2D state to a tensor and passes it through the model
        torch::Tensor converted_state = convertVector(state);
        torch::Tensor predictions = model.forward(converted_state);
        // Converts the output tensor to a vector of ints
        return tensorToVector(predictions);
    }

private:
    AutomataNN model;

    // Adjust convertVector to handle a 2D vector of bools
    torch::Tensor convertVector(const std::vector<std::vector<bool>>& state) {
        // Assuming state is not empty and all inner vectors are the same size
        int rows = state.size();
        int cols = state[0].size();
        torch::Tensor tensor = torch::empty({rows, cols}, torch::kFloat32);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                tensor[i][j] = state[i][j] ? 1.0 : 0.0;
            }
        }
        return tensor;
    }

    std::vector<int> tensorToVector(torch::Tensor tensor) {
        // Converts a Tensor to a std::vector<int>
        return std::vector<int>(tensor.data_ptr<int>(), tensor.data_ptr<int>() + tensor.numel());
    }
};



#endif //MODEL_HPP