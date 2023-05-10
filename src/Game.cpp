#include "../include/Game.h"

Game::Game()
{
	pGM = Managers::GraphicManager::getInstance();
	Entities::Entity* pAux;
	pAux = new Entities::Characters::Enemies::Warrior(sf::Vector2f(250.f, 200.f), sf::Vector2f(61.f, 100.f));
	if(pAux)
		Dentities.insert_back(pAux);
	else
	{
		std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
	}
	player = new Entities::Characters::Player(sf::Vector2f(500.f, 592.f), sf::Vector2f(61.f, 100.f));
	Dentities.insert_back(player);
	eManager.setpPlayer(player);
	for (int i = 0; i < 10; i++)
	{
		pAux = new Entities::Ground(sf::Vector2f(64.f + i * 128.f, 656.f), sf::Vector2f(128.f, 128.f));
		if(pAux)
			Sentities.insert_back(pAux);
		else
		{
			std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
		}
		pAux = NULL;
	}
	pAux = new Entities::Ground(sf::Vector2f(300.f, 400.f), sf::Vector2f(128.f, 128.f));
	if(pAux)
		Sentities.insert_back(pAux);
	else
	{
		std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
	}
	pAux = new Entities::Ground(sf::Vector2f(1000.f, 400.f), sf::Vector2f(128.f, 128.f));
	if(pAux)
		Sentities.insert_back(pAux);
	else
	{
		std::cout << std::endl << "ERROR: Failed To Memory Allocate" << std::endl;
	}
	settings.antialiasingLevel = 16;
	window.setFramerateLimit(FPS);
	eManager.setpPlayer(player);
	CManager.getSList(Sentities);
	CManager.getDList(Dentities);
	Executar();
}

Game::~Game()
{
	for(int i = 0; i < Dentities.getSize(); i++ )
	{
		if(Dentities[i])
			delete Dentities[i];
	}
	Dentities.clear();
	for(int i = 0; i < Sentities.getSize(); i++ )
	{
		if(Sentities[i])
			delete Sentities[i];
	}
	Sentities.clear();
}

void Game::Executar()
{ 
	sf::Font font;
	if(!font.loadFromFile("Assets/arial.ttf"))
		std::cout << "fail to load font" << std::endl;
	sf::Text fps("hello", font);
	fps.setCharacterSize(30);
	fps.setFillColor(sf::Color::Red);
	fps.setPosition(sf::Vector2f(10.f,10.f));
	fps.setStyle(sf::Text::Bold);
	if(!pGM)
	{
		std::cout << "ERROR: Fail to load GraphicManager" << std::endl;
		exit(1);
	}
	while (pGM->isWindowOpen())//window.isOpen()) usamos agr o gerenciador grafico por ponteiro (pGM)
	{
		if(!player->getAlive())
		{
			std::cout << "Morreu";
		}
		fps.setString(std::to_string(static_cast<int>(1/Entities::Entity::getDt())));
		eManager.Manage();
		for (int i = 0; i < Dentities.getSize(); i++)
		{
			Dentities[i]->Move();
		}
		for (int i = 0; i < Sentities.getSize(); i++)
		{
			Sentities[i]->Move();
		}
		Entities::Entity::updateDeltaTime();
		CManager.Manage();
		//window.clear(); usamos agr o gerenciador grafico por ponteiro (pGM)
		pGM->Clear();
		for (int i = 0; i < Dentities.getSize(); i++)
		{
			Dentities[i]->Draw();
		}
		for (int i = 0; i < Sentities.getSize(); i++)
		{
			Sentities[i]->Draw();
		}
		//window.draw(fps); usamos agr o gerenciador grafico por ponteiro (pGM)
		//window.display();
		pGM->Draw(fps);
		pGM->Display();
	}
}