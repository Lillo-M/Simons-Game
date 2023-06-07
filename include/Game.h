#pragma once
#define FPS 0
#include "Managers/EventsManager.h"
#include <iostream>
#include "Levels/Level1.h"
#include "Levels/Level2.h"
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
	Game();
	~Game();
	void Run();

private:
	Managers::EventsManager* eManager;
	Managers::GraphicManager* pGM;
	Managers::InputManager* iManager;
};
