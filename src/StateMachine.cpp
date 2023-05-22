#include "../include/States/StateMachine.h"

States::StateMachine::StateMachine()
{
}

States::StateMachine::~StateMachine()
{ 
}

void States::StateMachine::changeCurrentState(States::stateID sId)
{
    //currentState = sId;
}


void States::StateMachine::runCurrentState()
{
    currentState->Update();
    currentState->Draw();
}

const States::stateID States::StateMachine::getCurrentStateID() {return States::stateID::playing;}

void States::StateMachine::insert_State(States::State* pS) 
{
    //lStates.insert_back(pS);
}