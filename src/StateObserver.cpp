#include "../include/Observers/StateObserver.h"

Observers::StateObserver::StateObserver()
{
}

Observers::StateObserver::~StateObserver()
{
}

void Observers::StateObserver::notifyKeyPressed(std::string key)
{
    if(key != "Esc")
        return;
    pSMachine->changeCurrentState(States::stateID::pauseMenu);
}

void Observers::StateObserver::notifyKeyReleased(std::string key)
{

}

void Observers::StateObserver::notifyPlayerDeath()
{
    pSMachine->changeCurrentState(States::stateID::gameOver);
}