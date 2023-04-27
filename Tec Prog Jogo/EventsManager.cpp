#include "EventsManager.h"
#define VVV 10
#include <iostream>
EventsManager::~EventsManager()
{
	keyMap.clear();
	window = NULL;
	pPlayer = NULL;
	delete pPlayerIM;
	pPlayerIM = NULL;
}

EventsManager::EventsManager(sf::RenderWindow& wds, Player& pP):
	kb(),
	window(&wds),
	pPlayer(&pP)
{
	pPlayerIM = new PlayerInputManager(pPlayer);
	keyMap.clear();
	keyMap[sf::Keyboard::A] = 'A';
	keyMap[sf::Keyboard::B] = 'B';
	keyMap[sf::Keyboard::C] = 'C';
	keyMap[sf::Keyboard::D] = 'D';
	keyMap[sf::Keyboard::E] = 'E';
	keyMap[sf::Keyboard::F] = 'F';
	keyMap[sf::Keyboard::G] = 'G';
	keyMap[sf::Keyboard::H] = 'H';
	keyMap[sf::Keyboard::I] = 'I';
	keyMap[sf::Keyboard::J] = 'J';
	keyMap[sf::Keyboard::K] = 'K';
	keyMap[sf::Keyboard::L] = 'L';
	keyMap[sf::Keyboard::M] = 'M';
	keyMap[sf::Keyboard::N] = 'N';
	keyMap[sf::Keyboard::O] = 'O';
	keyMap[sf::Keyboard::P] = 'P';
	keyMap[sf::Keyboard::Q] = 'Q';
	keyMap[sf::Keyboard::R] = 'R';
	keyMap[sf::Keyboard::S] = 'S';
	keyMap[sf::Keyboard::T] = 'T';
	keyMap[sf::Keyboard::U] = 'U';
	keyMap[sf::Keyboard::V] = 'V';
	keyMap[sf::Keyboard::W] = 'W';
	keyMap[sf::Keyboard::X] = 'X';
	keyMap[sf::Keyboard::Y] = 'Y';
	keyMap[sf::Keyboard::Z] = 'Z';
	keyMap[sf::Keyboard::LShift] = "LShift";
	keyMap[sf::Keyboard::Space] = "Space";
	keyMap[sf::Keyboard::LControl] = "lCtrl";
	keyMap[sf::Keyboard::Tab] = "Tab";
	keyMap[sf::Keyboard::Escape] = "Esc";
	keyMap[sf::Keyboard::Right] = "Right";
	keyMap[sf::Keyboard::Left] = "Left";
	keyMap[sf::Keyboard::Up] = "Up";
	keyMap[sf::Keyboard::Down] = "Down";
	mapIt = keyMap.begin();
}

void EventsManager::Manage()
{
	sf::Event evente;
	//window->waitEvent(evente);
	while (window->pollEvent(evente))
	{
		if (evente.type == sf::Event::KeyPressed)
		{
			for (mapIt; mapIt != keyMap.end(); mapIt++)
			{
				if (mapIt->first == evente.key.code)
					pPlayerIM->pressedInput(mapIt->second);
			}
			mapIt = keyMap.begin();
		}
		if (evente.type == sf::Event::KeyReleased)
		{
			for (mapIt; mapIt != keyMap.end(); mapIt++)
			{
				if (mapIt->first == evente.key.code)
					pPlayerIM->releasedInput(mapIt->second);
			}
			mapIt = keyMap.begin();
		}
		if (evente.type == sf::Event::Closed)
			window->close();
	}
}


