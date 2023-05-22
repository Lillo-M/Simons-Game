#pragma once
#include "State.h"
#include "../Math/List.h"
namespace States
{
    class StateMachine
    {
    protected:
        //States::stateID currentState;

        //Math::List<States::State> lStates;
        States::State* currentState;
    public:
        StateMachine();
        virtual ~StateMachine();
        void changeCurrentState(States::stateID sId);
        void runCurrentState();
        static const States::stateID getCurrentStateID();
        void insert_State(States::State* pS);
    };
}