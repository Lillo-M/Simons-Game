#include "Game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"),
	eManager(window)
{
	Entities::Entity* pAux;
	entities.clear();
	player = new Entities::Player(sf::Vector2f(500.f, 150.f), sf::Vector2f(61.f, 100.f));
	entities.push_back(player);
	lentities.insert_back(player);
	eManager.setpPlayer(player);
	for (int i = 0; i < 10; i++)
	{
		pAux = new Entities::Ground(sf::Vector2f(64.f + i * 128.f, 700.f), sf::Vector2f(128.f, 128.f));
		entities.push_back(pAux);
		lentities.insert_back(pAux);
	}
	pAux = new Entities::Ground(sf::Vector2f(300.f, 500.f), sf::Vector2f(128.f, 128.f));
	entities.push_back(pAux);
	lentities.insert_back(pAux);
	pAux = new Entities::Ground(sf::Vector2f(1000.f, 500.f), sf::Vector2f(128.f, 128.f));
	entities.push_back(pAux);
	lentities.insert_back(pAux);
	settings.antialiasingLevel = 16;
	Entities::Entity::setWindow(window);
	window.setFramerateLimit(FPS);
	entIt = entities.begin();
	CManager.getList(lentities);
	Executar();
}

Game::~Game()
{
	for (entIt; entIt != entities.end(); entIt++)
	{
		delete (*entIt);
	}
	lentities.clear();
	entities.clear();
}

void Game::Executar()
{ 
	while (window.isOpen())
	{
		eManager.Manage();
		/*for (entIt; entIt != entities.end(); entIt++)
		{
			(*entIt)->Move();
		}*/
		for (unsigned int i = 0; i < Entities::Entity::getContEntities(); i++)
		{
			lentities[i]->Move();
		}
		Entities::Entity::updateDeltaTime();
		CManager.Manage();
		entIt = entities.begin();
		window.clear();
		/*for (entIt; entIt != entities.end(); entIt++)
		{
			(*entIt)->Draw();
		}*/
		for (unsigned int i = 0; i < Entities::Entity::getContEntities(); i++)
		{
			lentities[i]->Draw();
		}
		entIt = entities.begin();
		window.display();
		//Sleep(8);
	}
}