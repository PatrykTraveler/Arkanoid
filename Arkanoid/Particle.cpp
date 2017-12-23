#include "Particle.h"

Particle::Particle(sf::Vector2f size, sf::Vector2f position)
{
	collapse();
	this->start_pos = position;
	this->m_recreated = false;

	m_shape.setSize(size);
	m_shape.setPosition(position);
}

void Particle::update(float updateTime)
{
	if (!m_recreated) {
		if (getPosition().x + this->getSize().x > 800 || getPosition().x < 0)
			this->m_velocity.x = -this->m_velocity.x;

		if (getPosition().y + this->getSize().y < 600)
			this->m_velocity.y += 980.0f * updateTime;
		else {
			this->m_velocity.y = -this->m_velocity.y * 0.5f;
			this->m_velocity.x = this->m_velocity.x*((rand() % 2 - 1) < 0 ? -1 : 1)*0.5f;
		}

		/*if (std::abs(this->m_velocity.y) < 0.001f) {
			this->m_velocity.y = 0.0f;
			this->m_velocity.x = 0.0f;
			setPosition(getPosition().x, 600.0f-this->getSize().y);
		}*/
	}
	else {
		if (std::abs(this->start_pos.x - getPosition().x) < 0.1f || std::abs(getPosition().y - this->start_pos.y) < 0.1f) {
			this->m_shape.setPosition(start_pos);
			m_velocity = sf::Vector2f(0.f, 0.f);
		}
	}
		this->m_shape.move(m_velocity*updateTime);
}

void Particle::recreate()
{
	m_recreated = true;
	float velX = this->start_pos.x - getPosition().x;
	float velY = this->start_pos.y - getPosition().y;
	sf::Vector2f moveVec = sf::Vector2f(velX, velY) / sqrtf(velX*velX + velY*velY);
	m_velocity = moveVec*250.0f;
}

void Particle::collapse()
{
	m_recreated = false;
	int direction_x = (rand() % 2 - 1) < 0 ? -1 : 1;
	int direction_y = (rand() % 2 - 1) < 0 ? -1 : 1;
	float value_x = (float)(rand() % 25 + 10);
	float value_y = (float)(rand() % 25 + 10);
	m_velocity = sf::Vector2f(direction_x*value_x, direction_y*value_y);
}


Particle::~Particle()
{
}
