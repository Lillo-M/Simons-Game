#pragma once
#include "Managers/EventsManager.h"
#include <iostream>
#include "Levels/Alaska.h"
#include "Levels/Vulcano.h"
#include "States/StateMachine.h"
#include "Managers/InputManager.h"
#include "Menus/MainMenu.h"
#include "Menus/PauseMenu.h"
#include "Menus/LeaderBoard.h"
#include "States/LoadGameState.h"
#include "Menus/NewGameMenu.h"
#include "States/GameOverState.h"

class Game: public States::StateMachine
{
public:
	~Game();
	static Game* getInstance();
private:
	void Run();
	Game();
	static Game* Instance;
	Managers::EventsManager* eManager;
	Managers::GraphicManager* pGM;
	Managers::InputManager* iManager;
};
