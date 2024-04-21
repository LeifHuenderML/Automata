"""
 * @file libtorch_api.py
 * @author Leif Huender
 * @brief 
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

import torch 
import torchvision
from model import DQN

class LibtorchAPI:
    def __init__(self):
        self.model = DQN()
        self.model.load_state_dict(torch.load('model.pth'))
        self.example = torch.randint(low=0, high=2, size=(1024,1024), dtype=torch.float32, device=self.device)
        self.traced_script_module = torch.jit.trace(self.model, self.example)
        self.traced_script_module.save("model.pt")

    def get_trace_model(self):
        return self.traced_script_module
