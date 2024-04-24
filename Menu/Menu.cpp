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
#include <unistd.h>

Menu::Menu()
{   
    
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
    }

    if (!mBackground.loadFromFile("docs/images/Menu_Background.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mFont.loadFromFile("docs/images/college.ttf");
    // //Font operations
    // if (!mFont.loadFromFile("college.ttf"))
    // {
    //     std::cout<<"Error opening file\n";
    //     exit(2);
    // }

    mTitle.setFont(mFont);
    mTitle.setString("AUTOMATA - a game of life");
    mTitle.setCharacterSize(110);
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    mTitle.setFillColor(mTitleColor);

    m_0Player.setText("0 player");
    m_0Player.setSize({200,71});
    m_0Player.setPosition({(static_cast<float>(windowWidth)/3), (static_cast<float>(windowHeight)-500)});

    m_1Player.setText("1 player");
    m_1Player.setSize({200,71});
    m_1Player.setPosition({m_0Player.getPosition().x + m_0Player.getDimensions().x + 100, (static_cast<float>(windowHeight)-500)});

    mAI_Player.setText("AI player");
    mAI_Player.setSize({200,71});
    mAI_Player.setPosition({m_1Player.getPosition().x + m_1Player.getDimensions().x + 100, (static_cast<float>(windowHeight)-500)});

}

void Menu::run()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

    sf::Sprite background(mBackground);
    mTitlePosition.x = windowWidth/2;
    mTitlePosition.y = windowHeight/4;
    mTitle.setPosition(mTitlePosition);


    while (window.isOpen())
    {
       sf::Event event;
    //    playMusic();
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
            m_0Player.update(event, window);
            m_1Player.update(event, window);
            mAI_Player.update(event, window);
       }

       window.clear();
       window.draw(background);
       window.draw(mTitle);
       window.draw(m_0Player);
       window.draw(m_1Player);
       window.draw(mAI_Player);
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


//cs textbooks
// modern programming languages 2nd edition by adam boroks webber
// understanding unix/linux programming by bruce molay 