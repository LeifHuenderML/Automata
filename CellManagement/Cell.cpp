#include "Cell.hpp"

Cell::Cell(int x, int y, bool alive)

{
	m_Location.x = x;
	m_Location.y = y;
	m_IsAlive = alive;
	m_AliveColor = sf::Color(143, 188, 187, 255);
	m_DeadColor = sf::Color(46, 52, 64, 255);
}

sf::Vector2f Cell::getLocation() const

{
	return m_Location;
}

void Cell::setLocation(float x, float y)

{
	m_Location.x = x;
	m_Location.y = y;
}
 
bool Cell::getIsAlive() const

{
	return m_IsAlive;
}

void Cell::setState(bool state)

{
	m_IsAlive = state;
}

void Cell::setAliveColor(sf::Color color) {
	m_AliveColor = color;
}

sf::Color Cell::getAliveColor() const
{
	return m_AliveColor;
}

sf::Color Cell::getDeadColor() const
{
	return m_DeadColor;
}

void Cell::switchState() {
	m_IsAlive = !m_IsAlive;
}