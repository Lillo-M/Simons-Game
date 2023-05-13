#pragma once

#include <SFML/Graphics.hpp>
#include "Entities/Characters/Player.h"
#include "Entities/Obstacles/Ground.h"
#include "Managers/EventsManager.h"
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#define WIDTH 1280
#define HEIGHT 720
#define FPS 0
#include <list>
#include "Math/List.h"
#include "Managers/CollisionManager.h"
#include <iostream>
#include "../include/Entities/Characters/Enemies/Warrior.h"
#include "../include/Levels/Level1.h"

class Game
{
public:
	Game();
	~Game();
	void Executar();

private:
	//Managers::CollisionManager CManager;
	sf::ContextSettings settings;
	Managers::EventsManager eManager;
	Levels::Level1 lvl1;
	//Math::EntityList Sentities;
	//Math::EntityList Dentities;
	//Entities::Characters::Player* player;
	//sf::RenderWindow window;
	Managers::GraphicManager* pGM;
};
