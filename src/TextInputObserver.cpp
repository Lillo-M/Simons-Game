#include "../include/Observers/TextInputObserver.h"

Observers::TextInputObserver::TextInputObserver(States::GameOverState* pGameOver):
    pGameOver(pGameOver)
{
}

Observers::TextInputObserver::~TextInputObserver()
{

}

void Observers::TextInputObserver::notifyKeyPressed(std::string key)
{
    pGameOver->inputKey(key);
}

void Observers::TextInputObserver::notifyKeyReleased(std::string key)
{

}