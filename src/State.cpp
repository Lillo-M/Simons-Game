#include "../include/States/State.h"

States::State::State(StateMachine* pSMachine, States::stateID id):
    pSMachine(pSMachine),
    id(id)
{
}

States::State::~State()
{
    pSMachine = NULL;
}

void States::State::setStateMachine(StateMachine* pSMachine)
{
    this->pSMachine = pSMachine;
}

void States::State::changeState(States::stateID sID)
{
}

const States::stateID States::State::getID() const {return id;}