#include "../include/Managers/EventsManager.h"

Managers::EventsManager::~EventsManager()
{
	//std::cout << "EventsManager Destructor" << std::endl;
	pGM = NULL;
	Instance = NULL;
}

Managers::EventsManager::EventsManager():
	pGM(Managers::GraphicManager::getInstance())
{
}

void Managers::EventsManager::setpInputManager(Managers::InputManager* pIM)
{
	if(pIM)
		this->pIM = pIM;
}

void Managers::EventsManager::Manage()
{
	sf::Event event;
	while (pGM->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			pIM->pressedInput(event.key);
		}
		if (event.type == sf::Event::KeyReleased)
		{
			pIM->releasedInput(event.key);
		}
		if (event.type == sf::Event::Closed)
			pGM->Close();
	}
}

Managers::EventsManager* Managers::EventsManager::getInstance()
{
	if(!Instance)
	{
		try { Instance = new EventsManager();} catch(int error)
		{ if(!error){
			std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        	exit(1);
		}}
	}
	return Instance;
}

Managers::EventsManager* Managers::EventsManager::Instance(NULL);