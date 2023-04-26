#include "Game.h"

Game::Game() :
	window(sf::VideoMode(200, 200), "SFML works!"),
	shape(100.f),
	player(sf::Vector2f(10, 10), sf::Vector2f(10, 10))
{
	Entity::setWindow(window);
	shape.setFillColor(sf::Color::Green);
	Executar();
}

Game::~Game()
{
}

void Game::Executar()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		player.Draw();
		window.display();
	}
}