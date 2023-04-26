#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void Executar();

private:
	Player player;
	sf::RenderWindow window;
	sf::CircleShape shape;
};