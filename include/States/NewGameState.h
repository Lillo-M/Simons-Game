/*#pragma once

#include "State.h"
#include "../Levels/Level.h"


namespace States
{
    class SwitchLevelState: public State
    {
    public:
        SwitchLevelState(States::StateMachine* pSMachine);
        ~SwitchLevelState();
        void Update();
        void Draw();
        void PushLevel(Levels::Level* level);
    private:
        std::list<Levels::Level*> levels;
    };
}*/