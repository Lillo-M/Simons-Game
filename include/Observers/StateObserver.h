#pragma once
#include "Observer.h"
#include "../States/StateMachine.h"

namespace Observers
{
    class StateObserver: public Observer
    {
    public:
        StateObserver();
        ~StateObserver();
        void notifyKeyPressed(std::string key);
        void notifyKeyReleased(std::string key);
        void notifyPlayerDeath();
    private:
        States::StateMachine* pSMachine;
    };
}