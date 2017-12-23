#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int WIDTH = 50;
const int HEIGHT = 30;

class BlockMap 
{
public:
	BlockMap();
	void draw(sf::RenderWindow& window)
	{
		for (auto i : m_blocks)
			window.draw(i);
	}
	~BlockMap();
private:
	std::vector <sf::RectangleShape> m_blocks;
};

