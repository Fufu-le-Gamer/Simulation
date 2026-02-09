#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Buildings
{
public:
	Buildings(const sf::Font& font,
		const std::string& label,
		const sf::Vector2f& size,
		const sf::Vector2f& origin,
		const sf::Vector2f& position,
		const sf::Color& color,
		float rotationDeg = 0.f);

	void draw(sf::RenderWindow& window) const;

	sf::RectangleShape& shape();
	sf::Text& text();

private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
};

