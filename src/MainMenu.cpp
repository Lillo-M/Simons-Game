#include "../include/Menus/MainMenu.h"

Menus::MainMenu::MainMenu(States::StateMachine* pSM, Managers::InputManager* pIM):
    Menu(),
    State(pSM, States::stateID::mainMenu),
    pIM(pIM),
    twoPlayers(false)
{
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,-30), 30, "New Game"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,0), 30, "Load Game"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,30), 30, "LeaderBoard"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,60), 30, "2 Players: OFF"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,90), 30, "Quit Game"));
    buttons[currentButton]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));
}
Menus::MainMenu::~MainMenu()
{
    //std::cout << "MainMenu Destructor" << std::endl;
    pIM->removeObserver(static_cast<Observers::Observer*>(pMObserver));
    pIM = NULL;
    for(int i = 0; i < buttonCont; i++)
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
    switch (currentButton)
    {
    case 0:
        changeState(States::stateID::newGameMenu);
        buttons[currentButton--]->UnSelected();
        currentButton = 0;
        buttons[currentButton]->Selected();
        break;

    case 1:
        changeState(States::stateID::loadGameState);
            buttons[currentButton--]->UnSelected();
        currentButton = 0;
        buttons[currentButton]->Selected();
        break;

    case 2:
        changeState(States::stateID::leaderBoard);
            buttons[currentButton--]->UnSelected();
        currentButton = 0;
        buttons[currentButton]->Selected();
        break;

    case 3:
        twoPlayers = !twoPlayers;
        (twoPlayers ? buttons[3]->changeText("2 Players: ON"):buttons[3]->changeText("2 Players: OFF"));
        break;

    case 4:
        pGM->Close();
        break;

    default:
        break;
    }
}

void Menus::MainMenu::Draw()
{
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::MainMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Update();
    }
    Levels::Level::setTwoPlayers(twoPlayers);
}

void Menus::MainMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButton <= 0)
        return;
    buttons[currentButton--]->UnSelected();
    buttons[currentButton]->Selected();
}

void Menus::MainMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButton >= (buttonCont - 1))
        return;
    buttons[currentButton++]->UnSelected();
    buttons[currentButton]->Selected();
}