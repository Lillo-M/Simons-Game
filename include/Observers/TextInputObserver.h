#pragma once
#include "Observer.h"
#include "States/GameOverState.h"

namespace Observers
{
    class TextInputObserver: public Observer
    {
    public:
        TextInputObserver(States::GameOverState* pGameOver);
        ~TextInputObserver();
        void notifyKeyPressed(std::string key);
        void notifyKeyReleased(std::string key);
    private:
        States::GameOverState* pGameOver;
    };
}
