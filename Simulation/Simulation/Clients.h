#pragma once
#include <SFML/Graphics.hpp>

class Clients
{
public:
	Clients(const sf::Vector2f& pnjsize,
		float spawn,
		float speed);

	void update(float deltaTime);
	void draw(sf::RenderWindow& win)const;

private:
	sf::RectangleShape m_pnj;
	float m_speed;
	float m_spawn;
	
};

