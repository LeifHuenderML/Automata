#pragma once

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

class HighCell : public Cell
{
public:
	std::vector<sf::Color> m_Colors;

	HighCell(int x = 0, int y = 0, bool alive = 0);

	void setAliveColor(sf::Color color);

	sf::Vector2f getLocation() const;

	sf::Color getAliveColor() const;

	sf::Color getDeadColor() const;

	void switchState();

};