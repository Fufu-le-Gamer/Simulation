#include "Clients.h"

Clients::Clients(const sf::Vector2f& pnj_size,
	float spawn,
	float speed)
	:m_pnj(),
	m_speed(speed),
	m_spawn(spawn)
{
	m_pnj.setSize(pnj_size);
	m_pnj.setFillColor(sf::Color::Green);
	m_pnj.setPosition({ -100.f, spawn });
}

void Clients::update(float deltaTime)
{
	m_pnj.move({m_speed * deltaTime, 0.f });

	if (m_pnj.getPosition().x > 850.f)
	{
		m_pnj.setPosition({ -100.f, m_spawn });
	}
}

void Clients::draw(sf::RenderWindow& win) const
{
	win.draw(m_pnj);
}