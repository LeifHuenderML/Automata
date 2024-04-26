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
    m_0Player.setNum(1);

    m_1Player.setText("1 player");
    m_1Player.setSize({200,71});
    m_1Player.setPosition({m_0Player.getPosition().x + m_0Player.getDimensions().x + 100, (static_cast<float>(windowHeight)-500)});
    m_1Player.setNum(2);

    mAI_Player.setText("AI player");
    mAI_Player.setSize({200,71});
    mAI_Player.setPosition({m_1Player.getPosition().x + m_1Player.getDimensions().x + 100, (static_cast<float>(windowHeight)-500)});
    mAI_Player.setNum(3);

}

void Menu::run() {
    mainPage();
    // secondPage();
    game();
}

void Menu::mainPage() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");
    sf::Sprite background(mBackground);
    mTitlePosition.x = windowWidth / 2;
    mTitlePosition.y = windowHeight / 4;
    mTitle.setPosition(mTitlePosition);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            m1 = m_0Player.update(event, window);
            m2 = m_1Player.update(event, window);
            m3 = mAI_Player.update(event, window);

            if (m1 == 1 || m2 == 2 || m3 == 3) 
            {
                std::cout << "Button pressed" << std::endl;
                break;
            }
            
        }

        if (m1 == 1 || m2 == 2 || m3 == 3) 
        {
            std::cout << "Button pressed" << std::endl;

            m_0Player.setText("Conway");
            m_1Player.setText("Rainbow");
            mAI_Player.setText("HighLife");

            while (window.isOpen()) 
            {
                sf::Event event;
                while (window.pollEvent(event)) 
                {
                    if (event.type == sf::Event::Closed)
                        window.close();

                    s1 = m_0Player.update(event, window);
                    s2 = m_1Player.update(event, window);
                    s3 = mAI_Player.update(event, window);

                    if (s1 == 1 || s2 == 2 || s3 == 3) 
                    {
                        std::cout << "Button pressed" << std::endl;
                        break;
                    }

                
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

// void Menu::secondPage() {

//     m_0Player.setText("Conway");
//     m_1Player.setText("Rainbow");
//     mAI_Player.setText("HighLife");

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             s1 = m_0Player.update(event, window);
//             s2 = m_1Player.update(event, window);
//             s3 = mAI_Player.update(event, window);

//             if (s1 == 1 || s2 == 2 || s3 == 3) {
//                 std::cout << "Button pressed" << std::endl;
//                 break;
//             }

            
//         }

//         if (s1 == 1 || s2 == 2 || s3 == 3) {
//                 break;
//         }

//         window.clear();
//         window.draw(background);
//         window.draw(mTitle);
//         window.draw(m_0Player);
//         window.draw(m_1Player);
//         window.draw(mAI_Player);
//         window.display();
//     }
//     window.close();
//     std::cout << m1 << " " << m2 << " " << m3 << std::endl;
//     std::cout << s1 << " " << s2 << " " << s3 << std::endl;
// }


// void Menu::run()
// {
//     sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

//     sf::Sprite background(mBackground);
//     mTitlePosition.x = windowWidth/2;
//     mTitlePosition.y = windowHeight/4;
//     mTitle.setPosition(mTitlePosition);
    


//     while (window.isOpen())
//     {
//        sf::Event event;
        
//     //    playMusic();
//        while (window.pollEvent(event))
//        {
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             m1 = m_0Player.update(event, window);
//             m2 = m_1Player.update(event, window);
//             m3 = mAI_Player.update(event, window);
            
//        }
//        if(m1 == 1 || m2 == 2 || m3 == 3){
//                 std::cout << "Button pressed" << std::endl;
//                 break;
//         }
       

//        window.clear();
//        window.draw(background);
//        window.draw(mTitle);
//        window.draw(m_0Player);
//        window.draw(m_1Player);
//        window.draw(mAI_Player);
//        window.display();
//     }
    
//     window.close();
//     //-=======================

//     sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Menu");

//     sf::Sprite background(mBackground);
//     mTitlePosition.x = windowWidth/2;
//     mTitlePosition.y = windowHeight/4;
//     mTitle.setPosition(mTitlePosition);

//     m_0Player.setText("Conway");
//     m_1Player.setText("Rainbow");
//     mAI_Player.setText("HighLife");
//     int s1;
//     int s2;
//     int s3;

//     while (window.isOpen())
//     {
//        sf::Event event;
        
//     //    playMusic();
//        while (window.pollEvent(event))
//        {
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             s1 = m_0Player.update(event, window);
//             s2 = m_1Player.update(event, window);
//             s3 = mAI_Player.update(event, window);
            
//        }
//        if(s1 == 1 || s2 == 2 || s3 == 3){
//                 std::cout << "Button pressed" << std::endl;
//                 break;
//         }
       

//        window.clear();
//        window.draw(background);
//        window.draw(mTitle);
//        window.draw(m_0Player);
//        window.draw(m_1Player);
//        window.draw(mAI_Player);
//        window.display();
//     }

//     std::cout << m1 << " " << m2 << " " << m3 << std::endl;
//     std::cout << s1 << " " << s2 << " " << s3 << std::endl;

//     window.close();

// }

       

       
       

void Menu::playMusic(){
    //load a soundtrack and error check
    sf::Music music;
    if (!music.openFromFile("music/nordic study session ~ chill lofi beats Credit: @CozyNordic.mp3")){
        throw std::runtime_error("Error opening music");
    }
    //play the music
    music.play();
}


// void Menu::navigateToNewWindow(int state) {
//     // Create a new window or scene based on the state
//     std::cout << "Navigating to new window with state: " << state << std::endl;
//     // Function to create and display the new window based on the game state
//     sf::RenderWindow newStateWindow(sf::VideoMode(windowWidth, windowHeight), "Game State Window");

//     // // Buttons for the new window
//     // Button gofButton("GOF", mFont, 3);
//     // Button rainbowButton("RainBow", mFont, 4);
//     // Button highButton("High", mFont, 5);

//     // // Set positions for new buttons
//     // gofButton.setPosition(windowWidth / 4);
//     // rainbowButton.setPosition(windowWidth / 2);
//     // highButton.setPosition(3 * windowWidth / 4);

//     // // Set the title according to the state
//     // mTitle.setString("Game State: " + std::to_string(state));
//     // mTitle.setPosition(windowWidth / 2, windowHeight / 4);

//     // // Event loop for the new window
//     // while (newStateWindow.isOpen()) {
//     //     sf::Event event;
//     //     while (newStateWindow.pollEvent(event)) {
//     //         if (event.type == sf::Event::Closed)
//     //             newStateWindow.close();

//     //         if (event.type == sf::Event::MouseButtonPressed) {
//     //             if (gofButton.isMouseOver(newStateWindow)) {
//     //                 std::cout << "GOF Button pressed." << std::endl;
//     //                 // Implement functionality for GOF button
//     //             }
//     //             if (rainbowButton.isMouseOver(newStateWindow)) {
//     //                 std::cout << "RainBow Button pressed." << std::endl;
//     //                 // Implement functionality for Rainbow button
//     //             }
//     //             if (highButton.isMouseOver(newStateWindow)) {
//     //                 std::cout << "High Button pressed." << std::endl;
//     //                 // Implement functionality for High button
//     //             }
//     //         }
//     //     }

//         newStateWindow.clear();
//         newStateWindow.draw(background);
//         newStateWindow.draw(mTitle);
//         gofButton.draw(newStateWindow);
//         rainbowButton.draw(newStateWindow);
//         highButton.draw(newStateWindow);
//         newStateWindow.display();
//     // }
// }


// cs textbooks
// modern programming languages 2nd edition by adam boroks webber
// understanding unix/linux programming by bruce molay 


void Menu::game(){
    srand(time(0));
    Grid grid;
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Automota");

    while (window.isOpen())

    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))

        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        grid.createImage();
        grid.updateGrid();
        grid.draw(window);

        window.display();
    }

}