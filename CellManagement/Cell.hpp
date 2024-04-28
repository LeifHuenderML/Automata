#pragma once

#include <SFML/Graphics.hpp>

class Cell
{
public:
	Cell(int x = 0, int y = 0, bool alive = 0);

	sf::Vector2f getLocation() const;

	void setLocation(float x, float y);

	bool getIsAlive() const;

	void setState(bool state);

	void setAliveColor(sf::Color color);

	sf::Color getAliveColor() const;

	sf::Color getDeadColor() const;

	void switchState();

protected:
	sf::Vector2f m_Location;
	sf::Color m_AliveColor;
	sf::Color m_DeadColor;
	bool m_IsAlive;
};