#pragma once
#include <stdlib.h>

namespace States
{
    class StateMachine;

    enum stateID
    {
        empty =     -1,
        mainMenu =   0,
        playing =    1,
        gameOver =   2
    };

    class State
    {
    private:
        StateMachine* pSMachine;
        stateID id;
    
    public:
        State(StateMachine* pSMachine = NULL, States::stateID id = empty);
        virtual ~State();
        void setStateMachine(StateMachine* pSMachine);
        void changeState(States::stateID sID);
        const States::stateID getID() const;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        //virtual void Reset() = 0;
    };
}