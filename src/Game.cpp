#include "../include/Game.h"
#include "../include/Entities/Entity.h"

Game::Game():
    pGM(Managers::GraphicManager::getInstance()),
    eManager()
{
    try{
    currentState = static_cast<States::State*>(new Levels::Level1(&eManager, static_cast<States::StateMachine*>(this)));
    }
    catch(int error){
    if(!error)
    {
        std::cout << "ERROR: Failed to Memory Allocate" << std::endl;
        exit(1);
    }
    }
    Run();
}

Game::~Game()
{
    if(currentState)
        delete currentState;
}


void Game::Run()
{
    while(pGM->isWindowOpen())
    {
        pGM->Clear();
        this->runCurrentState();
        pGM->Display();
        eManager.Manage();
    }
}