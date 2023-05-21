#include "../include/Game.h"
#include "../include/Entities/Entity.h"

Game::Game():
    pGM(Managers::GraphicManager::getInstance()),
    eManager()
{
    currentState = static_cast<States::State*>(new Levels::Level1(&eManager, static_cast<States::StateMachine*>(this)));
    if(!currentState)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }
    Executar();
}

Game::~Game()
{
    if(currentState)
        delete currentState;
}


void Game::Executar()
{
    while(pGM->isWindowOpen())
    {
        pGM->Clear();
        this->runCurrentState();
        pGM->Display();
        eManager.Manage();
    }
}