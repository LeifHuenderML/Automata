/**
 * @file Menu.cpp
 * @author Shaun Swant
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

    if (!mBackground.loadFromFile("docs/images/bg2.png"))
    {
        std::cout << "Error opening file\n";
        exit(1);
    }
    mFont.loadFromFile("docs/images/Atop-R99O3.ttf");

    mTitle.setFont(mFont);
    mTitle.setString("AUTOMATA");
    mTitle.setCharacterSize(155);
        mTitle.setFillColor(sf::Color(180, 142, 173, 255));  


    mTitle.setPosition(1024 / 2.0f, 1024 * 0.2f);  
    mTitle.setOrigin(mTitle.getGlobalBounds().width / 2.0f, mTitle.getGlobalBounds().height / 2.0f);

    const float buttonWidth = 200.0f;
    const float buttonHeight = 71.0f;
    const float gapBetweenButtons = 100.0f;
    const float buttonYPosition = static_cast<float>(windowHeight) - 400;
    const int screenWidth = 1024;

        
    float totalWidth = 1024;  
    float initialXPosition = 1024/4.8;  

    m_0Player.setText("0 player");
    m_0Player.setSize({buttonWidth, buttonHeight});
    m_0Player.setPosition({initialXPosition, buttonYPosition});
    m_0Player.setNum(1);

    m_1Player.setText("1 player");
    m_1Player.setSize({buttonWidth, buttonHeight});
    m_1Player.setPosition({initialXPosition + buttonWidth + gapBetweenButtons, buttonYPosition});
    m_1Player.setNum(2);

    mAI_Player.setText("AI player");
    mAI_Player.setSize({buttonWidth, buttonHeight});
    mAI_Player.setPosition({initialXPosition + 2 * (buttonWidth + gapBetweenButtons), buttonYPosition});
    mAI_Player.setNum(3);
}



void Menu::run() {
    mainPage();
    secondPage();
}

void Menu::mainPage() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");
    sf::Sprite background(mBackground);
    mTitlePosition.x = windowWidth / 2;
    mTitlePosition.y = windowHeight / 4;
    mTitle.setPosition(mTitlePosition);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            m1 = m_0Player.update(event, window);
            m2 = m_1Player.update(event, window);
            m3 = mAI_Player.update(event, window);

            if (m1 == 1 || m2 == 2 || m3 == 3) {
                std::cout << "Button pressed" << std::endl;
                break;
            }
            
        }
        if (m1 == 1 || m2 == 2 || m3 == 3) {
                std::cout << "Button pressed" << std::endl;
                break;
        }

        window.clear();
        window.draw(background);
        window.draw(mTitle);
        window.draw(m_0Player);
        window.draw(m_1Player);
        window.draw(mAI_Player);
        window.display();
    }
    window.close();
}

void Menu::secondPage() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");
    sf::Sprite background(mBackground);
    mTitlePosition.x = windowWidth / 2;
    mTitlePosition.y = windowHeight / 4;
    mTitle.setPosition(mTitlePosition);

    m_0Player.setText("Conway");
    m_1Player.setText("Rainbow");
    mAI_Player.setText("HighLife");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            s1 = m_0Player.update(event, window);
            s2 = m_1Player.update(event, window);
            s3 = mAI_Player.update(event, window);

            if (s1 == 1 || s2 == 2 || s3 == 3) {
                std::cout << "Button pressed" << std::endl;
                break;
            }

            
        }

        if (s1 == 1 || s2 == 2 || s3 == 3) {
                break;
        }

        window.clear();
        window.draw(background);
        window.draw(mTitle);
        window.draw(m_0Player);
        window.draw(m_1Player);
        window.draw(mAI_Player);
        window.display();
    }
    window.close();
    std::cout << m1 << " " << m2 << " " << m3 << std::endl;
    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
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



// cs textbooks
// modern programming languages 2nd edition by adam boroks webber
// understanding unix/linux programming by bruce molay 


// void Menu::game(){
//     srand(time(0));
//     Grid grid;
//     sf::RenderWindow window(sf::VideoMode(1024, 1024), "Automota");

//     while (window.isOpen())

//     {
//         // check all the window's events that were triggered since the last iteration of the loop
//         sf::Event event;
//         while (window.pollEvent(event))

//         {
//             // "close requested" event: we close the window
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         grid.createImage();
//         grid.updateGrid();
//         grid.draw(window);

//         window.display();
//     }

// }


int Menu::get_player(){
    if(s1 == 1){
        return 1;
    }
    else if(s2 == 2){
        return 2;
    }
    else if(s3 == 3){
        return 3;
    }
    else{
        return -1;
    }
}
int Menu::get_mode(){
    if(m1 == 1){
        return 1;
    }
    else if(m2 == 2){
        return 2;
    }
    else if(m3 == 3){
        return 3;
    }
    else{
        return -1;
    }
}