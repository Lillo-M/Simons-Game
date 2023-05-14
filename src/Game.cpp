#include "../include/Game.h"


Game::Game():
    pGM(Managers::GraphicManager::getInstance()),
    eManager(),
    lvl1(&eManager)
{
    settings.antialiasingLevel = 16;
    Executar();
}

Game::~Game()
{
}


void Game::Executar()
{
    while(pGM->isWindowOpen())
    {
        eManager.Manage();
        lvl1.Run();
        pGM->Clear();
        lvl1.Draw();
        pGM->Display();
    }
}