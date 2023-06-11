#include "Menus/NewGameMenu.h"

Menus::NewGameMenu::NewGameMenu(States::StateMachine* pSM, Managers::InputManager* pIM):
    Menu(),
    State(pSM, States::stateID::newGameMenu),
    pIM(pIM)
{
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,-30), 30, "Alaska"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,0), 30, "Vulcano"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,30), 30, "Quit To MainMenu"));
    buttons[currentButton]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));
}

Menus::NewGameMenu::~NewGameMenu()
{
    std::cout << "NewGameMenu Destructor" << std::endl;
    levels.clear();
    pIM->removeObserver(static_cast<Observers::Observer*>(pMObserver));
    pIM = NULL;
    for(int i = 0; i < buttonCont; i++)
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
    switch (currentButton)
    {
    case 0:
        LoadAlaska();
        break;

    case 1:
        LoadVulcano();
        break;

    case 2:
        changeState(States::stateID::mainMenu);
        break;
    default:
        break;
    }
    buttons[currentButton--]->UnSelected();
    currentButton = 0;
    buttons[currentButton]->Selected();
}

void Menus::NewGameMenu::Draw()
{
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::NewGameMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::NewGameMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButton <= 0)
        return;
    buttons[currentButton--]->UnSelected();
    buttons[currentButton]->Selected();
}

void Menus::NewGameMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButton >= (buttonCont - 1))
        return;
    buttons[currentButton++]->UnSelected();
    buttons[currentButton]->Selected();
}

void Menus::NewGameMenu::LoadVulcano()
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

void Menus::NewGameMenu::LoadAlaska()
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