#include "../include/Managers/EventsManager.h"

using namespace Managers;

EventsManager::~EventsManager()
{
	keyMap.clear();
	pPlayer = NULL;
	pPlayer2 = NULL;
	delete pPlayerIM;
	pPlayerIM = NULL;
	pGM = NULL;
}

EventsManager::EventsManager(Entities::Characters::Player *pP, Entities::Characters::Player *pP2) : 
	pPlayer(pP),
	pPlayer2(pP2)
{
	pGM = Managers::GraphicManager::getInstance();
	pPlayerIM = new PlayerInputManager(pPlayer, pPlayer2);
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
	keyMap[sf::Keyboard::RControl] = "rCtrl";
	keyMap[sf::Keyboard::Tab] = "Tab";
	keyMap[sf::Keyboard::Escape] = "Esc";
	keyMap[sf::Keyboard::Right] = "Right";
	keyMap[sf::Keyboard::Left] = "Left";
	keyMap[sf::Keyboard::Up] = "Up";
	keyMap[sf::Keyboard::Down] = "Down";
	mapIt = keyMap.begin();
}

void EventsManager::setpPlayer(Entities::Characters::Player *pP)
{
	pPlayer = pP;
	pPlayerIM->setpPlayer(pPlayer);
}

void EventsManager::setpPlayer2(Entities::Characters::Player *pP)
{
	pPlayer2 = pP;
	pPlayerIM->setpPlayer2(pPlayer2);
}

void EventsManager::keyPressedEvent(sf::Event::KeyEvent key)
{
	for (mapIt; mapIt != keyMap.end(); mapIt++)
	{
		if (mapIt->first == key.code)
			pPlayerIM->pressedInput(mapIt->second);
	}
	mapIt = keyMap.begin();
}
void EventsManager::keyReleasedEvent(sf::Event::KeyEvent key)
{
	for (mapIt; mapIt != keyMap.end(); mapIt++)
	{
		if (mapIt->first == key.code)
			pPlayerIM->releasedInput(mapIt->second);
	}
	mapIt = keyMap.begin();
}

void EventsManager::Manage()
{
	sf::Event event;
	while (pGM->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			keyPressedEvent(event.key);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			keyReleasedEvent(event.key);
		}
		if (event.type == sf::Event::Closed)
			pGM->Close();
	}
}
