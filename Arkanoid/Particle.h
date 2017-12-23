#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Entity.h"

class Particle : public Entity
{
private:
	sf::Vector2f start_pos;
	bool m_recreated;
public:
	Particle(sf::Vector2f size, sf::Vector2f position);

	virtual void update(float updateTime) override;
	void recreate();
	void collapse();

	~Particle();
};

