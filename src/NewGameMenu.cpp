#include "Menus/NewGameMenu.h"

Menus::NewGameMenu::NewGameMenu(States::StateMachine* pSM, Managers::InputManager* pIM):
    Menu(),
    State(pSM, States::stateID::newGameMenu),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this))),
    pIM(pIM)
{
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,-30), 30, "Level 1"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,0), 30, "Level 2"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,30), 30, "Quit To MainMenu"));
    buttons[currentButtom]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));
}

Menus::NewGameMenu::~NewGameMenu()
{
    levels.clear();
    delete pMObserver;
    pIM->removeObserver(static_cast<Observers::Observer*>(pMObserver));
    pIM = NULL;
    for(int i = 0; i < buttomCont; i++)
    {
        if(buttons[i])
            delete buttons[i];
    }
    buttons.clear();
}

void Menus::NewGameMenu::PushLevel(Levels::Level* level)
{
    levels.push_back(level);
}

void Menus::NewGameMenu::Select()
{
    if(!this->getIsRunning())
        return;
    switch (currentButtom)
    {
    case 0:
        LoadLevel1();
        break;

    case 1:
        LoadLevel2();
        break;

    case 2:
        changeState(States::stateID::mainMenu);
        break;
    default:
        break;
    }
    buttons[currentButtom--]->UnSelected();
    currentButtom = 0;
    buttons[currentButtom]->Selected();
}

void Menus::NewGameMenu::Draw()
{
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::NewGameMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::NewGameMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom <= 0)
        return;
    buttons[currentButtom--]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::NewGameMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom >= (buttomCont - 1))
        return;
    buttons[currentButtom++]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::NewGameMenu::LoadLevel2()
{
    std::cout<< "NewGame Vulcano" << std::endl;
    std::list<Levels::Level*>::iterator it;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        if((*it)->getStateID() == States::stateID::vulcano)
        {
            if(!(*it)->getLevelStarted())
            {
                std::cout<< "Change State" << std::endl;
                changeState(States::stateID::vulcano);
                return;
            }
            else
                break;
        }
    }
    std::cout << "Reset Starting" << std::endl;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        (*it)->Reset();
    }
    changeState(States::stateID::vulcano);
}

void Menus::NewGameMenu::LoadLevel1()
{
    std::cout<< "NewGame Level 1" << std::endl;
    std::list<Levels::Level*>::iterator it;
    for(it = levels.begin(); it != levels.end(); it++)
    {
        if((*it)->getStateID() == States::stateID::alaska)
        {
            if(!(*it)->getLevelStarted())
            {
                std::cout<< "Change State" << std::endl;
                changeState(States::stateID::alaska);
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
    changeState(States::stateID::alaska);
    /*  */
}