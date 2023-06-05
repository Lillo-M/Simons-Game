#include "../include/Menus/MainMenu.h"

Menus::MainMenu::MainMenu(States::StateMachine* pSM, Managers::InputManager* pIM):
    Menu(),
    State(pSM, States::stateID::mainMenu),
    pMObserver(new Observers::MenuObserver(static_cast<Menus::Menu*>(this))),
    pIM(pIM)
{
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,-30), 30, "New Game"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,0), 30, "Load Game"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,30), 30, "LeaderBoard"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,60), 30, "Quit Game"));
    buttons[currentButtom]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));
}
Menus::MainMenu::~MainMenu()
{
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

void Menus::MainMenu::Select()
{
    if(!this->getIsRunning())
        return;
    switch (currentButtom)
    {
    case 0:
        changeState(States::stateID::newGameState);
        break;

    case 1:
        changeState(States::stateID::loadGameState);
        break;

    case 2:
        changeState(States::stateID::leaderBoard);
        break;

    case 3:
        pGM->Close();
        break;

    default:
        break;
    }
    buttons[currentButtom--]->UnSelected();
    currentButtom = 0;
    buttons[currentButtom]->Selected();
}

void Menus::MainMenu::Draw()
{
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::MainMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::MainMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom <= 0)
        return;
    buttons[currentButtom--]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::MainMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom >= (buttomCont - 1))
        return;
    buttons[currentButtom++]->UnSelected();
    buttons[currentButtom]->Selected();
}