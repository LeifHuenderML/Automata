/**
 * @file Button.hpp
 * @author Shaun Swant (sswant@students.nic.edu)
 * @brief 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

enum state {normal, hovered, clicked};

class Button: public sf::Drawable
{
public:
    //Default constructor that loads texture from file “button.png” and font from “college.ttf” file.
    //set texture for mButton, set the origin to the middle of the button (texture), 
    //set color to White, position to {300,100}, set state to normal, and scale to 100%
    //set font for the text, set the size of the text to the half of Button size, set the origin to the middle of the text 
    //and set position at the middle of the button, assign “Push me!” as a string of the button
    Button();
    //Constructor that sets button label to s, button position to the position,  button size to size (given in pixels), and button color to color.
    Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color, int num);
    ~Button(){};
    //change button position to position (what else needs to be changed?)
    void setPosition(sf::Vector2f position);
    //change button size to size (what else needs to be changed?)
    void setSize(sf::Vector2f  size);
    //change button label to s (what else needs to be changed?)
    void setText(std::string s);
    void setColorTextNormal(sf::Color textNormalColor){mTextNormal = textNormalColor;};
    void setColorTextHover(sf::Color textHoverColor){mTextHover = textHoverColor;};
    void setNum(int num);

    sf::Vector2f getPosition(){return mPosition;};
    sf::Vector2f getDimensions(){return sf::Vector2f(mButton.getGlobalBounds().width, mButton.getGlobalBounds().height);};
    sf::Uint32 getState(){return mBtnState;};

    //This function update the button state and/or look
    int update(sf::Event& e, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    //Button
    sf::Sprite mButton;
    sf::Texture mTexture;
    sf::Color mButtonColor = sf::Color(76,86,106,255);
    sf::Vector2f mPosition;
    sf::Uint32 mBtnState;
    int btnNum;
    
    //text
    sf::Text mText;
    sf::Font mFont;
    sf::Color mTextNormal = sf::Color(229,233,240,255);
    sf::Color mTextHover  = sf::Color(129,161,193,255);
};

#endif