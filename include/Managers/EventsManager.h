#pragma once

#include "../Entities/Characters/Player.h"
#include <SFML/Window.hpp>
#include "../Managers/PlayerInputManager.h"

namespace Managers
{
	class EventsManager
	{
	private:
		sf::RenderWindow* window;
		Entities::Characters::Player* pPlayer;
		std::map<sf::Keyboard::Key, std::string > keyMap;
		std::map<sf::Keyboard::Key, std::string >::const_iterator mapIt;
		PlayerInputManager* pPlayerIM;
	public:
		EventsManager(sf::RenderWindow& wds, Entities::Characters::Player* pP = NULL);
		~EventsManager();
		void Manage();
		void setpPlayer(Entities::Characters::Player* pP);
		void keyPressedEvent(sf::Event::KeyEvent key);
		void keyReleasedEvent(sf::Event::KeyEvent key);
	};
}