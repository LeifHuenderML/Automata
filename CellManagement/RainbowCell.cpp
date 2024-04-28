#include "RainbowCell.hpp"

RainbowCell::RainbowCell(int x, int y, bool alive)

{
	//Red = sf::Color(0xbf616a);
	//Orange = sf::Color(0xd08770);
	//Yellow = sf::Color(0xebcb8b);
	//Green = sf::Color(0xa3be8c);
	//Purple = sf::Color(0xb48ead);
	m_Colors = { sf::Color(0xbf616a), sf::Color(0xd08770ff), sf::Color(0xebcb8bff), sf::Color(0xa3be8cff), sf::Color(0xb48eadff), sf::Color(46, 52, 64, 255) };

	m_Location.x = x;
	m_Location.y = y;
	m_IsAlive = alive;
	m_AliveColor = m_Colors[rand() % 5];
	m_DeadColor = m_Colors[5];
}

void RainbowCell::setAliveColor(sf::Color color) {
	m_AliveColor = color;
}

sf::Color  RainbowCell::getAliveColor() const
{
	return m_AliveColor;
}

sf::Color RainbowCell::getDeadColor() const
{
	return m_DeadColor;
}

void RainbowCell::switchState() {
	m_IsAlive = !m_IsAlive;
}