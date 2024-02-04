/**
 * @file model.hpp
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

#include <torch/torch.h>


struct PolicyNetwork : torch::nn::Module {
    PolicyNetwork() {
        conv1 = register_module("conv1", torch::nn::Conv2d(1, 8, 3, 1, 1));
        conv2 = register_module("conv2", torch::nn::Conv2d(8, 16, 3, 1, 1));
        conv3 = register_module("conv3", torch::nn::Conv2d(16, 1, 3, 1, 1));
    }

    torch::Tensor forward(torch::Tensor x) {

        x = torch::relu(conv1->forward(x));
        x = torch::relu(conv2->forward(x));
        x = torch::sigmoid(conv3->forward(x));
        return x;
    }

    torch::nn::Conv2d conv1, conv2, conv3;
};