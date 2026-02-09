#include "Buildings.h"

Buildings::Buildings(const sf::Font& font,
					 const std::string& label,
					 const sf::Vector2f& size,
					 const sf::Vector2f& origin,
                     const sf::Vector2f& position,
					 const sf::Color& color,
					 float rotationDeg)
    :m_text(font)
{
    m_shape.setSize(size);
    m_shape.setFillColor(color);
    m_shape.setOrigin(origin);
    m_shape.setRotation(sf::degrees(rotationDeg));
    m_shape.setPosition(position);

    m_text.setString(label);
    m_text.setCharacterSize(30);
    m_text.setFillColor(sf::Color::Black);

    m_text.setOrigin(origin);

    m_text.setPosition(position);    
    m_text.setRotation(sf::degrees(rotationDeg));
}

void Buildings::draw(sf::RenderWindow& window) const
{
    window.draw(m_shape);
    window.draw(m_text);
}

sf::RectangleShape& Buildings::shape()
{
    return m_shape;
}

sf::Text& Buildings::text()
{
    return m_text;
}
