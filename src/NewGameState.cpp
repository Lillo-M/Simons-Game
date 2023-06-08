/*#include "../include/States/NewGameState.h"



States::SwitchLevelState::SwitchLevelState(States::StateMachine* pSMachine):
    State(pSMachine, States::stateID::newGameMenu)
{
}

States::SwitchLevelState::~SwitchLevelState()
{
    levels.clear();
}

void States::SwitchLevelState::Update()
{
    std::cout<< "NewGame" << std::endl;
    std::list<Levels::Level*>::iterator it;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        if((*it)->getStateID() == stateID::level1)
        {
            if(!(*it)->getLevelStarted())
            {
                std::cout<< "Change State" << std::endl;
                changeState(stateID::level1);
                return;
            }
            else
                break;
        }
    }
    std::cout<< "Reset Starting" << std::endl;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        (*it)->Reset();
    }
    changeState(stateID::level1);
    /*  
}

void States::SwitchLevelState::Draw()
{
}

void States::SwitchLevelState::PushLevel(Levels::Level* level)
{
    levels.push_back(level);
} */