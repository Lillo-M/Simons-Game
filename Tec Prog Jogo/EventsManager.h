#pragma once

#include "Player.h"
#include <SFML/Window.hpp>


class EventsManager
{
private:
	sf::Keyboard kb;
	sf::RenderWindow* window;
	Player* player;
public:
	EventsManager(sf::RenderWindow& wds, Player& pP);
	~EventsManager();
	void Manage();
};