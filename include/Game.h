#pragma once
#include "Managers/EventsManager.h"
#define FPS 0
#include <iostream>
#include "Levels/Level1.h"
#include "States/StateMachine.h"
#include "Managers/InputManager.h"
class Game: public States::StateMachine
{
public:
	Game();
	~Game();
	void Run();

private:
	Managers::EventsManager eManager;
	Managers::GraphicManager* pGM;
};
