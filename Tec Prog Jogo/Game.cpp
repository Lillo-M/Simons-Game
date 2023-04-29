#include "Game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"),
	eManager(window)
{
	player = new Entities::Player(sf::Vector2f(10, 10), sf::Vector2f(61, 100));
	entities.push_back(player);
	eManager.setpPlayer(player);
	entities.push_back(new Entities::Ground(sf::Vector2f(640, 700), sf::Vector2f(1280, 40)));
	settings.antialiasingLevel = 16;
	Entities::Entity::setWindow(window);
	window.setFramerateLimit(FPS);
	entIt = entities.begin();
	CManager.getList(entities);
	Executar();
}

Game::~Game()
{
	for (entIt; entIt != entities.end(); entIt++)
	{
		delete (*entIt);
	}
}

void Game::Executar()
{ 
	while (window.isOpen())
	{
		eManager.Manage();
		for (entIt; entIt != entities.end(); entIt++)
		{
			(*entIt)->Move();
		}
		CManager.Manage();
		entIt = entities.begin();
		window.clear();
		for (entIt; entIt != entities.end(); entIt++)
		{
			(*entIt)->Draw();
		}
		entIt = entities.begin();
		window.display();
		Entities::Entity::restartClock();
		Sleep(8);
	}
}