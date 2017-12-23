#include "Ball.h"



Ball::Ball(sf::Vector2f size, sf::Vector2f position) : particleList(0)
{
	ballPos = position;
	m_velocity = sf::Vector2f(100.f, 100.f);

	//fill the ball map
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_ballMap[i][j] = true;
			sf::RectangleShape shape;
			shape.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
			shape.setPosition(sf::Vector2f(j*TILE_SIZE + position.x, i*TILE_SIZE + position.y));
			ball.push_back(shape);
		}
	}
}

void Ball::update(float updateTime)
{
	int pos = -1;
	if (this->getPosition().x < 0 || this->getPosition().x + this->getSize().x > 800) {
		m_velocity.x = -m_velocity.x;
		pos = rand() % 100;
		ball[pos].setFillColor(sf::Color::Black);
	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getSize().y > 600) {
		m_velocity.y = -m_velocity.y;
		pos = rand() % 100;
		ball[pos].setFillColor(sf::Color::Black);
	}
	if (pos != -1) {
		Particle* particle = new Particle(sf::Vector2f(TILE_SIZE, TILE_SIZE), sf::Vector2f(pos % 10 * TILE_SIZE + ballPos.x, pos / 10 * TILE_SIZE + ballPos.y));
		particleList.push_back(particle);
	}

	ballPos += m_velocity*updateTime;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			ball[i * 10 + j].setPosition(sf::Vector2f(j*TILE_SIZE + ballPos.x, i*TILE_SIZE + ballPos.y));

	for (auto p : particleList)
		(*p).update(updateTime);
}

sf::Vector2f Ball::getSize()
{
	return sf::Vector2f(10 * TILE_SIZE, 10 * TILE_SIZE);
}

Ball::~Ball()
{
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	states.texture = nullptr;
	for (auto a : ball)
		target.draw(a);
}
