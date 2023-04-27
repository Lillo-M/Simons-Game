#pragma once

#include "Player.h"
#include <SFML/Window.hpp>
#include "PlayerInputManager.h"

class EventsManager
{
private:
	sf::Keyboard kb;
	sf::RenderWindow* window;
	Player* pPlayer;
	std::map<sf::Keyboard::Key, std::string > keyMap;
	std::map<sf::Keyboard::Key, std::string >::const_iterator mapIt;
	PlayerInputManager* pPlayerIM;
public:
	EventsManager(sf::RenderWindow& wds, Player& pP);
	~EventsManager();
	void Manage();
};