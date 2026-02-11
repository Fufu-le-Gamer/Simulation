#include "Clients.h"

Clients::Clients(float radius,
	float spawn,
	float speed)
	:m_pnj(radius),
	m_speed(speed),
	m_spawn(spawn)
{
	m_pnj.setFillColor(sf::Color::Green);
	m_pnj.setPosition({ -60.f, spawn - radius });
}

void Clients::update(float deltaTime)
{
	m_pnj.move({m_speed * deltaTime, 0.f });

	if (m_pnj.getPosition().x > 850.f)
	{
		m_pnj.setPosition({ -60.f, m_spawn - m_pnj.getRadius()});
	}
}

void Clients::draw(sf::RenderWindow& win) const
{
	win.draw(m_pnj);
}