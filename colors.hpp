/**
 * @file colors.hpp
 * @author Leif Huender
 * @brief 
 * @version 0.1
 * @date 2024-01-19
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

#ifndef COLORS_H
#define COLORS_H

struct Colors{
    //all of these are in hexidecimal notation 
    //when there are multiples of the shade it goes from 
    //0 as lightest to n as the darkest

    //Grey
    static const unsigned int Grey0 = 0x4c566a;
    static const unsigned int Grey1 = 0x434c5e;
    static const unsigned int Grey2 = 0x3b4252;
    static const unsigned int Grey3 = 0x2e3440;
    //White
    static const unsigned int White0 = 0xeceff4;
    static const unsigned int White1 = 0xe5e9f0;
    static const unsigned int White2 = 0xd8dee9;
    //Blue
    static const unsigned int Blue0 = 0x88c0d0;
    static const unsigned int Blue1 = 0x8fbcbb;
    static const unsigned int Blue2 = 0x81a1c1;
    static const unsigned int Blue3 = 0x5e81ac;
    //Mixed
    static const unsigned int Red = 0xbf616a;
    static const unsigned int Orange = 0xd08770;
    static const unsigned int Yellow = 0xebcb8b;
    static const unsigned int Green = 0xa3be8c;
    static const unsigned int Purple = 0xb48ead;
};

#endif