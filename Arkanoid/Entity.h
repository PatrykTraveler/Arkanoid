#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Vector2f m_velocity;
	sf::RectangleShape m_shape;

	sf::Vector2f getVelocity() {
		return this->m_velocity;
	}
	sf::Vector2f getPosition() {
		return this->m_shape.getPosition();
	}
	sf::Vector2f getSize() {
		return this->m_shape.getSize();
	}
	void setVelocity(sf::Vector2f velocity) {
		this->m_velocity = velocity;
	}
	void setPosition(sf::Vector2f position) {
		this->m_shape.setPosition(position);
	}
	void setPosition(float x, float y) {
		this->m_shape.setPosition(x, y);
	}
public:
	Entity();
	~Entity();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float updateTime) = 0;
};

