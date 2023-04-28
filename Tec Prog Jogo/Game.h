#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EventsManager.h"
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#define WIDTH 1280
#define HEIGHT 720
#define FPS 60
class Game
{
public:
	Game();
	~Game();
	void Executar();

private:
	sf::ContextSettings settings;
	EventsManager eManager;
	Entities::Player player;
	sf::RenderWindow window;
};