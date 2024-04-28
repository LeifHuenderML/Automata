#pragma once

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

class RainbowCell : public Cell{
public:
    RainbowCell(int x = 0, int y = 0, bool alive = 0);

    void setAliveColor(sf::Color color);

    sf::Color getAliveColor() const;

    sf::Color getDeadColor() const;

    void switchState();
private:
    std::vector<sf::Color> m_Colors;
};