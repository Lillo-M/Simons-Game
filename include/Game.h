#pragma once

#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "Managers/EventsManager.h"
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#define WIDTH 1280
#define HEIGHT 720
#define FPS 0
//#include <Windows.h>
#include <list>
#include "Math/List.h"
#include "Entities/Ground.h"
#include "Managers/CollisionManager.h"

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
	Math::List<Entities::Entity> lentities;
	Entities::Player* player;
	sf::RenderWindow window;
};
