#include "../include/States/LoadGameState.h"



States::LoadGameState::LoadGameState(States::StateMachine* pSMachine):
    State(pSMachine, States::stateID::loadGameState)
{
}

States::LoadGameState::~LoadGameState()
{
}

void States::LoadGameState::Update()
{
    std::ifstream savefile("Assets/savefile.txt", std::ifstream::binary);
    int read;
    savefile >> read;
    
    if(savefile.eof())
    {
        std::cout << "ERROR: No Savefile Founded" << std::endl;
        changeState(States::stateID::mainMenu);
        return;
    }

    std::list<Levels::Level*>::iterator it = levels.begin();
    while(it != levels.end())
    {
        if((*it)->getID() == read)
        {
            break;
        }
        it++;
    }

    savefile.close();
    (*it)->LoadLevel();
    changeState((*it)->getStateID());
    /*  */
}

void States::LoadGameState::Draw()
{
}

void States::LoadGameState::PushLevel(Levels::Level* level)
{
    levels.push_back(level);
}