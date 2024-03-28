/**
 * @file Menu.cpp
 * @author Leif Huender, Aaron, Shaun Swant
 * @brief 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Menu.hpp"

Menu::Menu(){
    
    m_0Player.setText("0 player");
    m_0Player.setSize({200,71});
    m_0Player.setPosition({(static_cast<float>(windowWidth)/2), (static_cast<float>(windowHeight)-500)});
    m_0Player.setColor(sf::Color::Red);

    m_1Player.setText("1 player");
    m_1Player.setColor( sf::Color::Red);
    m_1Player.setSize({200,71});
    m_1Player.setPosition({(static_cast<float>(windowWidth)/2), (static_cast<float>(windowHeight)-400)});

    mAI_Player.setText("AI player");
    mAI_Player.setColor(sf::Color::Red);
    mAI_Player.setSize({200,71});
    mAI_Player.setPosition({(static_cast<float>(windowWidth)/2), (static_cast<float>(windowHeight)-300)});

    minfo.setText("About");
    minfo.setColor(sf::Color::Red);
    minfo.setSize({200,71});
    minfo.setPosition({(static_cast<float>(windowWidth)/2), (static_cast<float>(windowHeight)-200)});
}

void Menu::run(){
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");


       while (window.isOpen())
   {
       sf::Event event;
       playMusic();
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
            m_0Player.update(event, window);
            m_1Player.update(event, window);
            mAI_Player.update(event, window);
            minfo.update(event, window);
       }

       window.clear();
       window.draw(m_0Player);
       window.draw(m_1Player);
       window.draw(mAI_Player);
       window.draw(minfo);
       window.display();
   }
   
}

void Menu::playMusic(){
    //load a soundtrack and error check
    sf::Music music;
    if (!music.openFromFile("music/nordic study session ~ chill lofi beats Credit: @CozyNordic.mp3")){
        throw std::runtime_error("Error opening music");
    }
    //play the music
    music.play();
}