#include "Entity.h"

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	states.texture = nullptr;
	target.draw(m_shape, states);
}

Entity::Entity()
{
}


Entity::~Entity()
{
}
