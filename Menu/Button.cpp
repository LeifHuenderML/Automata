/**
 * @file Button.cpp
 * @author Shaun Swant (sswant@students.nic.edu)
 * @brief 
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Button.hpp"

 
/**
 * @brief Construct a new Button:: Button object
 * 
 */
Button::Button()
{   
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
    }
    // mTexture.loadFromFile("docs/images/button.png");
    //Button operations
    if (!mTexture.loadFromFile("docs/images/button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mButton.setTexture(mTexture);
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    mPosition={300,200};
    mButton.setPosition(mPosition.x, mPosition.y);
    mBtnState = 0;
    mButton.setScale(.5,.5);

    // mFont.loadFromFile("docs/ages/college.ttf");
    //Font operations
    if (!mFont.loadFromFile("docs/images/Roboto-Bold.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    mText.setString("Push me!");
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
    
}

/**
 * @brief Construct a new Button:: Button object
 * 
 * @param s 
 * @param position 
 * @param size 
 * @param color 
 */
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color, int num)
{   
    btnNum = num;
    // mTexture.loadFromFile("Menu/docs/images/button.png");
    //Button operations
    if (!mTexture.loadFromFile("docs/images/button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    mButton.setTexture(mTexture);
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    mButton.setColor(color);
    mPosition = position;
    mButton.setPosition(mPosition.x, mPosition.y);
    mBtnState = 0;
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);

    // mFont.loadFromFile("Menu/docsages/college.ttf");
    //Font operations
    if (!mFont.loadFromFile("docs/images/Roboto-Bold.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mText.setFont(mFont);
    mText.setString(s);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);

}

void Button::setNum(int num)
{
    btnNum = num;
}

/**
 * @brief 
 * 
 * @param position 
 */
void Button::setPosition(sf::Vector2f position)
{
    mPosition.x = position.x;
    mPosition.y = position.y;
    mButton.setPosition(mPosition);

    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

/**
 * @brief 
 * 
 * @param size 
 */
void Button::setSize(sf::Vector2f  size)
{
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

//change button label to s (what else needs to be changed?)
void Button::setText(std::string s)
{
    mText.setString(s);
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);
}

//This function update the button state and/or look
int Button::update(sf::Event& e, sf::RenderWindow& window)
{
    if (e.type == sf::Event::Closed)
        window.close();

    //get position of the mouse
    sf::Vector2i m2Position = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(m2Position);
    bool mouseInButton =    mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
                            && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
                            && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
                            && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mText.setFillColor(mTextHover);
        }
        else
        {
            mText.setFillColor(mTextNormal);
        }
    }
    if (e.type == sf::Event::MouseButtonPressed && mouseInButton)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mButton.setRotation(180);
            }
            else
            {
                mButton.setRotation(0);
            }
            return btnNum;
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                mText.setFillColor(mTextHover);
                mButton.setRotation(0);
            }
            else
            {
                mText.setFillColor(mTextNormal);
                mButton.setRotation(0);
            }
        }
    }
    return 0;
}

void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}