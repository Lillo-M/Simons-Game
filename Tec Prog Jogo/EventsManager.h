#pragma once

#include "Player.h"
#include <SFML/Window.hpp>
#include "PlayerInputManager.h"

class EventsManager
{
private:
	sf::Keyboard kb;
	sf::RenderWindow* window;
	Entities::Player* pPlayer;
	std::map<sf::Keyboard::Key, std::string > keyMap;
	std::map<sf::Keyboard::Key, std::string >::const_iterator mapIt;
	PlayerInputManager* pPlayerIM;
public:
	EventsManager(sf::RenderWindow& wds, Entities::Player& pP);
	~EventsManager();
	void Manage();
};