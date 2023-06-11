#include "../include/Menus/PauseMenu.h"

Menus::PauseMenu::PauseMenu(States::StateMachine *pSM, Managers::InputManager *pIM):
    Menu(),
    State(pSM, States::stateID::pauseMenu),
    pIM(pIM)
{
    font.loadFromFile("Assets/arial.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setString("Game Paused");
    text.setPosition(sf::Vector2f(WIDTH/2 - 100,-340));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,-30), 30, "Resume"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,0), 30, "Save Game"));
    PushButtom(new GraphicElements::Buttom(sf::Vector2f(WIDTH/2 - 90,30), 30, "Main Menu"));
    buttons[currentButtom]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));

}

Menus::PauseMenu::~PauseMenu()
{
    std::cout << "PauseMenu Destructor" << std::endl;
    for(int i = 0; i < buttomCont; i++)
    {
        if(buttons[i])
            delete buttons[i];
    }
    pIM->removeObserver(static_cast<Observers::Observer*>(pMObserver));
    pIM = NULL;
}

void Menus::PauseMenu::Select()
{
    if(!this->getIsRunning())
        return;
    switch (currentButtom)
    {
    case 0:
        changeState(previousState->getStateID());
        break;

    case 1:
        static_cast<Levels::Level*>(States::State::previousState)->SaveLevel();
        break;

    case 2:
        changeState(States::stateID::mainMenu);
        break;

    default:
        break;
    }
    buttons[currentButtom]->UnSelected();
    currentButtom = 0;
    buttons[currentButtom]->Selected();
}

void Menus::PauseMenu::Draw()
{
    pGM->Draw(text);
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::PauseMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttomCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::PauseMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom <= 0)
        return;
    buttons[currentButtom--]->UnSelected();
    buttons[currentButtom]->Selected();
}

void Menus::PauseMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButtom >= (buttomCont - 1))
        return;
    buttons[currentButtom++]->UnSelected();
    buttons[currentButtom]->Selected();
}