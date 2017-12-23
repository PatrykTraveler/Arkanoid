#pragma once
#include <SFML/Graphics.hpp>
#include <list>

#include "Entity.h"
#include "Particle.h"
class Ball : public Entity
{
	enum Direction {
		UP, DOWN, LEFT, RIGHT
	};
public:
	std::list<Particle*> particleList;

	Ball(sf::Vector2f size, sf::Vector2f position);
	
	virtual void update(float updateTime) override;
	sf::Vector2f getSize();
	sf::Vector2f getPosition(){
		return ball[0].getPosition();
	}
	~Ball();
private:
	bool m_ballMap[10][10];
	sf::Vector2f ballPos;
	std::vector<sf::RectangleShape> ball;
	const float TILE_SIZE = 3.f;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

