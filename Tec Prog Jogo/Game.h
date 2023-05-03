#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EventsManager.h"
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#define WIDTH 1280
#define HEIGHT 720
#define FPS 0
//#include <Windows.h>
#include <list>
#include "Ground.h"
#include "CollisionManager.h"
class Game
{
public:
	Game();
	~Game();
	void Executar();

private:
	Managers::CollisionManager CManager;
	sf::ContextSettings settings;
	Managers::EventsManager eManager;
	std::list<Entities::Entity*> entities;
	std::list<Entities::Entity*>::iterator entIt;
	Entities::Player* player;
	sf::RenderWindow window;
};
