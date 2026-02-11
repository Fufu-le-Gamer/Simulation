#pragma once
#include <SFML/Graphics.hpp>

class Clients
{
public:
	Clients(float radius,
		float spawn,
		float speed);

	void update(float deltaTime);
	void draw(sf::RenderWindow& win)const;

private:
	sf::CircleShape m_pnj;
	float m_speed;
	float m_spawn;
	
};

