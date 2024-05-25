#include "../include/Menus/PauseMenu.h"

Menus::PauseMenu::PauseMenu(States::StateMachine *pSM, Managers::InputManager *pIM):
    Menu(),
    State(pSM, States::stateID::pauseMenu),
    pIM(pIM)
{
    font.loadFromFile(std::string(THE_WIZARD_PATH) + std::string("/Assets/arial.ttf"));
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setString("Game Paused");
    text.setPosition(sf::Vector2f(WIDTH/2 - 100,-340));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,-30), 30, "Resume"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,0), 30, "Save Game"));
    PushButton(new GraphicElements::Button(sf::Vector2f(WIDTH/2 - 90,30), 30, "Main Menu"));
    buttons[currentButton]->Selected();
    pIM->addObserver(static_cast<Observers::Observer*>(pMObserver));

}

Menus::PauseMenu::~PauseMenu()
{
    //std::cout << "PauseMenu Destructor" << std::endl;
    for(int i = 0; i < buttonCont; i++)
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
    switch (currentButton)
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
    buttons[currentButton]->UnSelected();
    currentButton = 0;
    buttons[currentButton]->Selected();
}

void Menus::PauseMenu::Draw()
{
    pGM->Draw(text);
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Draw();
    }
}

void Menus::PauseMenu::Update()
{
    pGM->CenterView(sf::Vector2f(0,0));
    isRunning = true;
    for(int i = 0; i < buttonCont; i++)
    {
        buttons[i]->Update();
    }
}

void Menus::PauseMenu::MoveUp()
{
    if(!this->getIsRunning())
        return;
    if(currentButton <= 0)
        return;
    buttons[currentButton--]->UnSelected();
    buttons[currentButton]->Selected();
}

void Menus::PauseMenu::MoveDown()
{
    if(!this->getIsRunning())
        return;
    if(currentButton >= (buttonCont - 1))
        return;
    buttons[currentButton++]->UnSelected();
    buttons[currentButton]->Selected();
}
