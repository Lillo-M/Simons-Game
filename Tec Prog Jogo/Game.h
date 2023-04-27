#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EventsManager.h"
#include <SFML/System.hpp>
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
	EventsManager eManager;
	Player player;
	sf::RenderWindow window;
};