/**
 * @file Menu.hpp
 * @author Leif Huender, Aaron, Shaun Swant
 * @brief 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include "../game.cpp"

class Menu{
private:
    //private data members 
    const int windowWidth = 1512;
    const int windowHeight = 982; 
    sf::Texture mBackground;
    sf::Text mTitle;
    sf::Font mFont;
    sf::Vector2f mTitlePosition;
    sf::Color mTitleColor = sf::Color::Black;//(0x2E344000)
    Button m_0Player;
    Button m_1Player;
    Button mAI_Player;
    // void navigateToNewWindow(int state);
    void mainPage();
    void secondPage();
    void game();
    int m1, m2, m3;
    int s1, s2, s3;

    //private function members
    //void playMusic();
public:
    Menu();
    void run();
    void playMusic();

};


#endif