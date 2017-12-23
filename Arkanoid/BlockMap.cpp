#include "BlockMap.h"

BlockMap::BlockMap()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 800 / WIDTH; j++)
		{
			sf::RectangleShape p;
			p.setPosition(sf::Vector2f(j*WIDTH, i*HEIGHT));
			p.setSize(sf::Vector2f(WIDTH, HEIGHT));
			p.setFillColor(sf::Color::Green);
			m_blocks.push_back(p);
		}
	}
}


BlockMap::~BlockMap()
{
}

