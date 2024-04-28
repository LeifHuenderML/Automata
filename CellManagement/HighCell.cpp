#include "HighCell.hpp"

HighCell::HighCell(int x, int y, bool alive)
{
	m_Colors = { sf::Color(143, 188, 187, 255), sf::Color(0xebcb8bff), sf::Color(46, 52, 64, 255) };

	m_Location.x = x;
	m_Location.y = y;
	m_IsAlive = alive;
	m_AliveColor = m_Colors[0];
	m_DeadColor = m_Colors[2];
}

sf::Vector2f HighCell::getLocation() const

{
	return m_Location;
}

void HighCell::setAliveColor(sf::Color color) {
	m_AliveColor = color;
}

sf::Color HighCell::getAliveColor() const {
	return m_AliveColor;
}

sf::Color HighCell::getDeadColor() const {
	return m_DeadColor;
}

void HighCell::switchState() {
	m_IsAlive = !m_IsAlive;
}