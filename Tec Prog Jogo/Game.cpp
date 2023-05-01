#include "Game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"),
	eManager(window)
{
	entities.clear();
	player = new Entities::Player(sf::Vector2f(500, 150), sf::Vector2f(61, 100));
	entities.push_back(player);
	eManager.setpPlayer(player);
	for (int i = 0; i < 10; i++)
	{
		entities.push_back(new Entities::Ground(sf::Vector2f(64 + i*128, 700), sf::Vector2f(128, 128)));
	}
	entities.push_back(new Entities::Ground(sf::Vector2f(300, 500), sf::Vector2f(128, 128)));
	entities.push_back(new Entities::Ground(sf::Vector2f(1000, 500), sf::Vector2f(128, 128)));
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
	entities.clear();
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
		Entities::Entity::updateDeltaTime();
		CManager.Manage();
		entIt = entities.begin();
		window.clear();
		for (entIt; entIt != entities.end(); entIt++)
		{
			(*entIt)->Draw();
		}
		entIt = entities.begin();
		window.display();
		//Sleep(8);
	}
}