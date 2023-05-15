#pragma once

#include "../Entities/Characters/Player.h"
#include <SFML/Window.hpp>
#include "../Managers/PlayerInputManager.h"

namespace Managers
{
	class EventsManager
	{
	private:
		Managers::GraphicManager* pGM;
		Entities::Characters::Player* pPlayer;
		Entities::Characters::Player* pPlayer2;
		std::map<sf::Keyboard::Key, std::string > keyMap;
		std::map<sf::Keyboard::Key, std::string >::const_iterator mapIt;
		PlayerInputManager* pPlayerIM;
	public:
		EventsManager(Entities::Characters::Player* pP = NULL, Entities::Characters::Player* pP2 = NULL);
		~EventsManager();
		void Manage();
		void setpPlayer(Entities::Characters::Player* pP);
		void setpPlayer2(Entities::Characters::Player* pP);
		void keyPressedEvent(sf::Event::KeyEvent key);
		void keyReleasedEvent(sf::Event::KeyEvent key);
	};
}