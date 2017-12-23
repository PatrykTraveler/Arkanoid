#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <list>
#include <string>
#include <iostream>

#include "Particle.h"
#include "Entity.h"
#include "Ball.h"

const float TILE_SIZE = 3.0f;
const int START_POS = 200;
const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "test");
	bool to_update = false, recreate = false;
	Ball ball(sf::Vector2f(TILE_SIZE * 10, TILE_SIZE * 10), sf::Vector2f(500.0f, 500.0f));

	float updateTime;
	sf::Clock clock;
	while (window.isOpen()) {
		updateTime = clock.restart().asSeconds();
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		ball.update(updateTime);

		window.clear();
		window.draw(ball);
		for (auto i : ball.particleList)
			window.draw(*i);
		window.display();
	}
}