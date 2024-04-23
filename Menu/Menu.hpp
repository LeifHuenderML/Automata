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
    Button minfo;
    //private function members
    //void playMusic();
public:
    Menu();
    void run();
    void playMusic();
};


#endif