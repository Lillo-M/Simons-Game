#include "Game.h"
#include <stdio.h>

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"),
	player(sf::Vector2f(10, 10), sf::Vector2f(100, 100)),
	eManager(window, player)
{
	Entity::setWindow(window);
	window.setFramerateLimit(FPS);
	Executar();
}

Game::~Game()
{
}

void Game::Executar()
{
	while (window.isOpen())
	{
		eManager.Manage();
		player.Move();
		window.clear();
		player.Draw();
		window.display();
	}
}