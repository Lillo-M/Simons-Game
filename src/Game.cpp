#include "../include/Game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), "Simon's Game"),
	eManager(window)
{
	Entities::Entity* pAux;
	player = new Entities::Player(sf::Vector2f(500.f, 592.f), sf::Vector2f(61.f, 100.f));
	lentities.insert_back(player);
	eManager.setpPlayer(player);
	for (int i = 0; i < 10; i++)
	{
		pAux = new Entities::Ground(sf::Vector2f(64.f + i * 128.f, 656.f), sf::Vector2f(128.f, 128.f));
		if(pAux)
			lentities.insert_back(pAux);
		else
		{
			std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
		}
		pAux = NULL;
	}
	pAux = new Entities::Ground(sf::Vector2f(300.f, 400.f), sf::Vector2f(128.f, 128.f));
	if(pAux)
		lentities.insert_back(pAux);
	else
	{
		std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
	}
	pAux = new Entities::Ground(sf::Vector2f(1000.f, 400.f), sf::Vector2f(128.f, 128.f));
	if(pAux)
		lentities.insert_back(pAux);
	else
	{
		std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
	}
	settings.antialiasingLevel = 16;
	Entities::Entity::setWindow(window);
	window.setFramerateLimit(FPS);
	CManager.getList(lentities);
	Executar();
}

Game::~Game()
{
	for(int i = 0; i < lentities.getSize(); i++ )
	{
		if(lentities[i])
			delete lentities[i];
	}
	lentities.clear();
}

void Game::Executar()
{ 
	while (window.isOpen())
	{
		eManager.Manage();
		for (unsigned int i = 0; i < Entities::Entity::getContEntities(); i++)
		{
			lentities[i]->Move();
		}
		Entities::Entity::updateDeltaTime();
		CManager.Manage();
		window.clear();
		for (unsigned int i = 0; i < Entities::Entity::getContEntities(); i++)
		{
			lentities[i]->Draw();
		}
		window.display();
	}
}